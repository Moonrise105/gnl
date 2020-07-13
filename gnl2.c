
#include "get_next_line.h"



int get_next_line(int fd, char **line)
{
	if (fd < 0 || !line || (read(fd, buff, 0)) < 0 || BUFFER_SIZE < 1)
    {
        return (-1);
    }

	//read_len = read(fd, buff, BUFFER_SIZE)

}