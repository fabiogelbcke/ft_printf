/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschuber <fschuber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 13:34:48 by fschuber          #+#    #+#             */
/*   Updated: 2014/11/21 03:48:53 by fschuber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_bzero(void *s, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = s;
	while (i < (int)n)
	{
		str[i] = 0;
		i++;
	}
}