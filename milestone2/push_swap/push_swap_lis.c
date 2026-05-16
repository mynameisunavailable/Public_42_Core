/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 07:33:57 by yunguo            #+#    #+#             */
/*   Updated: 2026/01/01 10:35:28 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_solver_mark_lis(int *stack, int argc, t_ps_dlist *heada)
{
	int			*res;
	size_t		res_c;
	size_t		i;
	t_ps_dlist	*curr;

	curr = heada;
	res = ft_calloc(argc, sizeof(int));
	if (!res)
		return (-1);
	res_c = iarr_lis_cir_unique(stack, argc, res, NULL);
	i = 0;
	while (i < res_c)
	{
		if (curr->cont == res[i])
		{
			curr->lis = TRUE;
			i++;
		}
		curr = curr->next;
		if (curr == heada)
			break ;
	}
	free(res);
	return (0);
}

int	ps_has_non_lis(t_ps_dlist *heada)
{
	t_ps_dlist	*top;

	top = heada;
	while (TRUE)
	{
		if (heada->lis == FALSE)
			return (1);
		heada = heada->next;
		if (heada == top)
			break ;
	}
	return (0);
}
