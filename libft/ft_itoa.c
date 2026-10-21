/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabukhai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 16:51:47 by jabukhai          #+#    #+#             */
/*   Updated: 2026/10/20 16:51:58 by jabukhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	num;
	long	tmp;
	int	len;
	char	*p;
	
	num = n;
	len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	tmp = num;
	while (tmp / 10 > 0)
	{
		len++;
		tmp /= 10;
	}
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (n < 0)
		p[0] = '-';
	if (num == 0)
		p[0] = '0';
	while (num > 0)
	{
		p[--len] = num % 10 + '0';
		num /= 10;
	}
	return (p);
}
