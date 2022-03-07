#ifndef CLIENT_H
# define CLIENT_H

#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_arg
{
	int 	pid;
	char	*str;
}	t_arg;

int	check_in(int argc, char **argv, t_arg *arg);
void putstr_endl(char *line, int fd);
void putstr(char *line, int fd);
int	atoi(const char *str);
char	*ft_itoa(int n);

#endif
