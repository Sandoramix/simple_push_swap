/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:08:30 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/07 22:07:50 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t n, size_t sizeof_n)
{
	const size_t	final_size = n * sizeof_n;
	void			*res;
	char			*p;
	size_t			i;

	res = malloc(final_size);
	if (!res)
		return (NULL);
	i = -1;
	p = (char *)res;
	while (++i < final_size)
		p[i] = 0;
	return (res);
}

void	*lst_free(t_list **head)
{
	t_list	*node;
	t_list	*next;

	if (!head)
		return (NULL);
	node = *head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	*head = NULL;
	return (NULL);
}

void	*mtx_free(char ***mtx_p)
{
	int		i;
	char	**mtx;

	if (!mtx_p)
		return (NULL);
	mtx = *mtx_p;
	i = -1;
	while (mtx && mtx[++i])
		free(mtx[i]);
	free(mtx);
	mtx_p = NULL;
	return (NULL);
}

int	str_len(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	*sort_int_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return (arr);
}
