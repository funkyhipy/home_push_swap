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

#include <stdlib.h>

#include "push_swap.h"
#include "libft.h"

// TODO: do better than O(n^2)
int	find_highest(t_stack *s)
{		
	int	highest;
	int	idx_highest;
	int	i;

	highest = s->v[0];
	idx_highest = 0;
	i = 1;
	while (i < s->nbr)
	{
		if (s->v[i] == highest && highest != -2147483648)
		{
			return (-1);
		}
		else if (s->v[i] > highest)
		{
			highest = s->v[i];
			idx_highest = i;
		}
		i++;
	}
	return (idx_highest);
}

// This function does 3 things :
// 1. Check if there are some duplicate values
//     - return 0 if there are some duplicates/malloc error
//     - return 1 if everything is OK
// 2. Transform the values into indexes 0..n_tot-1
//   Maybe not necessary for my algorithm, but nice to have some consistent
//   values.
// 3. Revert the order of the array, so that the top value is at the bottom,
//   which allows for better push operation
int	check_data(t_stack *s)
{
	int	*indexes;
	int	idx_highest;
	int	i_set;

	i_set = s->n_tot;
	indexes = ft_calloc(s->n_tot, sizeof(int));
	if (!indexes)
		return (0);
	while (i_set)
	{
		idx_highest = find_highest(s);
		if (idx_highest == -1)
		{
			free(indexes);
			return (0);
		}
		indexes[s->n_tot - idx_highest - 1] = --i_set;
		s->v[idx_highest] = -2147483648;
	}
	free(s->v);
	s->v = indexes;
	return (1);
}
