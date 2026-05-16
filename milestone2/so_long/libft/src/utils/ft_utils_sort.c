/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:54:47 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:20:05 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_bubble_sort_from_n(char ***arr, int arr_c, size_t n)
{
	int	count;
	int	swapped;

	count = n;
	swapped = TRUE;
	while (swapped == TRUE)
	{
		swapped = FALSE;
		count = n;
		while (count + 1 < arr_c)
		{
			if (ft_strcmp((*arr)[count], (*arr)[count + 1]) > 0)
			{
				ft_swap_str(&((*arr)[count]), &((*arr)[count + 1]));
				swapped = 1;
			}
			count++;
		}
	}
}
