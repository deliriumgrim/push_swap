/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drumfred <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:39:44 by drumfred          #+#    #+#             */
/*   Updated: 2021/11/19 17:39:46 by drumfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*read_buff(int fd, char *buff, char *ostatok)
{
	long	count;
	char	*tmp;

	count = 1;
	while (count)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
			return (0);
		else if (count == 0)
			break ;
		buff[count] = '\0';
		if (!ostatok)
			ostatok = ft_strdup("");
		tmp = ostatok;
		ostatok = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ostatok);
}

static char	*recover_ostatok(char *str)
{
	long	count;
	char	*ost;

	count = 0;
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	if (str[count] == '\0' || str[1] == '\0' )
		return (0);
	ost = ft_substr(str, count + 1, ft_strlen(str) - count);
	if (*ost == '\0')
	{
		free(ost);
		ost = NULL;
	}
	str[count + 1] = '\0';
	return (ost);
}

char	*get_next_line(int fd)
{
	static char	*ostatok;
	char		*str;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = read_buff(fd, buff, ostatok);
	if (!str)
		return (NULL);
	ostatok = recover_ostatok(str);
	return (str);
}
