/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yviavant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:24:55 by yviavant          #+#    #+#             */
/*   Updated: 2020/01/15 15:41:51 by yviavant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(size_t n, int base)
{
	size_t	i;

	i = 0;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(size_t n, int base)
{
	char	*str;
	int		len;
	size_t	digit;
	
	len = ft_len(n, base);
	if (!(str = (char *)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	str[len--] = '\0';
	while (n)
	{
		digit = n % base;
		n /= base;
		str[len--] = (digit < 0xA) ? ('0' + digit) : ('a' + digit - 0xA);
	}
	return (str);
}
