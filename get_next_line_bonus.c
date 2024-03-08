/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:11:13 by itulgar           #+#    #+#             */
/*   Updated: 2024/01/12 13:57:14 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *str)
{
	int		byte;
	char	*temp;

	byte = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_nl(str) && byte != 0)
	{
		byte = read(fd, temp, BUFFER_SIZE);
		if (byte == -1)
		{
			if (str)
				free(str);
			free(temp);
			return (NULL);
		}
		temp[byte] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*ft_new_line(char *str)
{
	char	*news;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	news = malloc(i + 2);
	if (!news)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		news[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		news[i] = str[i];
		i++;
	}
	news[i] = '\0';
	return (news);
}

char	*ft_cutline(char *str)
{
	int		i;
	int		j;
	char	*s;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = malloc(ft_strlen(str) - i + 1);
	if (!s)
		return (NULL);
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*nstr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd] || !*str[fd])
	{
		if (str[fd])
			free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	nstr = ft_new_line(str[fd]);
	str[fd] = ft_cutline(str[fd]);
	return (nstr);
}
