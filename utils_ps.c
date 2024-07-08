/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:48:13 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 19:03:41 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*best_target(t_list *b)
{
	t_list		*best;

	best = b;
	while (b)
	{
		if (best->target.totmoves > b->target.totmoves)
			best = b;
		b = b->next;
	}
	return (best);
}

int	ps_findnext_bigger(t_list *curr, t_list *other_stack)
{
	const int		val = curr->val;
	t_list			*cur;
	int				res;
	int				i;

	cur = other_stack;
	other_stack = other_stack->next;
	i = 0;
	res = -1;
	if (cur->val > curr->val)
		res = i;
	while (other_stack && ++i)
	{
		if (other_stack->val > val
			&& (res == -1 || (other_stack->val < cur->val)))
		{
			cur = other_stack;
			res = i;
		}
		other_stack = other_stack->next;
	}
	curr->target.next_bigger = cur;
	curr->target.next_idx = res;
	return (res);
}
