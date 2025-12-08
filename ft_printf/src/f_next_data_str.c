/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 18:06:47 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	f_next_data_str_pro(char *tmp, t_ft_print_info *info)
{
	info->o_str = ft_strdup(tmp);
	info->o_len = ft_strlen(tmp);
}

char	*f_next_data_str(t_ft_print_info *info,
		union u_ft_printf_subdata *data)
{
	char	*tmp;

	if (data->s == NULL && info->d_prec >= 0 && info->d_prec < 6)
		tmp = ft_strdup("");
	else if (data->s == NULL)
	{
		tmp = ft_strdup("(null)");
	}
	else
		tmp = ft_strdup(data->s);
	if ((info->d_prec >= 0) && (ft_strlen(tmp) > (size_t)info->d_prec))
	{
		info->o_str = ft_substr(tmp, 0, info->d_prec);
		free(tmp);
		tmp = info->o_str;
	}
	if ((info->d_wide > 0) && (ft_strlen(tmp) < (size_t)info->d_wide))
		f_next_data_padc(tmp, ' ', ft_strlen(tmp), info);
	else
		f_next_data_str_pro(tmp, info);
	free(tmp);
	return (info->o_str);
}
