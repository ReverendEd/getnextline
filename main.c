#include <stdio.h>
#include "get_next_line.c"

int main(void)
{
	char *line;
	int fd = open("test_file.txt", O_RDONLY);
	
	while(get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
	
	return (0);
}