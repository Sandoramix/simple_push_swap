/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:04:34 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 18:48:28 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// BASIC STUFF

t_list	*lst_new(int val)
{
	t_list	*res;

	res = ft_calloc(1, sizeof(t_list));
	if (!res)
		return (NULL);
	res->val = val;
	res->next = NULL;
	return (res);
}

t_list	*lst_gettail(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*lst_addnode_back(t_list **head, t_list *node)
{
	t_list	*tail;

	if (!head)
		return (NULL);
	tail = lst_gettail(*head);
	if (!tail)
		*head = node;
	else
		tail->next = node;
	return (*head);
}

t_list	*lst_addback(t_list **head, int val)
{
	t_list	*node;

	if (!head)
		return (NULL);
	node = lst_new(val);
	if (!node)
		return (NULL);
	return (lst_addnode_back(head, node));
}

int	lst_size(t_list *lst)
{
	int	size;

	size = 0;
	while (lst && ++size)
		lst = lst->next;
	return (size);
}

int	lst_avg(t_list *lst)
{
	int	sum;
	int	size;

	sum = 0;
	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		sum += lst->val;
		size++;
		lst = lst->next;
	}
	return (sum / size);
}

int *lst_to_array(t_list *lst)
{
	const int	size = lst_size(lst);
	int			*arr;
	int			i;

	arr = ft_calloc(size, sizeof(int));
	if (!arr)
		return (NULL);
	i = -1;
	while (lst)
	{
		arr[++i] = lst->val;
		lst = lst->next;
	}
	return (arr);
}

/**
 * This function is slower than allocating an array and sorting it,
 * but you don't have to check for malloc failure and freeing the array.
 */
int	lst_middle_val_slow(t_list *lst, int curr_value, int remaining_iterations)
{
	t_list	*curr;
	t_list	*next_bigger;

	curr = lst_findval(lst, curr_value);
	next_bigger = ps_findnext_bigger(curr, lst);
	if (!next_bigger)
		return (curr_value);
	remaining_iterations--;
	if (remaining_iterations == 0)
		return (next_bigger->val);
	return (lst_middle_val_slow(lst, next_bigger->val, remaining_iterations));
}

int	lst_middle_val(t_list *lst)
{
	const int	size = lst_size(lst);
	int			res;
	// int			*arr;

	// arr = lst_to_array(lst);
	// if (!arr)
	// 	return (lst_avg(lst));
	// arr = sort_int_array(arr, size);
	// res = arr[size / 2];
	// printf("arr[size / 2] = %d\n", res);
	// return (free(arr), res);
	res = lst_middle_val_slow(lst, lst_getmin(lst)->val, size / 2);
	return (res);
}

// USEFUL FOR PUSH_SWAP

void	lst_print(t_list *lst)
{
	int	i;

	i = -1;
	while (lst)
	{
		//TODO replace "printf"
		printf("[%d]\t[%d]\n", ++i, lst->val);
		lst = lst->next;
	}
}

t_list	*lst_findval(t_list *lst, int val)
{
	while (lst)
	{
		if (lst->val == val)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list	*lst_getmin(t_list *lst)
{
	t_list	*min;

	min = lst;
	while (lst)
	{
		if (lst->val < min->val)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

bool	lst_issorted(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->val > lst->next->val)
			return (false);
		lst = lst->next;
	}
	return (true);
}
