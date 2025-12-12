/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_ft_print_dinfo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 16:53:14 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ini_ft_print_dinfo(t_ft_print_info *info)
{
	info->d_flag = "";
	info->d_wide = -1;
	info->d_prec = -1;
	info->d_conv = '\0';
	info->o_str = "";
	info->o_len = 0;
	return (1);
}
