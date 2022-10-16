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

int	n_op_rotate_to_top(t_stack *s, int i)
{
	if (i <= s->nbr / 2)
		return (i);
	else
		return (s->nbr - i);
}

void	rotate_to_top(t_stack *s, int i)
{
	if (i == 0)
		return ;
	if (i <= s->nbr / 2)
	{
		while (i--)
			do_op(OP_ROT, s, NULL);
	}
	else
	{
		i -= s->nbr;
		while (i++)
			do_op(OP_R_ROT, s, NULL);
	}
}

int	find_min_value(const t_stack *s, int above)
{
	int	min_i;
	int	i;
	int	min;
	int	val;

	i = 1;
	min_i = 0;
	min = get_e(s, 0);
	while (i < s->nbr)
	{
		val = get_e(s, i);
		if (val < min && val >= above)
		{
			min = val;
			min_i = i;
		}
		++i;
	}
	return (min_i);
}

int	find_max_value(const t_stack *s, int under)
{
	int	max_i;
	int	i;
	int	max;
	int	val;

	i = 1;
	max_i = 0;
	max = get_e(s, 0);
	if (under < 0)
		under = s->max_size;
	while (i < s->nbr)
	{
		val = get_e(s, i);
		if (val > max && val <= under)
		{
			max = get_e(s, i);
			max_i = i;
		}
		++i;
	}
	return (max_i);
}
