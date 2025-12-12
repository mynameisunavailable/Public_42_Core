/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 15:51:55 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *f, ...)
{
	va_list			ap;
	t_ft_print_info	info;
	t_ft_print_var	var;

	ini_ft_print_cinfo(&info);
	ini_ft_print_var(&var);
	va_start(ap, f);
	while (f[var.i])
	{
		if (f[var.i] == '%')
		{
			var.temp = extract_str(f + var.i, &info, &var);
			process_conv(var.temp, &ap, &info, &var);
			free(var.temp);
		}
		else
		{
			write(1, f + var.i, 1);
			var.output_len++;
			var.i++;
		}
	}
	va_end(ap);
	return ((int)var.output_len);
}
