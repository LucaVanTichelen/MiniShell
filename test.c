#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	file;
	int	file2;
	int fd;

	int stdout_file = dup(1);
	// file = open("output", O_WRONLY | O_CREAT | O_TRUNC, 0644); // >
	// file = open("output", O_WRONLY | O_CREAT | O_APPEND, 0644); // >>
	file = open("input", O_RDONLY); // <
	file2 = dup2(file , 0);
	// file2 = dup2(file, 1);
	// printf("Hello\n");
	return (0);
}
