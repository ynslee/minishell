/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:36:28 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/22 09:42:55 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static long int	ft_intlen(long long nb)
{
	long	len;

	len = 0;
	if (nb == 0)
		len = 1;
	else
	{
		while (nb != 0)
		{
			nb = nb / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_lltoa(long long n)
{
	long long	len;
	char		*str;
	long long	nb;

	nb = (long long)n;
	if (nb == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = ft_intlen(nb);
	if (nb < 0)
	{
		nb = -1 * nb;
		len += 1;
	}
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (!str)
		malloc_error();
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
