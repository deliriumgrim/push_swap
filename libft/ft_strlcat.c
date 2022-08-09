/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:23:15 by drumfred          #+#    #+#             */
/*   Updated: 2021/10/25 20:23:18 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	start;
	size_t	c;

	len_dst = ft_strlen(dst);
	start = len_dst;
	c = 0;
	if (dstsize < len_dst + 1)
		return (ft_strlen(src) + dstsize);
	if (dstsize > len_dst + 1)
	{
		while (src[c] && start < dstsize - 1)
		{
			dst[start] = src[c];
			start++;
			c++;
		}
		dst[start] = '\0';
	}
	return (len_dst + ft_strlen(src));
}
