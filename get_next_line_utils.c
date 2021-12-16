/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:33:38 by tnaceur           #+#    #+#             */
/*   Updated: 2021/12/15 21:54:47 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen_line(char *saved, char c)
{
	int	i;

	i = 0;
	while (saved[i] && saved[i] != c)
		i++ ;
	if (saved[i] == c)
	{
		if (saved[i] == '\0')
			return (i);
		i++ ;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != c)
		i++ ;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*ptr;
	int		i;
	int		j;

	if (!s1)
		s1 = ft_strdup("");
	len = ft_strlen_line(s1, '\0') + ft_strlen_line(s2, '\0');
	ptr = malloc(len + 1);
	i = 0;
	j = 0;
	while (s1[i])
		ptr[j++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[j++] = s2[i++];
	ptr[j] = '\0';
	free(s1);
	s1 = NULL;
	return (ptr);
}

char	*ft_substr(char *saved)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen_line(saved, '\n') + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (saved[i])
	{	
		if (saved[i] == '\n')
		{
			str[i] = saved[i];
			str[i + 1] = '\0';
			return (str);
		}
		str[i] = saved[i];
		i++ ;
	}
	str[i] = '\0';
	return (str);
}
