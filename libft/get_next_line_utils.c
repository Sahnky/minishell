/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:40:56 by julberna          #+#    #+#             */
/*   Updated: 2023/06/22 09:42:35 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	while (dest && dest[i] != '\0')
		i++;
	dest_len = i;
	i = 0;
	while (src && src[i] != '\0')
		i++;
	src_len = i;
	i = 0;
	if (size <= dest_len)
		return (size + src_len);
	while (src && (dest_len + i + 1) < size && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	int		s1_len;
	int		s2_len;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
		i++;
	s1_len = i;
	i = 0;
	while (s2 && s2[i] != '\0')
		i++;
	s2_len = i;
	joined = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (joined == NULL)
		return (NULL);
	ft_strlcat(joined, s1, s1_len + 1);
	ft_strlcat(joined, s2, s1_len + s2_len + 1);
	return ((char *)joined);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	int		result;

	pointer = NULL;
	result = nmemb * size;
	if (!nmemb || !size || nmemb == result / size)
		pointer = malloc(result);
	if (pointer)
		while (result--)
			*(unsigned char *)(pointer + result) = 0;
	return (pointer);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char				*substr;
	unsigned int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (start > i)
	{
		len = 0;
		start = i;
	}
	if ((i + start) < len)
		len = i + start;
	substr = ft_calloc((len + 1), sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcat(substr, s + start, len + 1);
	return (substr);
}
