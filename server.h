#ifndef SERVER_H
# define SERVER_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

typedef struct s_char
{
	char	ch;
	int		cur_bit;
}	t_char;

void	putstr_endl(char *line, int fd);
void	putstr(char *line, int fd);
int		atoi(const char *str);
char	*ft_itoa(int n);

#endif