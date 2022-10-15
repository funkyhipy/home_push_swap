/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:16:11 by gmontaur          #+#    #+#             */
/*   Updated: 2022/10/14 14:16:34 by gmontaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <libft.h>
# include <ft_printf.h>

# define SORT_ASCENDING 1
# define SORT_DESCENDING 0

# define STACK_A 'a'
# define STACK_B 'b'

# define OP_PUSH "p"
# define OP_SWAP "s"
# define OP_SWAP_BOTH "ss"
# define OP_ROT "r"
# define OP_ROT_BOTH "rb"
# define OP_R_ROT "rr"
# define OP_R_ROT_BOTH "brr"

typedef struct s_stack
{
	int				nbr;
	int				n_tot;
	int				*v;
	char			name;
}	t_stack;

int		parse_str(const char *arg, t_stack *s);
int		parse_args(int argc, char *args[], t_stack *s);
int		check_data(t_stack *s);
void	clear_stacks(t_stack *a, t_stack *b);

int		stack_init(t_stack *stack, int n_args, char name);
void	stack_add_back(t_stack *stack, int new_val);
int		get_e(const t_stack *s, int pos);

char	is_sorted(const t_stack *s, char ascending);
void	sort(t_stack *a, t_stack *b);
void	small_sort(t_stack *s1, t_stack *s2);
void	print_stack(t_stack	*a, t_stack *b);

int		n_op_rotate_to_top(t_stack *s, int idx);
void	rotate_to_top(t_stack *s, int idx);
int		find_min_value(const t_stack *s, int above);
int		find_max_value(const t_stack *s, int under);

void	do_op(const char *op, t_stack *s_a, t_stack *s_b);
void	swap(t_stack *s);
void	rot(t_stack *s);
void	r_rot(t_stack *s);
void	push(t_stack *dest, t_stack *src);

#endif // !PUSH_SWAP_H
