/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:23:32 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 19:00:02 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
