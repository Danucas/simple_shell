#include "shell_libs.h"
/**
 *_gethostname - set the hostname to the buffer;
 *@buff: storage for the hostname
 *@size: max size to read
 */
void _gethostname(char *buff, int size)
{
	(void) buff;
	(void) size;
	int fd, rd;

	fd = open("/proc/sys/kernel/hostname", O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Can't get hostname from kernel\n");
		return;
	}
	rd = read(fd, buff, size);
	if (rd < 0)
	{
		printf("Error: Can't read hostname from kernel\n");
		return;
	}
	buff[rd - 1] = '\0';
}
