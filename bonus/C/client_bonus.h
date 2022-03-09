/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:39:01 by ugina             #+#    #+#             */
/*   Updated: 2022/03/09 15:39:03 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
