/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper_atob_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 07:16:37 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/25 07:16:37 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	shift_atob_steps(t_ps_dlist *a, t_ps_dlist *b, int *stepa, int *stepb)
{
	int	method;
	int	min;

	min = ft_max(a->l, b->l);
	method = 0;
	if (min > ft_max(a->r, b->r))
	{
		min = ft_max(a->r, b->r);
		method = 1;
	}
	if (min > a->l + b->r)
	{
		min = a->l + b->r;
		method = 2;
	}
	if (min > a->r + b->l)
		method = 3;
	*stepa = a->l;
	if (method == 1 || method == 3)
		*stepa = a->r;
	*stepb = b->l;
	if (method == 1 || method == 2)
		*stepb = b->r;
	return (method);
}

void	shift_atob_upup(t_ps_dlist **heada, t_ps_dlist **headb,
		int stepa, int stepb)
{
	int	temp;

	temp = ft_min(stepa, stepb);
	stepa -= temp;
	stepb -= temp;
	while (temp > 0)
	{
		rr(heada, headb);
		temp--;
	}
	while (stepa > 0)
	{
		ra(heada);
		stepa--;
	}
	while (stepb > 0)
	{
		rb(headb);
		stepb--;
	}
}

void	shift_atob_dndn(t_ps_dlist **heada, t_ps_dlist **headb,
		int stepa, int stepb)
{
	int	temp;

	temp = ft_min(stepa, stepb);
	stepa -= temp;
	stepb -= temp;
	while (temp > 0)
	{
		rrr(heada, headb);
		temp--;
	}
	while (stepa > 0)
	{
		rra(heada);
		stepa--;
	}
	while (stepb > 0)
	{
		rrb(headb);
		stepb--;
	}
}

void	shift_atob_updn(t_ps_dlist **heada, t_ps_dlist **headb,
		int stepa, int stepb)
{
	while (stepa > 0)
	{
		ra(heada);
		stepa--;
	}
	while (stepb > 0)
	{
		rrb(headb);
		stepb--;
	}
}

void	shift_atob_dnup(t_ps_dlist **heada, t_ps_dlist **headb,
		int stepa, int stepb)
{
	while (stepa > 0)
	{
		rra(heada);
		stepa--;
	}
	while (stepb > 0)
	{
		rb(headb);
		stepb--;
	}
}
