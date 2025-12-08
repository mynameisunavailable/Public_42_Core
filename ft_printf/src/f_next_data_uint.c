/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_uint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_uint(t_ft_print_info *info,
		union u_ft_printf_subdata *data)
{
	char	*tmp;

	tmp = f_next_data_uint_prec(data->u, info);
	info->o_str = f_next_data_uint_pad(data->u, tmp, info);
	free(tmp);
	return (info->o_str);
}
