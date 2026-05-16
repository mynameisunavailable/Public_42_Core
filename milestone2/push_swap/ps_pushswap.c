/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pushswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 08:03:38 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/25 08:03:38 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
void	sa(t_ps_dlist **head)
{
	s_sa(head);
	ft_putstr("sa\n");
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
void	sb(t_ps_dlist **head)
{
	s_sb(head);
	ft_putstr("sb\n");
}

// ss : sa and sb at the same time.
void	ss(t_ps_dlist **heada, t_ps_dlist **headb)
{
	s_ss(heada, headb);
	ft_putstr("ss\n");
}

// pa (push a): Take the first element at the top of b
//  and put it at the top of a.
// Do nothing if b is empty.
void	pa(t_ps_dlist **headb, t_ps_dlist **heada)
{
	s_pa(headb, heada);
	ft_putstr("pa\n");
}

// pb (push b): Take the first element at the top 
// of a and put it at the top of b.
// Do nothing if a is empty.
void	pb(t_ps_dlist **heada, t_ps_dlist **headb)
{
	s_pb(heada, headb);
	ft_putstr("pb\n");
}
