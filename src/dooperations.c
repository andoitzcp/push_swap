/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dooperations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p@student.42urduliz.com <marvi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:10:25 by acampo-p@         #+#    #+#             */
/*   Updated: 2024/10/07 13:10:51 by acampo-p@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_forwardops(t_stack *a, t_stack *b, t_ops *ops)
{
	int	i;

	i = 0;
	while (i < ops->ra && i < ops->rb)
	{
		ft_rotboth(a, b, 'f');
		i++;
	}
	while (i < ops->ra)
	{
		ft_rot(a, 1);
		i++;
	}
	while (i < ops->rb)
	{
		ft_rot(b, 1);
		i++;
	}
}

void	ft_reverseops(t_stack *a, t_stack *b, t_ops *ops)
{
	int	i;

	i = 0;
	while (i > ops->ra && i > ops->rb)
	{
		ft_rotboth(a, b, 'r');
		i--;
	}
	while (i > ops->ra)
	{
		ft_rrot(a, 1);
		i--;
	}
	while (i > ops->rb)
	{
		ft_rrot(b, 1);
		i--;
	}
}

void	ft_doops(t_stack *a, t_stack *b, t_ops *ops)
{
	ft_forwardops(a, b, ops);
	ft_reverseops(a, b, ops);
	ft_push(a, b);
}
