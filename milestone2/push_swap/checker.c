/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 08:17:31 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/25 08:17:31 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	run_instruction(t_ps_dlist **heada, t_ps_dlist **headb, char *cmd)
{
	if (ft_strcmp(cmd, "sa\n") == 0)
		s_sa(heada);
	else if (ft_strcmp(cmd, "sb\n") == 0)
		s_sb(headb);
	else if (ft_strcmp(cmd, "ss\n") == 0)
		s_ss(heada, headb);
	else if (ft_strcmp(cmd, "pa\n") == 0)
		s_pa(headb, heada);
	else if (ft_strcmp(cmd, "pb\n") == 0)
		s_pb(heada, headb);
	else if (ft_strcmp(cmd, "ra\n") == 0)
		s_ra(heada);
	else if (ft_strcmp(cmd, "rb\n") == 0)
		s_rb(headb);
	else if (ft_strcmp(cmd, "rr\n") == 0)
		s_rr(heada, headb);
	else if (ft_strcmp(cmd, "rra\n") == 0)
		s_rra(heada);
	else if (ft_strcmp(cmd, "rrb\n") == 0)
		s_rrb(headb);
	else if (ft_strcmp(cmd, "rrr\n") == 0)
		s_rrr(heada, headb);
	else
		return (-1);
	return (0);
}

int	check_instruction_valid(int filenum, t_ps_dlist **heada, t_ps_dlist **headb)
{
	char	*instruction;

	instruction = get_next_line(filenum);
	while (instruction != NULL)
	{
		if (run_instruction(heada, headb, instruction) != 0)
		{
			ft_safefree(instruction);
			get_next_line(-69);
			return (2);
		}
		ft_safefree(instruction);
		instruction = get_next_line(filenum);
	}
	if (validate_list_sorted(heada) == 1 && *headb == NULL)
	{
		return (0);
	}
	return (1);
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

int	check_instruction(int *stack, int *sorted_stack, int argc)
{
	t_ps_dlist	*heada;
	t_ps_dlist	*headb;
	int			res;

	heada = init_list(stack, sorted_stack, argc);
	if (!heada)
		return (-1);
	headb = NULL;
	res = check_instruction_valid(STDIN_FILENO, &heada, &headb);
	if (res == 0)
		ft_putstr("OK\n");
	else if (res == 1)
		ft_putstr("KO\n");
	else if (res == 2)
		ft_puterr("Error\n");
	t_ps_dlist_clear(&heada);
	t_ps_dlist_clear(&headb);
	return (res);
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
	{
		err = check_instruction(stack, sorted_stack, argc);
	}
	else
	{
		ft_puterr("Error\n");
		err = 1;
	}
	free(stack);
	free(sorted_stack);
	return (err);
}
