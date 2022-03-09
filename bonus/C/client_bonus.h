#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_arg
{
	int		pid;
	char	*str;
}	t_arg;

void	ft_putstr(char *str, int fd);
int		ft_atoi(const char *str);
void	get_char(char str, int pid);

#endif
