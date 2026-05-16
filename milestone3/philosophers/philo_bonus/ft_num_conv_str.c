/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_conv_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:36:01 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/19 21:41:56 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	digit;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}
	return (sign * result);
}

void	ft_reverse_string(char *string, char *reverse_string, int length)
{
	int	index;

	index = 0;
	while (length > 0)
	{
		reverse_string[index] = string[length - 1];
		length--;
		index++;
	}
	reverse_string[index] = '\0';
}

char	*ft_itoa_fast(int n, char *dest)
{
	int			i;
	long long	num;
	char		string[12];
	int			negative;

	negative = (n < 0);
	i = 0;
	num = (long long)n;
	if (num < 0)
		num = -num;
	else if (num == 0)
		string[i++] = '0';
	while (num > 0)
	{
		string[i++] = '0' + (num % 10);
		num = num / 10;
	}
	if (negative)
		string[i++] = '-';
	string[i] = '\0';
	ft_reverse_string(string, dest, i);
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}
