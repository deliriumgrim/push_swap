/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:21:30 by drumfred          #+#    #+#             */
/*   Updated: 2021/10/25 20:25:02 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	a;

	a = c;
	if (!c)
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == a)
			return ((char *)s);
		s++;
	}
	return (0);
}
