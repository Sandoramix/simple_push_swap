/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_brain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:07:58 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 19:14:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_min_as_target(t_list *curr, t_list *other_stack)
{
	const t_list	*min = lst_getmin(other_stack);
	int				i;
	t_list			*os;

	if (!curr || !min)
		return ;
	i = 0;
	os = other_stack;
	while (os->val != min->val)
	{
		os = os->next;
		i++;
	}
	curr->target.next_bigger = os;
	curr->target.next_idx = i;
}

void	update_next_move(t_list *a, t_list *b)
{
	const int	asize = lst_size(a);
	const int	bsize = lst_size(b);
	int			i;

	i = -1;
	while (++i < bsize)
	{
		b->target.rot = i;
		b->target.revrot = bsize - i - 1;
		if (ps_findnext_bigger(b, a) == -1)
			set_min_as_target(b, a);
		b->target.next_rot = b->target.next_idx;
		b->target.next_revrot = asize - b->target.next_idx - 1;
		b->target.totmoves = b->target.next_revrot;
		if (b->target.next_rot < b->target.next_revrot)
			b->target.totmoves = b->target.next_rot;
		if (b->target.rot < b->target.revrot)
			b->target.totmoves += b->target.rot;
		else
			b->target.totmoves += b->target.revrot;
		b = b->next;
	}
}
// NOT WORKING YET
void	combine_move(t_list **a, t_list **b, t_list *best)
{
	size_t	common_rot;
	size_t	common_revrot;

	common_rot = (int [2]){best->target.rot, best->target.next_rot}
	[best->target.next_rot > best->target.rot];
	common_revrot = (int [2]){best->target.revrot, best->target.next_revrot}
	[best->target.next_revrot > best->target.revrot];
	if (common_rot == 0 && common_revrot == 0)
		return ;
	if (common_rot > common_revrot)
	{
		best->target.rot -= common_rot;
		best->target.next_rot -= common_rot;
		while (common_rot-- > 0)
			ps_rotall(a, b, RR);
	}
	else if (common_revrot > common_rot)
	{
		best->target.revrot -= common_revrot;
		best->target.next_revrot -= common_revrot;
		while (common_revrot-- > 0)
			ps_revrotall(a, b, RRR);
	}
}

void	execute_fastest(t_list **a, t_list **b)
{
	t_list	*best;

	best = best_target(*b);
	//combine_move(a, b, best);
	if (best->target.rot < best->target.revrot)
		while (best->target.rot-- > 0)
			ps_rot(b, RB);
	else
		while (best->target.revrot-- > 0)
			ps_revrot(b, RRB);
	if (best->target.next_rot < best->target.next_revrot)
		while (best->target.next_rot-- > 0)
			ps_rot(a, RA);
	else
		while (best->target.next_revrot-- > 0)
			ps_revrot(a, RRA);
	ps_push(b, a, PA);
}
