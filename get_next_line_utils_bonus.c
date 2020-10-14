/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:37:57 by yslati            #+#    #+#             */
/*   Updated: 2019/12/16 17:38:00 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t					ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int						check_static(char *t)
{
	while (*t)
		if (*t++ == '\n')
			return (1);
	return (0);
}

int						line_len(const char *str)
{
	int			i;

	i = 0;
	while (*str && *str != '\n')
	{
		str++;
		i++;
	}
	return (i);
}

char					*ft_strjoin(char *str1, char *str2, char c)
{
	char		*p;
	char		*tmp;

	if (str1)
		p = (char*)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	else
		p = (char*)malloc(ft_strlen(str2) + 1);
	if (!p)
		return (NULL);
	tmp = p;
	if (str1)
		while (*str1)
			*p++ = *str1++;
	while (*str2 != c)
		*p++ = *str2++;
	*p = '\0';
	return (tmp);
}

char					*ft_strdup(const char *s1)
{
	int			i;
	size_t		len;
	char		*p;

	len = ft_strlen(s1);
	i = 0;
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
