/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_num_pos_space.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:06:15 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_num_pos_space.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_num_pos_space(char *tmp, size_t char_str_len,
		t_ft_print_info *info)
{
	char	*res;
	char	*tmp2;
	char	*char_str;

	tmp2 = ft_strdup(tmp);
	if (ft_cins('+', info->d_flag))
	{
		tmp2 = ft_memappend_front("+", 1, tmp2, ft_strlen(tmp2));
		char_str_len--;
	}
	else if (ft_cins(' ', info->d_flag))
	{
		tmp2 = ft_memappend_front(" ", 1, tmp2, ft_strlen(tmp2));
		char_str_len--;
	}
	char_str = create_strwc(' ', char_str_len);
	res = ft_memjoin2(char_str, char_str_len, tmp2, ft_strlen(tmp) + 1);
	free(tmp2);
	free(char_str);
	return (res);
}
