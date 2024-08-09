/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 13:53:13 by aternero          #+#    #+#             */
/*   Updated: 2024/08/09 13:49:49 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_cub(char *buff)
{
	char	*newbuff;
	ssize_t	count[2];

	count[0] = 0;
	count[1] = 0;
	while (buff[count[0]] && buff[count[0]] != '\n')
		count[0]++;
	if (!buff[count[0]])
	{
		free(buff);
		return (NULL);
	}
	newbuff = (char *)malloc(sizeof(char) * (ft_strlen(buff) - count[0] + 1));
	if (!newbuff)
		return (NULL);
	count[0]++;
	count[1] = 0;
	while (buff[count[0]] != '\0')
		newbuff[count[1]++] = buff[count[0]++];
	newbuff[count[1]] = '\0';
	free(buff);
	return (newbuff);
}

static char	*ft_ctlc(char *buff)
{
	char	*newtl;
	ssize_t	index;

	index = 0;
	if (!buff[index])
		return (NULL);
	while (buff[index] && buff[index] != '\n')
		index++;
	newtl = (char *)malloc(sizeof(char) * (index + 2));
	if (!newtl)
		return (NULL);
	index = 0;
	while (buff[index] && buff[index] != '\n')
	{
		newtl[index] = buff[index];
		index++;
	}
	if (buff[index] == '\n')
	{
		newtl[index] = '\n';
		index++;
	}
	newtl[index] = '\0';
	return (newtl);
}

static char	*ft_sastl(int fd, char *buff)
{
	char	*newbuff;
	ssize_t	rb;

	newbuff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!newbuff)
		return (NULL);
	rb = 1;
	while (!ft_strchr(buff, '\n') && rb)
	{
		rb = read(fd, newbuff, BUFFER_SIZE);
		if (rb == -1)
		{
			free(newbuff);
			return (NULL);
		}
		newbuff[rb] = '\0';
		buff = ft_strjoin(buff, newbuff);
	}
	free(newbuff);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[4096];
	char		*newtl;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buff[fd]);
		buff[fd] = NULL;
		return (NULL);
	}
	buff[fd] = ft_sastl(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	newtl = ft_ctlc(buff[fd]);
	buff[fd] = ft_cub(buff[fd]);
	return (newtl);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}

/*get_next_line is the main function, where we're goint to
	call the other functions. It receives the file descriptor and
	returns the next line of the file.
	First, it checks if the file descriptor is valid.
	Then, it calls the SASTL function to search and store the text
	line. After that, it calls the CTLC function to create a text line.
	Finally, it calls the CUB function to clean up the buffer and
	returns the new text line.
Get Next Line.
	This function will return the next line of the file.
	It receives the file descriptor and returns the next line.
	First, it checks if the file descriptor is valid.
	Then, it calls the SASTL function to search and store the text line.
	After that, it calls the CTLC function to create a text line.
	Finally, it calls the CUB function to clean up the buffer
	and returns the new text line.
	In bonus, we have to use fd as an index to store the buffer. This is
	because we have to read multiple files at the same time.

LET'S SEE THE FUNCTIONS:
SASTL = Search and Store Text Line.
	This function will search for the next line
	in the file and store it in a variable.
	It receives the file descriptor and a buffer. Then,
	it reads the file and join the lines until '\n' is found.
	By the way, rb is read bytes and temp is a temporary variable.
CTLC = Create a text line where we're goint to copy that we're obtaining.
	This function will create a new text line with the text that we're obtaining.
	It receives a buffer and returns a new text line.
	First, it counts the number of characters until '\n' is found.
	Then, it allocates memory for the new text line and copies the text.
	Finally, it returns the new text line.
CUB = Clean Up Buffer.
	This function will clean up the buffer.
	It receives a buffer and frees the memory.
	First, it frees the memory of the buffer.
	Then, it returns NULL.
*/
