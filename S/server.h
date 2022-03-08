#ifndef SERVER_H
# define SERVER_H

#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct s_char
{
	char	character;
	int		bit;
}	t_char;

void ft_putstr(char *str, int fd);
char	*ft_itoa(int n);
int	ft_strlen(const char *str);
char	*ft_strdup(const char *str_s);

#endif