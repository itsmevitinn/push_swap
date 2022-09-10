/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:53:22 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/10 19:29:29 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	send_to_b(node_list **stack_a, node_list **stack_b, int pos, int len)
{
	int	half;

	half = len / 2;
	while (pos <= half)
	{
		if (pos == 1)
		{
			push(stack_a, stack_b, 'b');
			break ;
		}
		rotate(stack_a, 'a', len);
		pos--;
	}
	while (pos > half)
	{
		if (pos == len)
		{
			reverse_rotate(stack_a, 'a', len);
			push(stack_a, stack_b, 'b');
			break ;
		}
		reverse_rotate(stack_a, 'a', len);
		pos++;
	}
}

int	count_len(node_list **stack)
{
	node_list	*temp;
	int			len;

	temp = *stack;
	len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int	find_position(node_list **stack, char type)
{
	node_list	*temp;
	int			position;
	int			value;

	if (type == 'o')
		value = pick_second_highest(stack);
	else
		value = pick_value(stack, type);
	temp = *stack;
	position = 0;
	while (temp)
	{
		if (temp->value == value)
		{
			position++;
			break ;
		}
		position++;
		temp = temp->next;
	}
	return (position);
}

void	insert_last_node(node_list **stack, int value)
{
	node_list	*new_node;
	node_list	*last;

	new_node = malloc(sizeof(node_list));
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last = *stack;
	last = get_last(last);
	last->next = new_node;
}

int	get_highest_bit(node_list **stack)
{
	node_list	*temp;
	int			highest;
	int			bits;

	bits = 0;
	temp = *stack;
	highest = -2147483648;
	while (temp != NULL)
	{
		if (highest < temp->value)
			highest = temp->value;
		temp = temp->next;
	}
	while (highest >> bits != 0)
		bits++;
	return (bits);
}
