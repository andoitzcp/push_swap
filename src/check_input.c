/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p@student.42urduliz.com <marvi      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:21:28 by acampo-p@         #+#    #+#             */
/*   Updated: 2024/10/07 12:24:07 by acampo-p@        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_returnwitherror(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

char	*ft_leftpadstr(char *s, int size)
{
	char	*lps;
	char	*tmp;

	lps = malloc(size + 1);
	if (!lps)
		exit(1);
	lps[size] = '\0';
	tmp = s;
	while (*tmp != '\0')
		tmp++;
	while (tmp-- > s)
	{
		size--;
		lps[size] = *tmp;
	}
	while (size-- > 0)
		lps[size] = '0';
	return (lps);
}

int	ft_isinteger(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]) && s[i] != '-' && s[i] != '+')
			ft_returnwitherror();
		i++;
	}
	if (*s == '-' || *s == '+')
		s++;
	if (ft_strlen(s) > 10)
		ft_returnwitherror();
	if (ft_strncmp(INT_MAX_STR, s, 10) < 0 && ft_strlen(s) == 10)
		ft_returnwitherror();
	return (1);
}

int	ft_isrepeated(char **array, char *s)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
	{
		if (ft_strncmp(array[i], s, 11) == 0)
			ft_returnwitherror();
		i++;
	}
	return (0);
}

int	ft_check_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_isinteger(argv[i]) == 0)
			return (0);
		if (ft_isrepeated(argv + i + 1, argv[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}
