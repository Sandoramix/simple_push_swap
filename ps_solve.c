/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:10:39 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 18:51:46 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	solve3(t_list **a)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	if (!a || lst_issorted(*a))
		return (true);
	if (lst_size(*a) == 2)
		return (ps_swap(a, SA), true);
	n1 = *a;
	n2 = (*a)->next;
	n3 = (*a)->next->next;
	if ((n1->val > n2->val && n2->val > n3->val)
		|| (n2->val < n1->val && n1->val < n3->val)
		|| (n1->val < n3->val && n3->val < n2->val))
		ps_swap(a, SA);
	if (n2->val < n3->val && n3->val < n1->val)
		ps_rot(a, RA);
	else if (n3->val < n1->val && n1->val < n2->val)
		ps_revrot(a, RRA);
	return (true);
}


void	solve(t_list **a, t_list **b)
{
	int		a_len;

	a_len = lst_size(*a);
	while (a_len > 3 && !lst_issorted(*a))
	{
		ps_push(a, b, PB);
		a_len--;
	}
	solve3(a);
	while (*b)
	{
		update_next_move(*a, *b);
		execute_fastest(a, b);
	}
}
