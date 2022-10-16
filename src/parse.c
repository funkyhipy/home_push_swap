/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

static int	check_only_digits(const char *str)
{
	while (str && *str)
	{
		if (*str != '-' && !ft_isdigit(*str) && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int	parse_str(const char *arg, t_stack *s)
{
	char	**args;
	int		i;
	int		res;

	i = 0;
	args = ft_split(arg, ' ');
	while (args[i])
		++i;
	res = parse_args(i, args, s);
	while (i--)
		free(args[i]);
	free(args);
	return (res);
}

int	parse_args(int n_args, char *args[], t_stack *s)
{
	long	val;
	int		i;

	i = 0;
	stack_init(s, n_args, STACK_A);
	while (args[i] && i < n_args)
	{
		if (!check_only_digits(args[i]))
			return (0);
		val = ft_atol(args[i]);
		if (val > 2147483647 || val < -2147483648)
			return (0);
		stack_add_back(s, (int)val);
		i++;
	}
	return (1);
}
