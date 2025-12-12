/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:30:53 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/25 18:30:53 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/25 13:42:23 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data(t_ft_print_info *info, union u_ft_printf_subdata *data)
{
	char	*res;

	if (info->d_conv == 'c')
		res = f_next_data_char(info, data);
	else if (info->d_conv == 's')
		res = f_next_data_str(info, data);
	else if (info->d_conv == 'p')
		res = f_next_data_ptr(info, data);
	else if (info->d_conv == 'd' || info->d_conv == 'i')
		res = f_next_data_int(info, data);
	else if (info->d_conv == 'x')
		res = f_next_data_hex(info, data);
	else if (info->d_conv == 'X')
		res = f_next_data_hex_upper(info, data);
	else if (info->d_conv == 'u')
		res = f_next_data_uint(info, data);
	else if (info->d_conv == '%' || info->d_conv == '\0')
		res = f_next_data_pct(info);
	else
		res = NULL;
	return (res);
}
