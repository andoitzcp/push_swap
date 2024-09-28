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

typedef struct s_instr
{
	char bufr[BUFR_LEN];
	struct s_instr *next;
} t_instr;

// Debugging
void ft_printstack(t_stack *stack);

// Operations
void ft_swap(t_stack *stack);
void ft_push(t_stack *src, t_stack *dst);
void ft_rot(t_stack *stack);
void ft_rrot(t_stack *stack);

// Algorithm
void ft_buildinstructions(t_stack *a, t_stack *b);


#endif
