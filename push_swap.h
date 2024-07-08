/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odudniak <odudniak@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 19:07:20 by odudniak          #+#    #+#             */
/*   Updated: 2024/07/08 16:41:16 by odudniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

//MOVES-------------------------------------------------------------------------
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
// MIGHT BE USED (for combined optimization)
# define RRB "rrb\n"
# define RRR "rrr\n"
// IS USED ONLY WHEN SORTING 3 NUMBERS IN A
# define SA "sa\n"
// ARENT USED AT ALL
# define SB "sb\n"
# define SS "ss\n"
//------------------------------------------------------------------------------

typedef struct s_list
{
	int				val;
	struct s_list	*next;
}	t_list;

//BASE UTILS
void	*ft_calloc(size_t n, size_t sizeof_n);
void	*lst_free(t_list **head);
void	*mtx_free(char ***mtx_p);
int		str_len(char *s);
char	**ft_split(char *s);



// LIST UTILS
//			BASIC
int		lst_size(t_list *lst);
t_list	*lst_new(int val);
t_list	*lst_addback(t_list **head, int val);
t_list	*lst_addnode_back(t_list **head, t_list *node);
t_list	*lst_gettail(t_list *lst);
//			EXTRA
void	lst_print(t_list *lst);
t_list	*lst_findval(t_list *lst, int val);
t_list	*lst_getmin(t_list *lst);
bool	lst_issorted(t_list *lst);


// PUSH_SWAP MOVES
bool	ps_revrot(t_list **stack, char *move);
bool	ps_rot(t_list **stack, char *move);
bool	ps_swap(t_list **stack, char *move);
bool	ps_push(t_list **from, t_list **to, char *move);

// PARSING
t_list	*parse(int ac, char **av);
//			NUMBER PARSING
bool	is_just_a_number(char *s);
int		ft_atoi(char *s);

#endif