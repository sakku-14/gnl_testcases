#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *line;
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	ac = 0;
	return (0);
}


//stdin ver
/*
int main(int ac, char **av)
{
	int fd = 0;
	char *line;
	while (get_next_line(fd, &line))
		printf("%s\n", line);
	printf("%s\n", line);
	return (0);
}
*/
