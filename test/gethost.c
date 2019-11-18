#include "shell_libs.h"
/**
 *_gethostname - set the hostname to the buffer;
 *@buff: storage for the hostname
 *@size: max size to read
 *Return: 0 if succes -1 if something wrong
 */
int _gethostname(char *buff, int size)
{
	(void) buff;
	(void) size;
	int fd, rd;

	fd = open("/proc/sys/kernel/hostname", O_RDONLY);
	if (fd < 0)
	{
	  /*		printf("Error: Can't get hostname from kernel\n");*/
		return (-1);
	}
	rd = read(fd, buff, size);
	if (rd < 0)
	{
	  /*		printf("Error: Can't read hostname from kernel\n");*/
		return (-1);
	}
	buff[rd - 1] = '\0';
	return (0);
}
