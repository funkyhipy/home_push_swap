/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	push_chunk_back_to_a(t_stack *s1, t_stack *s2)
{
	int	min_i;
	int	max_i;
	int	n;

	n = 0;
	while (s2->nbr)
	{
		min_i = find_min_value(s2, -1);
		max_i = find_max_value(s2, -1);
		if (n_op_rotate_to_top(s2, min_i) < n_op_rotate_to_top(s2, max_i))
		{
			rotate_to_top(s2, min_i);
			do_op(OP_PUSH, s1, s2);
			do_op(OP_ROT, s1, NULL);
		}
		else
		{
			rotate_to_top(s2, max_i);
			do_op(OP_PUSH, s1, s2);
			n++;
		}
	}
	return (n);
}

static void	send_above_threshold_to_b(t_stack *s1, t_stack *s2, t_chunk *chk)
{
	int	i;
	int	check_until;
	int	n_rot;

	chk->low_thres = s1->max_size - (chk->idx + 1) * chk->size;
	chk->up_thres = s1->max_size - (chk->idx) * chk->size;
	check_until = s1->nbr - chk->idx * chk->size;
	if (chk->idx == chk->chk_nbrs - 1)
		chk->low_thres = 0;
	i = 0;
	n_rot = 0;
	while (i < check_until)
	{
		if (get_e(s1, 0) >= chk->low_thres && get_e(s1, 0) < chk->up_thres)
		{
			do_op(OP_PUSH, s2, s1);
		}
		else
		{
			do_op(OP_ROT, s1, NULL);
			n_rot++;
		}
		i++;
	}
}

static void	compute_n_chunks(t_stack *s1, t_chunk *chk)
{
	if (s1->max_size > 200)
		chk->chk_nbrs = 7;
	else if (s1->max_size > 80)
		chk->chk_nbrs = 4;
	else
		chk->chk_nbrs = 3;
	chk->idx = 0;
	chk->size = s1->max_size / chk->chk_nbrs;
}

static void	sort_chunk(t_stack *s1, t_stack *s2, t_chunk *chk)
{
	int	n;

	send_above_threshold_to_b(s1, s2, chk);
	n = push_chunk_back_to_a(s1, s2);
	n += chk->idx * chk->size;
	while (n--)
		do_op(OP_ROT, s1, NULL);
}

void	sort(t_stack *s1, t_stack *s2)
{
	t_chunk	chk;

	if (s1->max_size < 2 || is_sorted(s1, SORT_ASCENDING))
		return ;
	else if (s1->nbr <= 5)
		return (small_sort(s1, s2));
	compute_n_chunks(s1, &chk);
	while (chk.idx < chk.chk_nbrs)
	{
		sort_chunk(s1, s2, &chk);
		chk.idx++;
	}
}
