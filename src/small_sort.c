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

#include "libft.h"
#include "push_swap.h"

void	sort_3(t_stack *a)
{
	if (is_sorted(a, SORT_ASCENDING))
		return ;
	if (get_e(a, 0) < get_e(a, 1) && get_e(a, 0) < get_e(a, 2))
	{
		do_op(OP_R_ROT, a, NULL);
		do_op(OP_SWAP, a, NULL);
	}
	else if (get_e(a, 0) < get_e(a, 1))
		do_op(OP_R_ROT, a, NULL);
	else if (get_e(a, 0) < get_e(a, 2))
		do_op(OP_SWAP, a, NULL);
	else if (get_e(a, 1) < get_e(a, 2))
		do_op(OP_ROT, a, NULL);
	else
	{
		do_op(OP_ROT, a, NULL);
		do_op(OP_SWAP, a, NULL);
	}
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	min_idx;

	min_idx = find_min_value(a, -1);
	rotate_to_top(a, min_idx);
	do_op(OP_PUSH, b, a);
	sort_3(a);
	do_op(OP_PUSH, a, b);
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	min_idx;

	min_idx = find_min_value(a, -1);
	rotate_to_top(a, min_idx);
	do_op(OP_PUSH, b, a);
	sort_4(a, b);
	do_op(OP_PUSH, a, b);
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
