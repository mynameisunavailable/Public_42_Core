/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_next_data_hex_prec_padc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*f_next_data_hex_prec_padc(char *tmp, t_ft_print_info *info)
{
	char	*char_str;
	size_t	char_str_len;

	char_str_len = info->d_prec - ft_strlen(tmp);
	char_str = create_strwc('0', char_str_len);
	info->o_str = ft_memjoin2(char_str, char_str_len, tmp, ft_strlen(tmp));
	free(char_str);
	free(tmp);
	tmp = info->o_str;
	return (tmp);
}
