/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:23:32 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 18:47:53 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print(t_list *a)
{
	int		i;

	i = -1;
	while (a)
	{
		printf("[%d]: [%d] (next: {idx[%d]; val[%d]})\n", ++i, a->val,
			a->target.next_idx,
			a->target.next_bigger ? a->target.next_bigger->val : 0);
		a = a->next;
	}
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
	lst_free(&a);
	lst_free(&b);
	return (0);
}
