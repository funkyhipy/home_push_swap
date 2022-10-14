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

#include "push_swap.h"

char	is_sorted(const t_stack *s, char ascending)
{
	int	idx;

	idx = 0;
	if (ascending)
	{
		while (++idx < s->nbr)
		{
			if (get_e(s, idx) <= get_e(s, idx - 1))
				return (0);
		}
	}
	else
	{
		while (++idx < s->nbr)
		{
			if (get_e(s, idx) >= get_e(s, idx - 1))
				return (0);
		}
	}
	return (1);
}
