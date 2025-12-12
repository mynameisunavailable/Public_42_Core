/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_next_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:03:08 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_next_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	extract_next_data(va_list *ap, t_ft_print_info *info,
		union u_ft_printf_subdata *data)
{
	if (info->d_conv == 'c')
	{
		data->c = va_arg(*ap, int);
	}
	else if (info->d_conv == 's')
	{
		data->s = va_arg(*ap, char *);
	}
	else if (info->d_conv == 'p')
	{
		data->p = va_arg(*ap, void *);
	}
	else if (info->d_conv == 'd' || info->d_conv == 'i')
	{
		data->d = va_arg(*ap, int);
	}
	else if (info->d_conv == 'x' || info->d_conv == 'X' || info->d_conv == 'u')
	{
		data->u = va_arg(*ap, unsigned int);
	}
}
