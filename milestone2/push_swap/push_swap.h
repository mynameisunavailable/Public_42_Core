/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 09:44:32 by yunguo            #+#    #+#             */
/*   Updated: 2026/01/01 10:38:05 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"

struct s_ps_dlist
{
	int					l;
	int					r;
	int					rank;
	int					steptob;
	int					cont;
	t_bool				lis;
	struct s_ps_dlist	*targetb;
	struct s_ps_dlist	*prev;
	struct s_ps_dlist	*next;
};

typedef struct s_ps_dlist	t_ps_dlist;

//ps_helper_atob_helper.c
int			shift_atob_steps(t_ps_dlist *a, t_ps_dlist *b,
				int *stepa, int *stepb);
void		shift_atob_upup(t_ps_dlist **heada, t_ps_dlist **headb,
				int stepa, int stepb);
void		shift_atob_dndn(t_ps_dlist **heada, t_ps_dlist **headb,
				int stepa, int stepb);
void		shift_atob_updn(t_ps_dlist **heada, t_ps_dlist **headb,
				int stepa, int stepb);
void		shift_atob_dnup(t_ps_dlist **heada, t_ps_dlist **headb,
				int stepa, int stepb);

//ps_helper_create.c
t_ps_dlist	*ps_dlist_new(int cont);
t_ps_dlist	*ps_dlist_newfront(t_ps_dlist **head, int cont);
t_ps_dlist	*ps_dlist_newend(t_ps_dlist **head, int cont);
void		t_ps_dlist_clear(t_ps_dlist **head);

//ps_helper_init.c
t_ps_dlist	*min_steptob(t_ps_dlist *head);
t_ps_dlist	*init_list_rank(t_ps_dlist *head, int *s_stack, int argc);
t_ps_dlist	*init_list(int *stack, int *s_stack, int argc);

//ps_helper_update.c
void		ps_dlist_update_lr(t_ps_dlist **head);
void		update_list_lista(t_ps_dlist *heada, t_ps_dlist *headb);
void		update_list_listb(t_ps_dlist *heada, t_ps_dlist *headb);
void		sort_by_rank_b(t_ps_dlist **headb);
void		sort_by_rank_a(t_ps_dlist **heada);

//ps_helper_update_steptob.c
void		ps_dlist_update_steptoa(t_ps_dlist **heada, t_ps_dlist **headb);

//ps_helper_update_steptob.c
void		ps_dlist_update_steptob_emptyb(t_ps_dlist **heada);
t_ps_dlist	*ft_max_rank(t_ps_dlist *max, t_ps_dlist *curr);
t_ps_dlist	*ps_dlist_find_ins_node(t_ps_dlist *a, t_ps_dlist *headb);
int			ps_dlist_find_stepto_node(t_ps_dlist *a, t_ps_dlist *b);
void		ps_dlist_update_steptob(t_ps_dlist **heada, t_ps_dlist **headb);

//ps_helper_swap.c
t_ps_dlist	*ps_dlist_x(t_ps_dlist *a, t_ps_dlist *b);
void		ps_dlist_insf(t_ps_dlist **head, t_ps_dlist *new);
void		ps_dlist_inse(t_ps_dlist **head, t_ps_dlist *new);

//ps_helper_validate.c
int			ps_arg_isvalid(char **argv, int *argc, int **stack, int **s_stack);
// int			validate_list_inorder_imp(t_ps_dlist *heada);
int			validate_list_inorder(t_ps_dlist **heada);
int			validate_list_sorted(t_ps_dlist **heada);
// int			validate_list_inorder_decrease(t_ps_dlist **headb);
// int			validate_list_sorted_decrease(t_ps_dlist **headb);

//ps_pushswap_helper.c
void		s_sa(t_ps_dlist **head);
void		s_sb(t_ps_dlist **head);
void		s_ss(t_ps_dlist **heada, t_ps_dlist **headb);
//Take the first element at the top of b and put it at the top of a.
void		s_pa(t_ps_dlist **headb, t_ps_dlist **heada);
//Take the first element at the top of a and put it at the top of b.
void		s_pb(t_ps_dlist **heada, t_ps_dlist **headb);

//ps_rotate_helper.c
void		s_ra(t_ps_dlist **head);
void		s_rb(t_ps_dlist **head);
void		s_rr(t_ps_dlist **heada, t_ps_dlist **headb);

//ps_rrotate_helper.c
void		s_rra(t_ps_dlist **head);
void		s_rrb(t_ps_dlist **head);
void		s_rrr(t_ps_dlist **heada, t_ps_dlist **headb);

//push_swap_lis.c
int			ps_solver_mark_lis(int *stack, int argc, t_ps_dlist *heada);
int			ps_has_non_lis(t_ps_dlist *heada);

//ps_pushswap.c
void		sa(t_ps_dlist **head);
void		sb(t_ps_dlist **head);
void		ss(t_ps_dlist **heada, t_ps_dlist **headb);
//Take the first element at the top of b and put it at the top of a.
void		pa(t_ps_dlist **headb, t_ps_dlist **heada);
//Take the first element at the top of a and put it at the top of b.
void		pb(t_ps_dlist **heada, t_ps_dlist **headb);

//ps_rotate.c
void		ra(t_ps_dlist **head);
void		rb(t_ps_dlist **head);
void		rr(t_ps_dlist **heada, t_ps_dlist **headb);

//ps_rrotate.c
void		rra(t_ps_dlist **head);
void		rrb(t_ps_dlist **head);
void		rrr(t_ps_dlist **heada, t_ps_dlist **headb);

#endif