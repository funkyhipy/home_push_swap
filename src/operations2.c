/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

static void	do_complex_op(const char *op, t_stack *s1, t_stack *s2)
{
	if (!ft_strncmp(op, OP_SWAP_BOTH, 2))
	{
		swap(s1);
		swap(s2);
		ft_printf("ss\n");
	}
	else if (!ft_strncmp(op, OP_R_ROT_BOTH, 3))
	{
		r_rot(s1);
		r_rot(s2);
		ft_printf("rrr\n");
	}
	else if (!ft_strncmp(op, OP_ROT_BOTH, 2))
	{
		rot(s1);
		rot(s2);
		ft_printf("rr\n");
	}
}

void	do_op(const char *op, t_stack *s1, t_stack *s2)
{
	if (!ft_strncmp(op, OP_SWAP, 1))
		swap(s1);
	else if (!ft_strncmp(op, OP_PUSH, 1))
		push(s1, s2);
	else if (!ft_strncmp(op, OP_R_ROT, 2))
		r_rot(s1);
	else if (!ft_strncmp(op, OP_ROT, 1))
		rot(s1);
	else
	{
		do_complex_op(op, s1, s2);
		return ;
	}
	ft_printf("%s%c\n", op, s1->name);
}
