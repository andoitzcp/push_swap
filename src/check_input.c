/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                   :+:    :+: :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p@student.42urduliz.com <marvi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:21:28 by acampo-p@         #+#    #+#             */
/*   Updated: 2024/10/24 14:40:04 by andoitzcp   ########  ###                */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_returnwitherror(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_isbtwnlimits(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (*s == '-')
	{
		if (len > 11)
			ft_returnwitherror();
		if (ft_strncmp(INT_MIN_STR, s, 11) < 0 && len == 11)
			ft_returnwitherror();
	}
	else
	{
		if (*s == '+')
			s++;
		if (ft_strlen(s) > 10)
			ft_returnwitherror();
		if (ft_strncmp(INT_MAX_STR, s, 10) < 0 && ft_strlen(s) == 10)
			ft_returnwitherror();
	}
	return (1);
}

int	ft_isinteger(char *s)
{
	int	i;

	if (*s == '\0')
		ft_returnwitherror();
	i = 0;
	if (*s == '+' || *s == '-')
		i++;
	if (s[i] == '\0')
		ft_returnwitherror();
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			ft_returnwitherror();
		i++;
	}
	ft_isbtwnlimits(s);
	return (1);
}

int	ft_isrepeated(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->arr[i] == stack->arr[j])
				ft_returnwitherror();
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_argv(int argc, char **argv)
{
	int		i;
	t_stack	stack;

	i = 0;
	while (++i < argc)
	{
		if (ft_isinteger(argv[i]) == 0)
			return (0);
	}
	i = 0;
	ft_buildstack(&stack, argc, argv, 'a');
	if (ft_isrepeated(&stack) == 1)
	{
		free(stack.arr);
		return (0);
	}
	free(stack.arr);
	return (1);
}
