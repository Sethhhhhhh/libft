/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 05:03:38 by yviavant          #+#    #+#             */
/*   Updated: 2020/01/14 16:23:03 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(long n)
{
	int		len;

	len = 1;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void		ft_write(long n, int len, char *str)
{
	int		start;

	start = 0;
	str[len] = '\0';
	len--;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		start = 1;
	}
	while (len >= start)
	{
		str[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
}

char			*ft_itoa(int n)
{
	int		count_char;
	char	*str;
	long	ln;

	ln = (long)n;
	count_char = ft_len(ln);
	if ((str = (char *)malloc(sizeof(char) * count_char + 1)) == NULL)
		return (NULL);
	ft_write(ln, count_char, str);
	return (str);
}
