#include "client.h"

static void	print_pid(void)
{
	__pid_t pid;
	char	*pidstr;

	pid = getgid();
	pidstr = ft_itoa(pid);
	if (!pidstr)
	{
		putstr_endl("Error at ft_itoa(pid)", 2);
		return ;
	}
	putstr_endl(pidstr, 2);
	free(pidstr);
}

static void	leave(int crypt)
{
	(void)sig;
	exit (0);
}

static void	catch_n_crypt(int crypt)
{

}

int	main(void)
{
	print_pid();
	signal(SIGUSR1, catch_n_crypt);
	signal(SIGUSR2, catch_n_crypt);
	signal(SIGINT,)
}