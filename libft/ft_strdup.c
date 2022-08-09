/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:21:45 by drumfred          #+#    #+#             */
/*   Updated: 2021/10/25 20:21:47 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	size_t	c;

	c = 0;
	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (a == NULL)
		return (NULL);
	while (s1[c])
	{
		a[c] = s1[c];
		c++;
	}
	a[c] = '\0';
	return (a);
}
