/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_algorithm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p@student.42urduliz.com <marvi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:06:11 by acampo-p@         #+#    #+#             */
/*   Updated: 2024/10/07 13:07:47 by acampo-p@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotuntilordered(t_stack *s)
{
	int	i;

	i = 0;
	s->min = ft_min(s->arr, s->len);
	while (s->arr[i] != s->min)
		i++;
	if (i <= s->len - i)
	{
		while (i-- > 0)
			ft_rot(s, 1);
	}
	else
	{
		while (ft_abs(s->len - i) > 0)
		{
			ft_rrot(s, 1);
			i++;
		}
	}
}

void	ft_order3elarray(t_stack *s)
{
	if (s->len != 3)
		return ;
	s->min = ft_min(s->arr, s->len);
	s->max = ft_max(s->arr, s->len);
	if (s->name == 'a')
	{
		while (s->arr[0] != s->min)
			ft_rot(s, 1);
		if (s->arr[0] > s->arr[1] || s->arr[1] > s->arr[2])
			ft_swap(s);
	}
	if (s->name == 'b')
	{
		while (s->arr[0] != s->max)
			ft_rot(s, 1);
		if (s->arr[0] < s->arr[1] || s->arr[1] < s->arr[2])
			ft_swap(s);
	}
}

void	ft_buildinstructions(t_stack *a, t_stack *b)
{
	t_ops	ops;

	while (b->len < 3 && a->len > 3)
		ft_push(a, b);
	ft_order3elarray(b);
	while (a->len > 3)
	{
		ft_calcrotations(a, b, &ops);
		ft_doops(a, b, &ops);
		b->min = ft_min(b->arr, b->len);
		b->max = ft_max(b->arr, b->len);
	}
	ft_order3elarray(a);
	while (b->len > 0)
	{
		ft_calcrotations(b, a, &ops);
		ft_doops(b, a, &ops);
		a->min = ft_min(a->arr, a->len);
		a->max = ft_max(a->arr, a->len);
	}
	ft_rotuntilordered(a);
}
