/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	s_a;
	t_stack	s_b;
	int		status_ok;

	if (argc <= 1)
		return (0);
	if (argc == 2)
		status_ok = parse_str(argv[1], &s_a);
	else
		status_ok = parse_args(argc - 1, &argv[1], &s_a);
	if (!status_ok || !check_data(&s_a) || !stack_init(&s_b, s_a.nbr, STACK_B))
	{
		ft_putendl_fd("Error", 2);
		clear_stacks(&s_a, &s_b);
		return (1);
	}
	sort(&s_a, &s_b);
	clear_stacks(&s_a, &s_b);
	return (0);
}
