/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:58:02 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 09:11:49 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_int(t_ft_print_info *info, union u_ft_printf_subdata *data)
{
	long long	n;
	char		*tmp;
	char		sign;

	n = (long long)data->d;
	sign = ft_num_char_long(n);
	if (n < 0)
		n = -n;
	tmp = f_next_data_int_prec(n, info);
	if (sign == '-')
	{
		info->o_str = f_next_data_num_neg(tmp, info);
	}
	else
	{
		info->o_str = f_next_data_num_pos(tmp, info);
	}
	free(tmp);
	return (info->o_str);
}
