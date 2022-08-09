/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:24:43 by drumfred          #+#    #+#             */
/*   Updated: 2021/10/25 20:24:46 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_needle;

	len_needle = ft_strlen(needle);
	if (!*needle)
		return ((char *)haystack);
	while (len)
	{
		if (!*haystack || len_needle > len)
			return (0);
		if (!ft_strncmp(haystack, needle, len_needle))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
