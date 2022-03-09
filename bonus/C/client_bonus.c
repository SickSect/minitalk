/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:35:06 by ugina             #+#    #+#             */
/*   Updated: 2022/03/09 15:35:10 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	send(t_arg *arg)
{
	size_t	i;

	i = 0;
	while (arg->str[i])
	{
		get_char(arg->str[i], arg->pid);
		i++;
	}
}

int	check_argv(char *str)
{
	unsigned int	i;
	int				res;

	i = 0;
	res = -1;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = 1;
		else
			return (-1);
		i++;
	}
	return (res);
}

int	check_in(t_arg *arg, int argc, char **argv)
{
	if (!arg || argc != 3 || !check_argv(argv[1]))
		return (-1);
	arg->pid = ft_atoi(argv[1]);
	arg->str = argv[2];
	return (1);
}

static void	know_handler(int sig)
{
	(void)sig;
}

int	main(int argc, char **argv)
{
	t_arg	arg;

	signal(SIGUSR1, know_handler);
	if (check_in(&arg, argc, argv) == -1)
	{
		ft_putstr("Invalid CLI arguments", 2);
		return (1);
	}
	send(&arg);
	return (0);
}
