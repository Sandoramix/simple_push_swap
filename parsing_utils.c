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

t_list	*populate(char **av, bool should_free)
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
		{
			if (should_free)
				mtx_free(&av);
			return (lst_free(&res), write(2, "Error\n", 7), exit(1), NULL);
		}
	}
	return (res);
}

t_list	*parse(int ac, char **av)
{
	bool	should_free;
	t_list	*res;

	should_free = false;
	if (ac < 2)
		return (NULL);
	av = &av[1];
	if (ac == 2)
	{
		should_free = true;
		av = ft_split(*av);
		if (!av || !av[0])
			return (write(2, "Error\n", 7), mtx_free(&av), exit(1), NULL);
	}
	res = populate(av, should_free);
	if (should_free)
		mtx_free(&av);
	return (res);
}
