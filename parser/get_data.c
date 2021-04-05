#include "../headers/overall.h"

char	*get_data(int fd)
{
	char	*data;
	char	*buff;
	int		buff_size;

	data = NULL;
	if (fd < 0 || BUFFER_SIZE < 1
			|| !(buff = malloc(BUFFER_SIZE + 1)) || read(fd, buff, 0) < 0)
		return (NULL);
	while ((buff_size = read(fd, buff, BUFFER_SIZE)))
	{
		buff[buff_size] = '\0';
		data = join_free(data, buff);
		if (data == NULL)
			buff_size = 0;
	}
	free(buff);
	return (data);
}
