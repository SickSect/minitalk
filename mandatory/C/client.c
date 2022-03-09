#include "client.h"

void get_char(char str, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (str & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		bit++;
	}
}

void	send(t_arg *arg)
{
	size_t	i;

	i = 0;
	while(arg->str[i])
	{
		get_char(arg->str[i], arg->pid);
		i++;
	}
}

int	check_argv(char *str)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = -1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = 1;
		else
			return (-1);
		i++;
	}
	return (res);
}

int	check_in(t_arg *arg, int argc, char **argv)
{
	if(!arg || argc != 3 || !check_argv(argv[1]))
		return (-1);
	arg->pid = ft_atoi(argv[1]);
	arg->str = argv[2];
	return (1);
}

int main(int argc, char **argv)
{
	t_arg    arg;

	if (check_in(&arg, argc, argv) == -1)
	{
		ft_putstr("Invalid CLI arguments", 2);
		return (1);
	}
	send(&arg);
	return (0);
}
