/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_d_wide.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 08:12:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/24 08:43:09 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*extract_d_wide(char *sstr, t_ft_print_info *info)
{
	int		i;
	char	*temp;

	i = 0;
	while (ft_isdigit(sstr[i]))
		i++;
	temp = ft_substr(sstr, 0, i);
	info->d_wide = ft_atoi(temp);
	free(temp);
	return (sstr + i);
}
