/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:04:34 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/07 21:59:36 by odudniak         ###   ########.fr       */
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