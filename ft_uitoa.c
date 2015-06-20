/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 07:58:46 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/28 20:30:47 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void		numtostr(char **strptr, unsigned long long int n, long long int size)
{
	char		*str;

	str = *strptr;
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	str[size] = '\0';
	while (n > 0)
	{
		str[size - 1] = '0' + (char)(n % 10);
		n = n / 10;
		size--;
	}
}

char			*ft_uitoa(uintmax_t n)
{
	char		*str;
	uintmax_t	size;
	uintmax_t	temp;

	size = 0;
	temp = n;
	while (temp > 0)
	{
		temp = temp / 10;
		size++;
	}
	if (n == 0)
		size = 1;
	str = (char*)malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	numtostr(&str, n, size);
	return (str);
}
