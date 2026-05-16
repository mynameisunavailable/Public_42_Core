/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_helper_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:49:02 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/18 10:49:02 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_dlist	*ps_dlist_new(int cont)
{
	t_ps_dlist	*new;

	new = malloc(sizeof(t_ps_dlist));
	if (!new)
		return (NULL);
	new->cont = cont;
	new->lis = FALSE;
	new->targetb = NULL;
	new->next = new;
	new->prev = new;
	return (new);
}

t_ps_dlist	*ps_dlist_newfront(t_ps_dlist **head, int cont)
{
	t_ps_dlist	*new;

	new = ps_dlist_new(cont);
	if (!new)
		return (NULL);
	ps_dlist_insf(head, new);
	return (*head);
}

t_ps_dlist	*ps_dlist_newend(t_ps_dlist **head, int cont)
{
	t_ps_dlist	*new;

	new = ps_dlist_new(cont);
	if (!new)
		return (NULL);
	ps_dlist_inse(head, new);
	return (*head);
}

void	t_ps_dlist_clear(t_ps_dlist **head)
{
	t_ps_dlist	*temp;
	t_ps_dlist	*curr;
	t_ps_dlist	*last;

	if (!head || !*head)
		return ;
	curr = *head;
	last = curr->prev;
	while (curr != last)
	{
		temp = curr;
		curr = curr->next;
		ft_safefree(temp);
	}
	ft_safefree(curr);
}
