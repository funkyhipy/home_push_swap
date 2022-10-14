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

#include "libft.h"
#include "push_swap.h"

void	swap(t_stack *s)
{
	int	tmp;

	if (s->nbr < 2)
		return ;
	tmp = s->v[s->nbr - 1];
	s->v[s->nbr - 1] = s->v[s->nbr - 2];
	s->v[s->nbr - 2] = tmp;
}

void	r_rot(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->nbr < 2)
		return ;
	tmp = s->v[0];
	i = 0;
	while (i++ < s->nbr - 1)
		s->v[i - 1] = s->v[i];
	s->v[s->nbr - 1] = tmp;
}

void	rot(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->nbr < 2)
		return ;
	tmp = s->v[s->nbr - 1];
	i = s->nbr;
	while (i--)
		s->v[i] = s->v[i - 1];
	s->v[0] = tmp;
}

void	push(t_stack *dest, t_stack *src)
{
	if (src->nbr < 1)
		return ;
	dest->v[dest->nbr] = src->v[src->nbr - 1];
	dest->nbr++;
	src->nbr--;
}
