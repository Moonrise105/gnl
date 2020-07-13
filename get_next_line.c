/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 00:38:40 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/13 23:09:25 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define BUFFER_SIZE 32
#include "get_next_line.h"

char *check_read_buff(char *read_buff, char **line, int *flag)
{
	char *p;

	p = NULL;
	
	if (read_buff && ft_strlen(read_buff))
	{
		if ((p = ft_strchr(read_buff, '\n')))
		{
			*flag = 1;
			*p = '\0';
			*line = ft_strdup(read_buff);
            ++p;
			//printf("p = %s\n", p);
			ft_strlcpy(read_buff, p, ft_strlen(p) + 1);
		}
		else
		{
			*line = ft_strdup(read_buff);
			ft_strclr(read_buff);
            
		}
	}
	else
	{
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
	int flag;

	flag = 0;
	
	n_pos = NULL;
	if (fd < 0 || !line || (read(fd, buff, 0)) < 0 || BUFFER_SIZE < 1)
    {
        return (-1);
    }
		
	n_pos = check_read_buff(read_buff, line, &flag);
	//printf("{%s}\n", n_pos);
	while (!n_pos && (read_len = read(fd, buff, BUFFER_SIZE)))
	{
		buff[read_len] = '\0';
		if ((n_pos = ft_strchr(buff, '\n')))
		{
			*n_pos = '\0';
			// if (read_buff)
			// {
			// 	free(read_buff);
			// 	read_buff = NULL;
			// }
				
			read_buff = ft_strdup(++n_pos);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
	}
	if (read_len  || ft_strlen(read_buff) || flag)
	{
		return (1);
	}
	else 
	{
		// if (read_buff)
		// 	free(read_buff);
		// if (*line)
		// 	free(*line);
		return (0);
	}
	//return ((read_len  || ft_strlen(read_buff) || flag) ? 1 : 0); //mb bez ft_strlen(*line)
}

int main(void)
{
	char *line;
	int fd;

	int i;

	line = NULL;
;
	fd = open("4_newlines", O_RDONLY);
	

	while((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
        //line = NULL;
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}