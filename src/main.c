/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acampo-p <acampo-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 22:27:50 by acampo-p          #+#    #+#             */
/*   Updated: 2023/05/28 23:24:37 by acampo-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

snode	*ft_appendnode(snode *head, snode *tmp, snode *node);
{
	if (!head)
		head = node;
	else
		tmp->next = node;
	return (head);
}

snode	*ft_constructnode(*argv)
{
	snode	*node;
	size_t	i;

	node = malloc(sizeof(snode));
	if (!node)
		return(NULL);
	i = ft_atoi(*argv);
	node->i = i;
	node->next = NULL;
	return (node);
}

snode	*ft_constructllist(int argc, char **argv)
{
	snode	*head;
	snode	*tmp;

	head = NULL;
	tmp = head;
	while (argc-- > 0)
	{
		node = ft_constructnode(*argv);
		if (!node)
			return (NULL);
		head = ft_appendnode(node, tmp);
		tmp = node;
		argv++;
	}
	return (head);
}

int	main (int argc, char **argv)
{
	snode	*head;

	head = ft_constructllist(argc, argv);
	if (!head)
		return (1);
	ft_printllist(head);
	return(0);
}
