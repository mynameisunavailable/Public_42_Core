/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:44:05 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stddef.h>

// ft_utils_x.c
void	ft_swap_int(int *a, int *b);
void	ft_swap_str(char **a, char **b);

// ft_utils_pmem.c
void	ft_print_m(void *addr);
void	ft_print_hc(void *addr, unsigned int size);
void	*ft_print_memory(void *addr, unsigned int size);

// ft_utils_hexdump.c
void	ft_phd_offset(unsigned int value);
void	ft_phd_hex(void *addr, unsigned int size, unsigned int c_perline);
void	ft_phd_txt(void *addr, unsigned int size);
void	*ft_print_hexdump(void *addr, unsigned int size, unsigned int offset);

// ft_utils_sort.c
void	ft_bubble_sort_from_n(char ***arr, int arr_c, size_t n);

#endif