/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:54 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/14 21:49:53 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	check_order_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	temp = *stack_b;
	while (temp->next != NULL)
	{
		if (temp->value > (temp->next)->value)
			temp = temp->next;
		else
			return (0);
	}
	while (*stack_b != NULL)
		push(stack_a, stack_b, 'a');
	return (1);
}

int	check_order_a(t_node **stack_a)
{
	t_node	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (temp->value < (temp->next)->value)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	dup_or_ordened(t_node **stack_a, t_node **stack_b, char **split)
{
	t_node	*temp;
	t_node	*next;

	temp = *stack_a;
	next = (*stack_a)->next;
	while (temp->next != NULL)
	{
		while (next)
		{
			if (temp->value != next->value)
				next = next->next;
			else
				free_and_error(stack_a, stack_b, split);
		}
		temp = temp->next;
		next = temp->next;
	}
	if (check_order_a(stack_a) == 1)
	{
		free_all(stack_a, stack_b, split);
		exit(EXIT_FAILURE);
	}
}

void	free_and_error(t_node **a, t_node **b, char **splitted)
{
	free_all(a, b, splitted);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_all(t_node **stack_a, t_node **stack_b, char **splitted)
{
	t_node		*next;
	int			i;

	while (*stack_a)
	{
		next = (*stack_a)->next;
		free(*stack_a);
		*stack_a = next;
	}
	free(stack_a);
	while (*stack_b)
	{
		next = (*stack_b)->next;
		free(*stack_b);
		*stack_b = next;
	}
	free(stack_b);
	if (splitted)
	{
		i = 0;
		while (splitted[i])
			free(splitted[i++]);
		free(splitted);
	}
}
