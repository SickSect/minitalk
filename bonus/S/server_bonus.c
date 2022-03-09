#include "server_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

static void	handler_msg(int sig, siginfo_t *info, void *context)
{
	static t_char chr = {0, 0};

	(void)context;
	if(sig == SIGUSR2)
		chr.character |= 1 << chr.bit;
	chr.bit++;
	if(chr.bit == 8)
	{
		ft_putchar_fd(chr.character, 1);
		chr.character = 0;
		chr.bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

static void	handler_exit(int sig)
{
	(void)sig;
	exit(0);
}

void	print_pid(void)
{
	pid_t	pid;
	char *str_pid;

	pid = getpid();
	str_pid = ft_itoa(pid);
	if(!str_pid)
	{
		ft_putstr("Error at itoa()", 2);
		return ;
	}
	ft_putstr(str_pid, 1);
	free(str_pid);
}

int	main(void)
{
	struct sigaction sa;

	print_pid();
	sa.sa_handler = SIG_DFL; 
	sa.sa_sigaction = handler_msg;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, handler_exit);
	signal(SIGTERM, handler_exit);
	while (1)
		pause();
}
