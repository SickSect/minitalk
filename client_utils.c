#include "client.h"

int	check_argv(char *str)
{
	size_t	i;
	int		boolean;

    	i = 0;
	boolean = -1;
	while (str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
			boolean = 1;
		else
			return (-1);
		i++;
	}
	return (boolean);
}

int	check_in(int argc, char **argv, t_arg *arg)
{
	if (argc != 3 || !arg || !check_argv(argv[1]))
		return (-1);
	arg->str = argv[2];
	arg->pid = atoi(argv[1]);
	return(0);
}

void putstr_endl(char *line, int fd)
{
    unsigned int	i;

    i = 0;
	while(line[i])
	{
		write(fd, &line[i], 1);
		i++;
	}
	write(1, "\n", 1);
}
