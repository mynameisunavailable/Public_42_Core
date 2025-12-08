/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_d_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 09:31:08 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*extract_d_flag(char *sstr, t_ft_print_info *info)
{
	int	i;

	i = 0;
	while (ft_cins(sstr[i], info->c_flag) != 0)
		i++;
	info->d_flag = ft_substr(sstr, 0, i);
	return (sstr + i);
}
