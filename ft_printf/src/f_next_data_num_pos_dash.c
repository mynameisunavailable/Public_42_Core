/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_num_pos_dash.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:06:27 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_num_pos_dash.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 09:33:37 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_num_pos_dash(char *tmp, size_t char_str_len,
		t_ft_print_info *info)
{
	char	*res;
	char	*char_str;

	char_str = create_strwc(' ', char_str_len);
	res = ft_memjoin2(tmp, ft_strlen(tmp), char_str, char_str_len);
	free(char_str);
	if (ft_cins('+', info->d_flag))
		res = ft_memappend_front("+", 1, res, ft_strlen(res));
	else if (ft_cins(' ', info->d_flag))
		res = ft_memappend_front(" ", 1, res, ft_strlen(res));
	return (res);
}
