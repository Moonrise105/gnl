/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 17:29:00 by ctobias           #+#    #+#             */
/*   Updated: 2020/06/15 00:38:40 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 32

char *check_read_buff(char *read_buff, char **line)
{
	char *p;

	p = NULL;
	
	if (read_buff)
	{
		
		if ((p = ft_strchr(read_buff, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(read_buff);
			++p;
			ft_strlcpy(read_buff, p, ft_strlen(p));
		}
		else
		{
			*line = ft_strdup(read_buff);
			ft_strclr(read_buff);
		}
	}
	else
	{
		//printf("in");
		*line = ft_strdup("\0");
	}
	return (p);
}

int get_next_line(int fd, char **line)
{
	char 		buff[BUFFER_SIZE + 1];
	int 		read_len;
	static char *read_buff;
	char 		*n_pos;
	char		*tmp;
	
	//read_buff = NULL;
	n_pos = NULL;
	// if (fd == -1)
	// 	return (-1);

	if (fd < 0 || !line || (read(fd, buff, 0)) < 0)
		return (-1);
	n_pos = check_read_buff(read_buff, line);
	while (!n_pos && (read_len = read(fd, buff, BUFFER_SIZE)))
	{
		buff[read_len] = '\0';
		if ((n_pos = ft_strchr(buff, '\n')))
		{
			*n_pos = '\0';
			if (read_buff)
				free(read_buff);
			read_buff = ft_strdup(++n_pos);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	return ((read_len || ft_strlen(*line)) ? 1 : 0);	
}

int main(void)
{
	char *line;
	int fd;

	line = NULL;
	//line = "g";
	//fd = open("42TESTERS-GNL/files/half_marge_top", O_RDONLY);
	fd = open("file", O_RDONLY);
	//get_next_line(fd, &line);
	
	while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	//printf("s\n")
		
	//printf("%s\n", line);
	//free(line);
	close(fd);
	return (0);
}