/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_stack *s)
{
	int	tmp;

	if (s->nbr < 2)
		return ;
	tmp = s->values[s->nbr - 1];
	s->values[s->nbr - 1] = s->values[s->nbr - 2];
	s->values[s->nbr - 2] = tmp;
}

void	r_rot(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->nbr < 2)
		return ;
	tmp = s->values[0];
	i = 0;
	while (i++ < s->nbr - 1)
		s->values[i - 1] = s->values[i];
	s->values[s->nbr - 1] = tmp;
}

void	rot(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->nbr < 2)
		return ;
	tmp = s->values[s->nbr - 1];
	i = s->nbr;
	while (i--)
		s->values[i] = s->values[i - 1];
	s->values[0] = tmp;
}

void	push(t_stack *dest, t_stack *src)
{
	if (src->nbr < 1)
		return ;
	dest->values[dest->nbr] = src->values[src->nbr - 1];
	dest->nbr++;
	src->nbr--;
}
