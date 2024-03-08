/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar < itulgar@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:11:16 by itulgar           #+#    #+#             */
/*   Updated: 2024/01/10 17:19:51 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_nl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *temp)
{
	int		i;
	int		j;
	char	*ns;

	i = -1;
	j = -1;
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		str[0] = '\0';
	}
	ns = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(temp) + 1));
	if (!ns)
		return (NULL);
	while ((str[++i]))
		ns[i] = str[i];
	while (temp[++j])
		ns[i + j] = temp[j];
	ns[i + j] = '\0';
	free(str);
	return (ns);
}
