/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:22:26 by acampo-p          #+#    #+#             */
/*   Updated: 2024/09/16 11:38:15 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include "../include/libft/libft.h"
# include "../include/ft_printf/src/ft_printf.h"

# define INT_MAX_STR "2147483647"
# define INT_MIN_STR "-2147483648"
# define BUFR_LEN 100

typedef struct s_stack
{
	char name;
    int *arr;
    int len;
    int sz;
	int min;
	int max;
} t_stack;

typedef struct s_ops
{
	int ra;
	int rb;
	int sa;
	int sb;
} t_ops;

typedef struct s_instr
{
	char bufr[BUFR_LEN];
	struct s_instr *next;
} t_instr;

// Debugging
void ft_printstack(t_stack *stack);


// Input checking
void ft_returnwitherror(void);
int ft_check_argv(int argc, char **argv);
int ft_isrepeated(char **array, char *s);
int ft_isinteger(char *s);

// Operations
void ft_swap(t_stack *stack);
void ft_push(t_stack *src, t_stack *dst);
void ft_rot(t_stack *stack, char print);
void ft_rrot(t_stack *stack, char print);
void ft_rotboth(t_stack *a, t_stack *b, char direction);

// Algorithm
void ft_buildinstructions(t_stack *a, t_stack *b);

// Calculate optimal rotations
void ft_calcrotations(t_stack *a, t_stack *b, t_ops *ops);
int ft_convtry(t_stack *b, int n);
int ft_minmaxcase(t_stack *b);
int ft_calctotops(int i, int j);

// Execute operations
void ft_doops(t_stack *a, t_stack *b, t_ops *ops);
void ft_forwardops(t_stack *a, t_stack *b, t_ops *ops);
void ft_reverseops(t_stack *a, t_stack *b, t_ops *ops);

#endif
