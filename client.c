/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:09:33 by racasado          #+#    #+#             */
/*   Updated: 2024/10/09 13:25:22 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>
#include <signal.h>

size_t ft_strlen(char *str)
{
    size_t len = 0;
    while (str[++len]);
    return len;
}
int	ft_is_space(const char chr)
{
	if (chr == '\f' || chr == ' ' || chr == '\n' || chr == '\t' || chr == '\v'
		|| chr == '\r')
	{
		return (1);
	}
	return (0);
}
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_is_space(nptr[i]))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
}

int string_to_binary(char *str)
{
	int result = 0;
	int i = 0;
	while (str[i])
	{
		
	}
}

int main(int argc, char **argv)
{
    if (argc != 3 || ft_strlen(argv[1]) == 0 || ft_strlen(argv[2]) == 0)
    {
        return 1;
    }
    if (argc == 3)
    {
        int pid = ft_atoi(argv[1]);
        kill(pid,argv[2]);
    }
    return (0);
}