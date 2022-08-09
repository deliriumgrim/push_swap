/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:54:10 by drumfred          #+#    #+#             */
/*   Updated: 2021/10/22 19:54:12 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*a;

	a = s;
	while (n--)
	{
		if (*a == (char)c)
			return ((char *)a);
		a++;
	}
	return (0);
}
