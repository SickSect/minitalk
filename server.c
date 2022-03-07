#include "server.h"

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
	(void)crypt;
	exit (0);
}

static void	catch_n_crypt(int crypt)
{
	static t_char sym = {0, 0};
	
	if(crypt == SIGUSR2)
		// act
	sym.cur_bit++;
	if(sym.cur_bit == 8)
	{
		//print
	}
}

int	main(void)
{
	print_pid();
	signal(SIGUSR1, catch_n_crypt);
	signal(SIGUSR2, catch_n_crypt);
	signal(SIGINT, leave);
	signal(SIGTERM, leave);
	while (1)
		pause();
}