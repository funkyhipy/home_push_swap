/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	find_highest(t_stack *s)
{		
	int	h;
	int	idx_h;
	int	i;

	h = s->values[0];
	idx_h = 0;
	i = 1;
	while (i < s->nbr)
	{
		if (s->values[i] == h && h != -2147483648)
		{
			return (-1);
		}
		else if (s->values[i] > h)
		{
			h = s->values[i];
			idx_h = i;
		}
		i++;
	}
	return (idx_h);
}

int	check_data(t_stack *s)
{
	int	*indexes;
	int	idx_h;
	int	i_set;

	i_set = s->max_size;
	indexes = ft_calloc(s->max_size, sizeof(int));
	if (!indexes)
		return (0);
	while (i_set)
	{
		idx_h = find_highest(s);
		if (idx_h == -1)
		{
			free(indexes);
			return (0);
		}
		indexes[s->max_size - idx_h - 1] = --i_set;
		s->values[idx_h] = -2147483648;
	}
	free(s->values);
	s->values = indexes;
	return (1);
}
