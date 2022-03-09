/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:51:20 by ugina             #+#    #+#             */
/*   Updated: 2022/03/09 15:51:22 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_char
{
	char	character;
	int		bit;
}	t_char;

void	ft_putstr(char *str, int fd);
char	*ft_itoa(int n);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *str_s);

#endif
