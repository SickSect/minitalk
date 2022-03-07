#include "server.h"

static void	print_pid(void)
{
	pid_t pid;
	char	*pidstr;

	pid = getgid();
	pidstr = ft_itoa(pid);
	if (!pidstr)
	{
		putstr_endl("Error at ft_itoa(pid)", 2);
		return ;
	}
	putstr_endl(pidstr, 1);
	free(pidstr);
}

static void	handler_msg(int sig)
{
	static t_char	chr = {0, 0};

	if (sig == SIGUSR2)
		chr.character |= 1 << chr.current_bit;
	chr.current_bit++;
	if (chr.current_bit == 8)
	{
		putchar(chr.character, 1);
		chr.character = 0;
		chr.current_bit = 0;
	}
}

static void	handler_exit(int sig)
{
	(void)sig;
	exit(0);
}

int	main(void)
{
	print_pid();
	signal(SIGUSR1, handler_msg);
	signal(SIGUSR2, handler_msg);
	signal(SIGINT, handler_exit);
	signal(SIGTERM, handler_exit);
	while (1)
		pause();
}
