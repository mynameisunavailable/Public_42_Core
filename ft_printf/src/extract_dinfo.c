/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_dinfo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 11:44:11 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	extract_dinfo(char *sstr, t_ft_print_info *info)
{
	ini_ft_print_dinfo(info);
	sstr = extract_d_flag(sstr, info);
	sstr = extract_d_wide(sstr, info);
	sstr = extract_d_prec(sstr, info);
	sstr = extract_d_conv(sstr, info);
}
