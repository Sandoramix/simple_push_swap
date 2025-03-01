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

t_list	*ps_findnext_bigger(t_list *curr, t_list *other_stack)
{
	const int		val = curr->val;
	int				res;
	int				i;

	curr->target.next_bigger = other_stack;
	other_stack = other_stack->next;
	i = 0;
	res = -1;
	if (curr->target.next_bigger->val > curr->val)
		res = i;
	while (other_stack && ++i)
	{
		if (other_stack->val > val
			&& (res == -1 || (other_stack->val < curr->target.next_bigger->val)))
		{
			curr->target.next_bigger = other_stack;
			res = i;
			curr->target.next_idx = res;
		}
		other_stack = other_stack->next;
	}
	if (res == -1)
		curr->target.next_bigger = NULL;
	return (curr->target.next_bigger);
}
