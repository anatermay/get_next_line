/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:40:29 by aternero          #+#    #+#             */
/*   Updated: 2024/08/09 13:41:10 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	index[2];

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	index[0] = 0;
	index[1] = 0;
	while (s1[index[0]])
	{
		str[index[0]] = s1[index[0]];
		index[0]++;
	}
	while (s2[index[1]])
		str[index[0]++] = s2[index[1]++];
	str[index[0]] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	if (!s)
		return (0);
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (0);
}

/* We are working on get_next_line project and
	we need to implement ft_strlcat, ft_strlcpy,
	ft_strlen, ft_strjoin and ft_strchr.
	We are going to implement these functions
	in get_next_line_utils.c file.
ft_strchr will be used in get_next_line.c file to
	find the newline character in the buffer. If it
	is found, we will return the address of the
	newline character. If it is not found, we will
	return NULL.
ft_strjoin will be used in get_next_line.c file to
	join the buffer and the line. We will allocate
	memory for the new string and copy the buffer
	and the line to the new string.
ft_strlen will be used in get_next_line.c file to
	find the length of the buffer and the line.
ft_strlcpy will be used in get_next_line.c file to
	copy the buffer and the line to the new string.
ft_strlcat will be used in get_next_line.c file to
	concatenate the buffer and the line to the new
	string. */