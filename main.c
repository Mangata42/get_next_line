#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;

	if (argc != 2)
	{
		ft_putstr("file you stoopid");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	ret = 42;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%s  ret = %d\n", line, ret);
	}
	return (0);
}