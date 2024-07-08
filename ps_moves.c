/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:54:45 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 17:58:35 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ps_swap(t_list **stack, char *move)
{
	int	tmp;

	if (move)
		write(1, move, str_len(move));
	if (!stack || lst_size(*stack) < 2)
		return (false);
	tmp = (*stack)->val;
	(*stack)->val = (*stack)->next->val;
	(*stack)->next->val = tmp;
	return (true);
}

bool	ps_rot(t_list **stack, char *move)
{
	t_list	*last;
	t_list	*head;

	if (move)
		write(1, move, str_len(move));
	if (!stack || lst_size(*stack) < 2)
		return (false);
	head = *stack;
	*stack = (*stack)->next;
	last = lst_gettail(*stack);
	head->next = NULL;
	last->next = head;
	return (true);
}

bool	ps_revrot(t_list **stack, char *move)
{
	t_list	*prelast;
	t_list	*last;
	t_list	*head;

	if (move)
		write(1, move, str_len(move));
	if (!stack || lst_size(*stack) < 2)
		return (false);
	head = *stack;
	prelast = *stack;
	while (prelast && prelast->next && prelast->next->next)
		prelast = prelast->next;
	last = lst_gettail(*stack);
	prelast->next = NULL;
	*stack = last;
	last->next = head;
	return (true);
}

bool	ps_push(t_list **from, t_list **to, char *move)
{
	t_list	*node;

	if (move)
		write(1, move, str_len(move));
	if (!from || lst_size(*from) == 0)
		return (false);
	node = *from;
	*from = (*from)->next;
	node->next = NULL;
	lst_addnode_back(to, node);
	return (true);
}
