#include "client.h"

void	letter(int pid, char ch)
{
	int	cur_byte;

	cur_byte = 128;
	while(cur_byte != 0)
	{
		if(cur_byte & ch)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		cur_byte /= 2;
	}
}

void sending(t_arg *arg)
{
	unsigned int	i;

	i = 0;
	while(arg->str[i])
	{
		letter(arg->pid, arg->str[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_arg    arg;
	
	if (check_in(argc, argv, &arg) == -1)
	{
		putstr_endl("Invalid CLI arguments", 2);
		return (1);
	}
	sending(&arg);
	return (0);
}