/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:38:55 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 16:42:46 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*populate(char **av)
{
	t_list	*res;
	int		i;
	int		n;

	res = NULL;
	i = -1;
	while (av && av[++i])
	{
		n = ft_atoi(av[i]);
		if (!is_just_a_number(av[i]) || lst_findval(res, n) != NULL
			|| !lst_addback(&res, n))
			return (lst_free(&res), write(2, "Error\n", 7), exit(1), NULL);
	}
	return (res);
}

t_list	*parse(int ac, char **av)
{
	t_list	*res;

	if (ac < 2)
		return (NULL);
	av = &av[1];
	res = populate(av);
	return (res);
}
