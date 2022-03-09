/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:36:01 by ugina             #+#    #+#             */
/*   Updated: 2022/03/09 15:36:04 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	get_char(char str, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (str & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
		bit++;
	}
}

void	ft_putstr(char *str, int fd)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

static int	ft_whiler(const char *str, int neg, int i)
{
	long	res;
	int		max;

	max = 0;
	res = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + (str[i++] - '0');
		max++;
	}
	if (max > 19)
	{
		if (neg == 1)
			return (0);
		return (-1);
	}
	if (neg == 1)
		return (-1 * res);
	return (res);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	res;

	i = 0;
	neg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\v' || str[i] == '\r'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		i++;
		neg = 1;
	}
	else if (str[i] == '+')
		i++;
	res = ft_whiler(str, neg, i);
	return (res);
}
