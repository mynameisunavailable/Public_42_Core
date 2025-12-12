/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 14:56:35 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_ptr(t_ft_print_info *info, union u_ft_printf_subdata *data)
{
	char	*tmp;

	if (data->p == NULL)
	{
		tmp = ft_strdup("(nil)");
		info->o_str = ft_strdup(tmp);
	}
	else
	{
		tmp = ft_ptoa(data->p);
		info->o_str = ft_memjoin2("0x", 2, tmp, ft_strlen(tmp));
	}
	free(tmp);
	tmp = info->o_str;
	if ((info->d_wide >= 0) && (ft_strlen(tmp) < (size_t)info->d_wide))
	{
		f_next_data_padc(tmp, ' ', ft_strlen(tmp), info);
	}
	else
	{
		info->o_str = ft_strdup(tmp);
		info->o_len = ft_strlen(tmp);
	}
	free(tmp);
	return (info->o_str);
}
