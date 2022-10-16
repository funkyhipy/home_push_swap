/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_3(t_stack *s)
{
	if (is_sorted(s, SORT_ASCENDING))
		return ;
	if (get_e(s, 0) < get_e(s, 1) && get_e(s, 0) < get_e(s, 2))
	{
		do_op(OP_R_ROT, s, NULL);
		do_op(OP_SWAP, s, NULL);
	}
	else if (get_e(s, 0) < get_e(s, 1))
		do_op(OP_R_ROT, s, NULL);
	else if (get_e(s, 0) < get_e(s, 2))
		do_op(OP_SWAP, s, NULL);
	else if (get_e(s, 1) < get_e(s, 2))
		do_op(OP_ROT, s, NULL);
	else
	{
		do_op(OP_ROT, s, NULL);
		do_op(OP_SWAP, s, NULL);
	}
}

void	sort_4(t_stack *s1, t_stack *s2)
{
	int	i;

	i = find_min_value(s1, -1);
	rotate_to_top(s1, i);
	do_op(OP_PUSH, s2, s1);
	sort_3(s1);
	do_op(OP_PUSH, s1, s2);
}

void	sort_5(t_stack *s1, t_stack *s2)
{
	int	i;

	i = find_min_value(s1, -1);
	rotate_to_top(s1, i);
	do_op(OP_PUSH, s2, s1);
	sort_4(s1, s2);
	do_op(OP_PUSH, s1, s2);
}

void	small_sort(t_stack *s1, t_stack *s2)
{
	if (s1->nbr == 2)
		do_op(OP_SWAP, s1, s2);
	else if (s1->nbr == 3)
		sort_3(s1);
	else if (s1->nbr == 4)
		sort_4(s1, s2);
	else if (s1->nbr == 5)
		sort_5(s1, s2);
}
