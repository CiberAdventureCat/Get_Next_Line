/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatwoma <kbatwoma@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 09:44:12 by kbatwoma          #+#    #+#             */
/*   Updated: 2020/07/21 09:20:59 by kbatwoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!dst && !src)
		return (0);
	while (src[len] != '\0')
		len++;
	if (size == 0)
		return (len);
	while (dst && src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	i;
	size_t	len;

	i = 0;
	len_dst = 0;
	while (dst[len_dst] != '\0')
		len_dst++;
	while (src[i] != '\0')
		i++;
	len = len_dst + i;
	if (size <= len_dst)
		return (i + size);
	i = 0;
	while (src[i] != '\0' && len_dst + 1 < size)
	{
		dst[len_dst] = src[i];
		i++;
		len_dst++;
	}
	dst[len_dst] = '\0';
	return (len);
}

char	*ft_strdup(const char *str)
{
	int		len;
	char	*duplicate;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	duplicate = malloc(sizeof(*str) * (len + 1));
	if (duplicate)
		ft_strlcpy(duplicate, str, len + 1);
	return (duplicate);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_s1;
	int		len_s2;

	if (!s1 || !s2)
		return (0);
	len_s1 = 0;
	len_s2 = 0;
	while (s1[len_s1] != '\0')
		len_s1++;
	while (s2[len_s2] != '\0')
		len_s2++;
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcat(str, s2, len_s1 + len_s2 + 1);
	return (str);
}

int		ft_free(char **array, int a)
{
	free(*array);
	*array = NULL;
	return (a);
}
