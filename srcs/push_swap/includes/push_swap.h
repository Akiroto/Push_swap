/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseiller <lseiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:41:02 by lseiller          #+#    #+#             */
/*   Updated: 2022/04/12 12:36:31 by lseiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../../libft/includes/libft.h"

enum	e_operation {
	RRB,
	RB
};

typedef struct s_element
{
	char				*content;
	int					index;
	struct s_element	*next;
}	t_list;

/* ⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷ */
//list_tools.c
int			lstsize(t_list *lst);
t_list		*lstnew(char *content);
void		lstclear(t_list **lst);
void		lstadd_back(t_list **alst, t_list *new);
/* ⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷ */
//parse.c
t_list		*ft_parsing(int argc, char **argv, t_list **stack_a);
//parse_tools.c
int			ft_isstrdigit(char *str);
int			ft_isoverflow(char *nbr);
int			ft_isdoublon(char **split);
void		ft_free_split(char **split, int i);
/* ⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷ */
//index.c
void		ft_index(t_list *stack_a);
/* ⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷ */
//push.c
int			ft_pa(t_list **stack_a, t_list **stack_b);
int			ft_pb(t_list **stack_b, t_list **stack_a);
//swap.c
int			ft_sa(t_list **stack_a);
int			ft_sb(t_list **stack_b);
int			ft_ss(t_list **stack_a, t_list **stack_b);
//rotate.c
t_list		*lstlast(t_list *lst);
int			ft_ra(t_list **stack_a);
int			ft_rb(t_list **stack_b);
int			ft_rr(t_list **stack_a, t_list **stack_b);
//reverse_rotate.c
int			ft_rrb(t_list **stack_b);
int			ft_rra(t_list **stack_a);
t_list		*not_lstlast(t_list *lst);
int			ft_rrr(t_list **stack_a, t_list **stack_b);
/* ⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷⟷ */
//small_sort.c
void		ft_small_sort(t_list **stack_a);
//sort_tools.c
int			find_pos(t_list *stack, int size);
void		ft_rotate_to_index(t_list **stack, int size, int op);
int			ft_issort(t_list **stack_a, t_list **stack_b, int sort);
//big_sort.c
void		ft_big_sort(t_list **stack_a);
//sort_to_a.c
int			simple_push(t_list **stack_a, t_list **stack_b,
				int size, int operation);
int			double_push(t_list **stack_a, t_list **stack_b,
				int size, int operation);
int			double_push_switched(t_list **stack_a, t_list **stack_b,
				int size, int operation);
int			case_pos_switched(t_list **stack_a, t_list **stack_b, int size);
//pre_sort_to_b.c
void		should_swap_or_rotate(t_list **stack_a, t_list **stack_b,
				int inc_pool, int pool);

#endif
