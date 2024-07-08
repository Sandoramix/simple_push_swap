/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:23:32 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 16:53:15 by odudniak         ###   ########.fr       */
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
	if ((n1->val > n2->val && n1->val < n3->val)
		|| (n2->val < n1->val && n1->val < n3->val)
		|| (n1->val < n3->val && n3->val < n2->val))
		ps_swap(a, SA);
	if (n2->val < n3->val && n3->val < n1->val)
		ps_rot(a, RA);
	else if (n3->val < n1->val && n1->val < n2->val)
		ps_revrot(a, RRA);
	return (true);
}

typedef struct s_newplace
{
	t_list	*target;
	
}	t_newplace;

void	*solve(t_list **a, t_list **b)
{
	int		a_len;

	a_len = lst_size(*a);
	while (a_len > 3 && !lst_issorted(*a))
	{
		ps_push(a, b, PB);
		a_len--;
	}
	solve3(a);
	(void)a;
	(void)b;
	return (NULL);
}


int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	b = NULL;
	a = parse(ac, av);
	if (!a)
		return (0);
	solve(&a, &b);
	lst_print(a);
	lst_free(&a);
	lst_free(&b);
	return (0);
}
