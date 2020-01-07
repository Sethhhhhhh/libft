/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:24:55 by yviavant          #+#    #+#             */
/*   Updated: 2020/01/07 21:19:52 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n, int base)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

char		*ft_itoa_base(int n, int base)
{
	char	*str;
	int		len;
	int		digit;
	
	len = ft_len(n, base);
	if (!(str = (char *)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (n)
	{
		digit = n % base;
		str[len--] = digit < 0xA ? ('0' + digit) : ('A' + digit - 0xA);
		n /= base;
	}
	return (str);
}
