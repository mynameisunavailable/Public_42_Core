/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/25 19:04:30 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*extract_str(const char *f, t_ft_print_info *info, t_ft_print_var *var)
{
	var->tlen = 1;
	while (ft_cins(f[var->tlen], info->c_conv) == 0 && (f[var->tlen] != '\0'))
	{
		var->tlen++;
	}
	var->temp = ft_substr(f, 1, var->tlen);
	if (ft_cins(var->temp[var->tlen - 1], info->c_conv) == 0)
	{
		var->i++;
		free(var->temp);
		var->temp = ft_strdup("");
	}
	else
		var->i += var->tlen + 1;
	return (var->temp);
}
