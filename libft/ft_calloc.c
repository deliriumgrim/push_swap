/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 19:41:46 by drumfred          #+#    #+#             */
/*   Updated: 2021/10/22 19:55:50 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count * count > ((size_t) - 1) || (size * size > ((size_t) - 1) && \
		(size_t) - 1 / count < size))
		return (NULL);
	mem = (char *) malloc(count * size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, count * size);
	return (mem);
}
