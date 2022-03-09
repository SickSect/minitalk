/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:47:16 by ugina             #+#    #+#             */
/*   Updated: 2022/03/09 15:47:19 by ugina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

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

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_mod(long n, int len, int neg)
{
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) *(len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		neg = -1;
		n = -n;
	}
	str[len] = '\0';
	while (--len)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	if (neg < 0)
		str[0] = '-';
	else
		str[0] = '0' + (n % 10);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		neg;
	long	nb;
	int		len;

	len = ft_len(n);
	nb = n;
	neg = 0;
	str = ft_mod(nb, len, neg);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strdup(const char *str_s)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(str_s) + 1));
	if (!str)
		return (NULL);
	while (str_s[i])
	{
		str[i] = str_s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
