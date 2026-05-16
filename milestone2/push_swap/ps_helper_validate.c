/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper_validate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 19:47:32 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/21 19:47:32 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	new_arr_size(char **argv, int argc)
{
	int		i;
	size_t	total;

	total = 0;
	i = 0;
	while (i < argc)
	{
		total += find_split_count(argv[i], " ");
		i++;
	}
	return ((int)(total));
}

static int	expand_arg(char **argv, int *argc, char ***new_arr)
{
	int		i;
	int		j;
	char	**each;
	int		c;
	int		new_arr_c;

	new_arr_c = new_arr_size(argv, *argc);
	*new_arr = ft_calloc(new_arr_c + 1, sizeof(char *));
	if (!*new_arr || new_arr_c < 1)
		return (free(*new_arr), 0);
	i = -1;
	c = 0;
	while (++i < *argc)
	{
		j = 0;
		each = ft_split(argv[i], " ");
		if (!each)
			return (free_arr(*new_arr), 0);
		while (each[j] != NULL)
			(*new_arr)[c++] = each[j++];
		free(each);
		(*new_arr)[c] = NULL;
	}
	*argc = new_arr_c;
	return (1);
}

int	ps_arg_isvalid(char **argv, int *argc, int **stack, int **s_stack)
{
	size_t	size;
	char	**expanded_arr;

	expanded_arr = NULL;
	if (expand_arg(argv, argc, &expanded_arr) == 0)
		return (0);
	size = (size_t)(*argc);
	*stack = arr_to_iarr(expanded_arr, size);
	free_arr(expanded_arr);
	if (!*stack)
		return (0);
	*s_stack = ft_iarrdup(*stack, size);
	if (!*s_stack)
		return (0);
	ft_bbsort_iarr_from_n(s_stack, size, 0);
	if (ft_iarr_chkrep_sorted(*s_stack, size) == 1)
		return (0);
	return (1);
}

// int	validate_list_inorder_imp(t_ps_dlist *heada)
// {
// 	t_ps_dlist	*min;
// 	t_ps_dlist	*top;
// 	int			c;

// 	if (!heada)
// 		return (0);
// 	c = 0;
// 	min = heada;
// 	top = heada;
// 	while (TRUE)
// 	{
// 		if (min->rank > heada->rank)
// 			min = heada;
// 		heada = heada->next;
// 		if (heada == top)
// 			break ;
// 	}
// 	heada = min;
// 	while (TRUE)
// 	{
// 		if (heada->rank > heada->next->rank)
// 			c++;
// 		heada = heada->next;
// 		if (heada->next == min)
// 			break ;
// 	}
// 	return (c);
// }

// 1 if in order
int	validate_list_inorder(t_ps_dlist **heada)
{
	t_ps_dlist	*curr;
	t_ps_dlist	*min;

	if (!heada || !*heada)
		return (0);
	curr = *heada;
	min = curr;
	while (TRUE)
	{
		if (min->rank > curr->rank)
			min = curr;
		curr = curr->next;
		if (curr == *heada)
			break ;
	}
	curr = min;
	while (TRUE)
	{
		if (curr->rank > curr->next->rank)
			return (0);
		curr = curr->next;
		if (curr->next == min)
			break ;
	}
	return (1);
}

int	validate_list_sorted(t_ps_dlist **heada)
{
	t_ps_dlist	*curr;

	if (!heada || !*heada)
		return (0);
	curr = *heada;
	while (TRUE)
	{
		if (curr->rank > curr->next->rank)
			return (0);
		curr = curr->next;
		if (curr->next == *heada)
			break ;
	}
	return (1);
}

// int	validate_list_inorder_decrease(t_ps_dlist **headb)
// {
// 	t_ps_dlist	*curr;
// 	t_ps_dlist	*top;

// 	if (!headb || !*headb)
// 		return (0);
// 	curr = *headb;
// 	while (curr->rank != 0)
// 	{
// 		curr = curr->next;
// 		if (curr == *headb)
// 			return (0);
// 	}
// 	top = curr;
// 	while (TRUE)
// 	{
// 		if (curr->rank < curr->next->rank)
// 			return (0);
// 		curr = curr->next;
// 		if (curr->next == top)
// 			break ;
// 	}
// 	return (1);
// }

// int	validate_list_sorted_decrease(t_ps_dlist **headb)
// {
// 	t_ps_dlist	*curr;

// 	if (!headb || !*headb)
// 		return (0);
// 	curr = *headb;
// 	if (curr->rank != 0)
// 	{
// 		return (0);
// 	}
// 	while (TRUE)
// 	{
// 		if (curr->rank < curr->next->rank)
// 			return (0);
// 		curr = curr->next;
// 		if (curr->next == *headb)
// 			break ;
// 	}
// 	return (1);
// }
// void	sort_by_rank_a(t_ps_dlist **heada)
// {
// 	t_ps_dlist	*curr;

// 	curr = *heada;
// 	while (curr->rank != 0)
// 	{
// 		curr = curr->next;
// 		if (curr == *heada)
// 			return ;
// 	}
// 	if (curr->l < curr->r)
// 	{
// 		while ((*heada)->rank != 0)
// 			ra(heada);
// 	}
// 	else
// 	{
// 		while ((*heada)->rank != 0)
// 			rra(heada);
// 	}
// }
