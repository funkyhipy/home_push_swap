/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	stack_init(t_stack	*s, int n_tot, char name)
{
	s->name = name;
	s->nbr = 0;
	s->n_tot = n_tot;
	s->v = ft_calloc(n_tot, sizeof(int));
	if (!s->v)
		return (0);
	return (1);
}

void	stack_add_back(t_stack *s, int new_val)
{
	if (s->nbr == s->n_tot)
		return ;
	s->v[s->nbr] = new_val;
	s->nbr++;
}

int	get_e(const t_stack *s, int pos)
{
	int	idx;

	if (pos >= s->nbr)
		return (0);
	while (pos < 0)
		pos += s->nbr;
	idx = (s->nbr - pos - 1) % s->nbr;
	return (s->v[idx]);
}

void	clear_stacks(t_stack *a, t_stack *b)
{
	if (a->v)
		free(a->v);
	if (b->v)
		free(b->v);
}
