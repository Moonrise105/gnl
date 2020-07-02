/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 18:09:38 by ctobias           #+#    #+#             */
/*   Updated: 2020/06/14 19:16:39 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t k;

	k = 0;
    if (str)
    {
        while (*str)
        {
            k++;
            str++;
        }
    }
	return (k);
}

char	*ft_strchr(const char *s, int c)
{
	char *p;

	p = (char*)s;
	while (*p && (*p != (char)c))
		p++;
	if (*p == (char)c)
		return (p);
	return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *p;

	if (!s1 && !s2)
		return (NULL);
	str = (char*)malloc(sizeof(char) * \
	((s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0) + 1));
	if (!str)
		return (NULL);
	p = str;
	if (s1)
	{
		while (*s1)
			*str++ = *s1++;
	}
	if (s2)
	{
		while (*s2)
			*str++ = *s2++;
	}
	*str = '\0';
	return (p);
}

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t result;

	i = ft_strlen(dest);
	result = ft_strlen(src);
	if (i >= size)
		result += size;
	else
		result += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (result);
}

char		*ft_strdup(const char *str)
{
	int		len;
	char	*new_str;
	char	*p;

	len = ft_strlen(str);
	new_str = (char*)malloc(sizeof(char) * len + 1);
	p = new_str;
	if (!new_str)
		return (NULL);
	while (*str)
	{
		*new_str = *str;
		new_str++;
		str++;
	}
	*new_str = *str;
	return (p);
}

void		ft_strclr(char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
	{
		*(s + i) = '\0';
		i++;
	}
}

void		*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (!count || dest == src)
		return (dest);
	dest_ptr = (unsigned char*)dest;
	src_ptr = (unsigned char*)src;
	while (count-- > 0)
		*(dest_ptr++) = *(src_ptr++);
	return (dest);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_size;

	src_size = ft_strlen(src);
	if (src_size + 1 < size)
		ft_memcpy(dst, src, src_size + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_size);
}
