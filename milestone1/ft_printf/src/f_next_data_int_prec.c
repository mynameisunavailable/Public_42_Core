/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_int_prec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:45:31 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_int_prec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 09:11:28 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_int_prec(long long n, t_ft_print_info *info)
{
	char	*tmp;
	char	*char_str;
	size_t	char_str_len;

	if (info->d_prec >= 0)
	{
		if ((info->d_prec == 0) && (n == 0))
			tmp = ft_strdup("");
		else
			tmp = ft_ldtoa(n);
		if (ft_strlen(tmp) < (size_t)info->d_prec)
		{
			char_str_len = info->d_prec - ft_strlen(tmp);
			char_str = create_strwc('0', char_str_len);
			info->o_str = ft_memjoin2(char_str, char_str_len, tmp,
					ft_strlen(tmp));
			free(char_str);
			info->o_len = info->d_prec;
			free(tmp);
			tmp = info->o_str;
		}
	}
	else
		tmp = ft_ldtoa(n);
	return (tmp);
}
