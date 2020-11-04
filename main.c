#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

/*
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
*/

//some av ver totyuuuuuuuuuuuuuuuuuuuuuu
int main(int ac, char **av)
{
	int		fd[MAX_FD];
	char	*line;
	int		i, flag = 0;
	int		ret;

	while(i + 1 < ac)
	{
		fd[i] = open(av[i + 1], O_RDONLY);
		i++;
	}
	i = 0;
	while(1)
	{
		while(i + 1 < ac)
		{
			if((ret = get_next_line(fd[i], &line)) == -1)
				flag = 1;
			if (flag == 0)
			{
				printf("fd%d:%d:%s\n", i, ret, line);
				free(line);
				i++;
			}
			else
			{
				printf("fd%d:%d:...error\n", i, ret);
			}
			flag = 0;
		}
		i = 0;
	}
	i = 0;
	while (i + 1 < ac)
	{
		close(fd[i]);
		i++;
	}
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
