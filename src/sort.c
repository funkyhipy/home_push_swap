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

typedef struct s_sort_info
{
	int	n_chks;
	int	n_per_chunks;
	int	i_chk;
	int	low_thres;
	int	up_thres;
}	t_sort_info;

/*
 * Return the number of values that are pushed under
 *
 * */
static int	push_chunk_back_to_a(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	max_pos;
	int	n_low;

	n_low = 0;
	while (b->nbr)
	{
		min_pos = find_min_value(b, -1);
		max_pos = find_max_value(b, -1);
		if (n_op_rotate_to_top(b, min_pos) < n_op_rotate_to_top(b, max_pos))
		{
			rotate_to_top(b, min_pos);
			do_op(OP_PUSH, a, b);
			do_op(OP_ROT, a, NULL);
		}
		else
		{
			rotate_to_top(b, max_pos);
			do_op(OP_PUSH, a, b);
			n_low++;
		}
	}
	return (n_low);
}

static void	send_above_threshold_to_b(t_stack *a, t_stack *b, t_sort_info *info)
{
	int	i;
	int	check_until;
	int	n_rot;

	info->low_thres = a->n_tot - (info->i_chk + 1) * info->n_per_chunks;
	info->up_thres = a->n_tot - (info->i_chk) * info->n_per_chunks;
	check_until = a->nbr - info->i_chk * info->n_per_chunks;
	if (info->i_chk == info->n_chks - 1)
		info->low_thres = 0;
	i = 0;
	n_rot = 0;
	while (i < check_until)
	{
		if (get_e(a, 0) >= info->low_thres && get_e(a, 0) < info->up_thres)
		{
			do_op(OP_PUSH, b, a);
		}
		else
		{
			do_op(OP_ROT, a, NULL);
			n_rot++;
		}
		i++;
	}
}

static void	compute_n_chunks(t_stack *a, t_sort_info *info)
{
	if (a->n_tot > 200)
		info->n_chks = 7;
	else if (a->n_tot > 80)
		info->n_chks = 4;
	else
		info->n_chks = 3;
	info->i_chk = 0;
	info->n_per_chunks = a->n_tot / info->n_chks;
}

static void	sort_chunk(t_stack *a, t_stack *b, t_sort_info *info)
{
	int	n_lows;

	send_above_threshold_to_b(a, b, info);
	n_lows = push_chunk_back_to_a(a, b);
	n_lows += info->i_chk * info->n_per_chunks;
	while (n_lows--)
		do_op(OP_ROT, a, NULL);
}

void	sort(t_stack *a, t_stack *b)
{
	t_sort_info	info;

	if (a->n_tot < 2 || is_sorted(a, SORT_ASCENDING))
		return ;
	else if (a->nbr <= 5)
		return (small_sort(a, b));
	compute_n_chunks(a, &info);
	while (info.i_chk < info.n_chks)
	{
		sort_chunk(a, b, &info);
		info.i_chk++;
	}
}
