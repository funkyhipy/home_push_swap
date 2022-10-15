/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	n_op_rotate_to_top(t_stack *s, int idx)
{
	if (idx <= s->nbr / 2)
		return (idx);
	else
		return (s->nbr - idx);
}

void	rotate_to_top(t_stack *s, int idx)
{
	if (idx == 0)
		return ;
	if (idx <= s->nbr / 2)
	{
		while (idx--)
			do_op(OP_ROT, s, NULL);
	}
	else
	{
		idx -= s->nbr;
		while (idx++)
			do_op(OP_R_ROT, s, NULL);
	}
}

int	find_min_value(const t_stack *s, int above)
{
	int	min_idx;
	int	idx;
	int	min;
	int	val;

	idx = 1;
	min_idx = 0;
	min = get_e(s, 0);
	while (idx < s->nbr)
	{
		val = get_e(s, idx);
		if (val < min && val >= above)
		{
			min = val;
			min_idx = idx;
		}
		idx++;
	}
	return (min_idx);
}

int	find_max_value(const t_stack *s, int under)
{
	int	max_idx;
	int	idx;
	int	max;
	int	val;

	idx = 1;
	max_idx = 0;
	max = get_e(s, 0);
	if (under < 0)
		under = s->n_tot;
	while (idx < s->nbr)
	{
		val = get_e(s, idx);
		if (val > max && val <= under)
		{
			max = get_e(s, idx);
			max_idx = idx;
		}
		idx++;
	}
	return (max_idx);
}
