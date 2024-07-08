/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:14:23 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 16:34:00 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	int	i;
	int	res;
	int	old;
	int	sign;

	if (!s)
		return (0);
	i = 0;
	sign = 1;
	if (s[i] == '-')
		sign = -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	res = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		old = res;
		res = res * 10 + (s[i] - '0');
		if (res / 10 != old)
			return (0);
		i++;
	}
	return (res * sign);
}

bool	is_just_a_number(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (false);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (ft_atoi(s) == 0 && (s[i] != '0' || s[i + 1] != '\0'))
		return (false);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] != '\0')
		return (false);
	return (true);
}
