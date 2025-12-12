/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo    <yunguo@student.42singapor>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 10:24:15 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/21 10:24:15 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:49:39 by yunguo            #+#    #+#             */
/*   Updated: 2025/11/20 14:39:36 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		negative;
	char	digit;

	negative = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		negative = -1;
	}
	if (-10 < n && n < 10)
	{
		digit = n * negative;
		digit = digit + '0';
	}
	else
	{
		digit = n % 10;
		digit = digit * negative;
		digit = digit + '0';
		ft_putnbr_fd((int)(negative * (n / 10)), fd);
	}
	write(fd, &digit, 1);
}
