/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 22:01:57 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 16:37:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char tocheck)
{
	if (tocheck == ' ' || (tocheck >= 9 && tocheck <= 13)
		|| tocheck == 0)
		return (1);
	return (0);
}

static size_t	count_char(const char *s)
{
	size_t	res;
	size_t	i;

	res = 0;
	i = -1;
	while (s[++i])
		if (!ft_isspace(s[i]) && ft_isspace(s[i + 1]))
			res++;
	return (res);
}

char	*ft_substr(char *s, int start, int end)
{
	char		*res;
	int			size;

	size = end - start + 1;
	if (!s || size < 0)
		return (NULL);
	res = ft_calloc(size + 1, sizeof(char));
	if (!res)
		return (NULL);
	while (end >= start)
		res[--size] = s[end--];
	return (res);
}

char	**ft_split(char *s)
{
	char	**res;
	size_t	arr_len;
	size_t	start;
	size_t	idx;
	size_t	i;

	arr_len = count_char(s);
	res = ft_calloc((arr_len + 1), sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	idx = 0;
	start = 0;
	while (idx < arr_len)
	{
		if (ft_isspace(s[i]) && !ft_isspace(s[i + 1]))
			start = i + 1;
		if (!ft_isspace(s[i]) && ft_isspace(s[i + 1]))
			res[idx++] = ft_substr(s, start, i);
		if (idx > 0 && !res[idx - 1])
			return (mtx_free(&res));
		i++;
	}
	return (res);
}
