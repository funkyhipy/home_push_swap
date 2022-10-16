/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	is_sorted(const t_stack *s, int order)
{
	int	i;

	i = 0;
	if (order)
	{
		while (++i < s->nbr)
		{
			if (get_e(s, i) <= get_e(s, i - 1))
				return (0);
		}
	}
	else
	{
		while (++i < s->nbr)
		{
			if (get_e(s, i) >= get_e(s, i - 1))
				return (0);
		}
	}
	return (1);
}
