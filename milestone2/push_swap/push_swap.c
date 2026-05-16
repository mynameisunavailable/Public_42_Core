/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 07:33:57 by yunguo            #+#    #+#             */
/*   Updated: 2026/01/01 10:37:50 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	shift_atob(t_ps_dlist *a, t_ps_dlist **heada, t_ps_dlist **headb)
// {
// 	int			stepa;
// 	int			stepb;
// 	int			method;

// 	if (!a || !heada || !*heada)
// 		return ;
// 	if (!headb || !*headb)
// 	{
// 		pb(heada, headb);
// 		return ;
// 	}
// 	stepa = 0;
// 	stepb = 0;
// 	method = shift_atob_steps(a, a->targetb, &stepa, &stepb);
// 	if (method == 0)
// 		shift_atob_upup(heada, headb, stepa, stepb);
// 	else if (method == 1)
// 		shift_atob_dndn(heada, headb, stepa, stepb);
// 	else if (method == 2)
// 		shift_atob_updn(heada, headb, stepa, stepb);
// 	else if (method == 3)
// 		shift_atob_dnup(heada, headb, stepa, stepb);
// }

void	shift_btoa(t_ps_dlist *a, t_ps_dlist **heada, t_ps_dlist **headb)
{
	int			stepa;
	int			stepb;
	int			method;

	if (!a || !heada || !*heada || !headb || !*headb)
		return ;
	stepa = 0;
	stepb = 0;
	method = shift_atob_steps(a, a->targetb, &stepa, &stepb);
	if (method == 0)
		shift_atob_upup(heada, headb, stepb, stepa);
	else if (method == 1)
		shift_atob_dndn(heada, headb, stepb, stepa);
	else if (method == 2)
		shift_atob_dnup(heada, headb, stepb, stepa);
	else if (method == 3)
		shift_atob_updn(heada, headb, stepb, stepa);
}

// void	print_cdlist(char c, t_ps_dlist *head)
// {
// 	t_ps_dlist	*top;

// 	ft_putstr("list ");
// 	ft_putchar(c);
// 	ft_putstr(": \n");
// 	if (!head)
// 	{
// 		ft_putstr("list empty\n");
// 		return ;
// 	}
// 	top = head;
// 	while (TRUE)
// 	{
// 		ft_putnbr(head->cont);
// 		ft_putstr(", ");
// 		if (head->lis == TRUE)
// 			ft_putstr("TRUE");
// 		else
// 			ft_putstr("FALSE");
// 		ft_putchar('\n');
// 		head = head->next;
// 		if (top == head)
// 			break ;
// 	}
// }

void	sort_3_increase_a(t_ps_dlist **heada)
{
	if (validate_list_sorted(heada) == 1)
		return ;
	if (validate_list_inorder(heada) == 1)
	{
		sort_by_rank_a(heada);
		return ;
	}
	sa(heada);
	sort_by_rank_a(heada);
}

void	ps_solver_push_non_lis(t_ps_dlist **lista, t_ps_dlist **listb)
{
	t_ps_dlist	*heada;
	t_ps_dlist	*headb;
	t_ps_dlist	*tempa;

	heada = *lista;
	headb = *listb;
	while (heada->lis == FALSE && heada->r > 3)
	{
		pb(&heada, &headb);
		ps_dlist_update_lr(&heada);
	}
	tempa = heada;
	while (ps_has_non_lis(heada) == 1 && heada->r > 3)
	{
		if (heada->lis == FALSE)
			pb(&heada, &headb);
		else
			ra(&heada);
		ps_dlist_update_lr(&heada);
		if (heada == tempa || heada == NULL)
			break ;
	}
	sort_3_increase_a(&heada);
	*lista = heada;
	*listb = headb;
}

// void	ps_solver_push_non_lis(t_ps_dlist **lista, t_ps_dlist **listb)
// {
// 	t_ps_dlist	*heada;
// 	t_ps_dlist	*headb;
// 	t_ps_dlist	*tempa;

// 	heada = *lista;
// 	headb = *listb;
// 	while (heada->lis == FALSE && heada->r > 3)//
// 	{
// 		pb(&heada, &headb);
// 		ps_dlist_update_lr(&heada);//
// 	}
// 	tempa = heada;
// 	while (ps_has_non_lis(heada) == 1 && heada->r > 3)//
// 	{
// 		if (heada->lis == FALSE)
// 			pb(&heada, &headb);
// 		else
// 			ra(&heada);
// 		ps_dlist_update_lr(&heada);//
// 		if (heada == tempa || heada == NULL)
// 			break ;
// 	}
// 	sort_3_increase_a(&heada);//
// 	*lista = heada;
// 	*listb = headb;
// }

void	ps_solver(int *stack, int *sorted_stack, int argc)
{
	t_ps_dlist	*heada;
	t_ps_dlist	*headb;
	t_ps_dlist	*tempa;

	heada = init_list(stack, sorted_stack, argc);
	if (!heada)
		return ;
	headb = NULL;
	ps_solver_mark_lis(stack, argc, heada);
	if (validate_list_inorder(&heada) == 0)
		ps_solver_push_non_lis(&heada, &headb);
	while (headb != NULL)
	{
		update_list_listb(heada, headb);
		tempa = min_steptob(headb);
		shift_btoa(tempa, &heada, &headb);
		pa(&headb, &heada);
	}
	sort_by_rank_a(&heada);
	t_ps_dlist_clear(&heada);
}

int	main(int argc, char **argv)
{
	int	*stack;
	int	*sorted_stack;
	int	err;

	if (argc < 2)
		return (1);
	err = 0;
	argv += 1;
	argc -= 1;
	stack = NULL;
	sorted_stack = NULL;
	if (ps_arg_isvalid(argv, &argc, &stack, &sorted_stack) == 1)
		ps_solver(stack, sorted_stack, argc);
	else
	{
		ft_puterr("Error\n");
		err = 1;
	}
	free(stack);
	free(sorted_stack);
	return (err);
}

// 0 25 50 75 1 26 51 76 2 27 52 77 3 28 53 78 4 29 54 79 5 30 
// 55 80 6 31 56 81 7 32 57 82 8 33 58 83 9 34 59 84 10 35 60 85
//  11 36 61 86 12 37 62 87 13 38 63 88 14 39 64 89 15 40 65 90 
// 16 41 66 91 17 42 67 92 18 43 68 93 19 44 69 94 20 45 70 95 
// 21 46 71 96 22 47 72 97 23 48 73 98 24 49 74 99