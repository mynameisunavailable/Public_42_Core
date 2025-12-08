/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_padc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:01:34 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_padc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_padc(char *tmp, char c, size_t tmp_len,
		t_ft_print_info *info)
{
	char	*char_str;
	size_t	char_str_len;

	char_str_len = info->d_wide - tmp_len;
	char_str = create_strwc(c, char_str_len);
	if (ft_cins('-', info->d_flag))
		info->o_str = ft_memjoin2(tmp, tmp_len, char_str, char_str_len);
	else
		info->o_str = ft_memjoin2(char_str, char_str_len, tmp, tmp_len);
	free(char_str);
	info->o_len = info->d_wide;
	return (info->o_str);
}
