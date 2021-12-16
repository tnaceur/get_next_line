/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:35:10 by tnaceur           #+#    #+#             */
/*   Updated: 2021/12/15 22:00:26 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

char	*ft_strdup(char *s1)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen_line(s1, '\0') + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < ft_strlen_line(s1, '\0'))
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*move(char *saved, int i, int j)
{
	char	*str;

	str = NULL;
	if (ft_strchr(saved, '\n') == NULL)
	{
		saved[0] = '\0';
		return (saved);
	}
	while (saved[i])
	{
		if (saved[i] == '\n')
			break ;
		i++;
	}	
	str = malloc(ft_strlen_line(saved, '\0') - i + 1);
	if (!str)
		return (NULL);
	while (saved[i])
		str[j++] = saved[++i];
	str[j] = '\0';
	ft_free(&saved);
	return (str);
}

char	*ft_read(char *saved, int fd)
{
	char	*tmp;
	ssize_t	i;

	i = 1;
	while (i)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (NULL);
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
		{
			ft_free(&tmp);
			return (NULL);
		}
		tmp[i] = '\0';
		saved = ft_strjoin(saved, tmp);
		ft_free(&tmp);
		if (ft_strchr(saved, '\n') != NULL)
			return (saved);
	}
	ft_free(&tmp);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*tmp;
	int			i;
	int			j;

	tmp = NULL;
	i = 0;
	j = 0;
	if ((fd < 0 || BUFFER_SIZE <= 0)
		|| (read(fd, tmp, BUFFER_SIZE) == 0 && !saved))
		return (NULL);
	if (!saved || ft_strchr(saved, '\n') == NULL)
		saved = ft_read(saved, fd);
	if (saved)
	{
		tmp = ft_substr(saved);
		saved = move(saved, i, j);
		if (!saved[0])
		{
			free(saved);
			saved = NULL;
		}
		return (tmp);
	}
	return (saved);
}
