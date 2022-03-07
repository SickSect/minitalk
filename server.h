#ifndef SERVER_H
# define SERVER_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

typedef struct s_char
{
	char	character;
	int	current_bit;
}	t_char;

void putstr_endl(char *line, int fd);
void putchar(char ch, int fd);
char	*ft_itoa(int n);
char	*ft_strdup(const char *str_s);
int	ft_strlen(const char *str);

#endif
