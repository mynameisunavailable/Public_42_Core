/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_pushswap_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 10:36:49 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/25 10:36:49 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one element or none.
void	s_sa(t_ps_dlist **head)
{
	if (!head || !(*head) || (*head)->next == *head)
		return ;
	*head = ps_dlist_x(*head, (*head)->next);
}

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one element or none.
void	s_sb(t_ps_dlist **head)
{
	if (!head || !(*head) || (*head)->next == *head)
		return ;
	*head = ps_dlist_x(*head, (*head)->next);
}

// ss : sa and sb at the same time.
void	s_ss(t_ps_dlist **heada, t_ps_dlist **headb)
{
	if (!heada || !(*heada) || (*heada)->next == *heada)
		;
	else
		*heada = ps_dlist_x(*heada, (*heada)->next);
	if (!headb || !(*headb) || (*headb)->next == *headb)
		;
	else
		*headb = ps_dlist_x(*headb, (*headb)->next);
}

// pa (push a): Take the first element at the top of b
//  and put it at the top of a.
// Do nothing if b is empty.
void	s_pa(t_ps_dlist **headb, t_ps_dlist **heada)
{
	t_ps_dlist	*b;
	t_ps_dlist	*newb;

	if (!headb || !(*headb))
		return ;
	b = *headb;
	if (b->next == b)
		newb = NULL;
	else
		newb = (*headb)->next;
	b->next->prev = b->prev;
	b->prev->next = b->next;
	ps_dlist_insf(heada, b);
	*headb = newb;
}

// pb (push b): Take the first element at the top 
// of a and put it at the top of b.
// Do nothing if a is empty.
void	s_pb(t_ps_dlist **heada, t_ps_dlist **headb)
{
	t_ps_dlist	*a;
	t_ps_dlist	*newa;

	if (!heada || !(*heada))
		return ;
	a = *heada;
	if (a->next == a)
		newa = NULL;
	else
		newa = (*heada)->next;
	a->next->prev = a->prev;
	a->prev->next = a->next;
	ps_dlist_insf(headb, a);
	*heada = newa;
}
