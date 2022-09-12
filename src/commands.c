/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:42:14 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/12 09:21:16 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(node_list **stack_list, char type)
{
	node_list	*first;
	node_list	*second;
	node_list	*third;

	first = *stack_list;
	second = (*stack_list)->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack_list = second;
	if (type == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

void	push(node_list **stack_a, node_list **stack_b, char type)
{
	node_list	*temp_sender;

	if (type == 'a')
	{
		temp_sender = (*stack_b)->next;
		insert_first_node(stack_a, *stack_b);
		*stack_b = temp_sender;
		ft_printf("pa\n");
	}
	else if (type == 'b')
	{
		temp_sender = (*stack_a)->next;
		insert_first_node(stack_b, *stack_a);
		*stack_a = temp_sender;
		ft_printf("pb\n");
	}
}

node_list	*get_last(node_list *stack)
{
	node_list	*current;

	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	rotate(node_list **stack, char type, int len)
{
	node_list	*first;
	node_list	*second;
	node_list	*last;

	if (len > 1)
	{
		second = (*stack)->next;
		first = *stack;
		first->next = NULL;
		last = get_last(second);
		last->next = first;
		*stack = second;
		if (type == 'b')
			ft_printf("rb\n");
		else if (type == 'a')
			ft_printf("ra\n");
	}
	else
		return ;
}

void	reverse_rotate(node_list **stack, char type, int len)
{
	node_list	*prev;
	node_list	*last;
	node_list	*first;

	if (len > 1)
	{
		first = *stack;
		last = *stack;
		while (last->next != NULL)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = first;
		*stack = last;
		if (type == 'b')
			ft_printf("rrb\n");
		else if (type == 'a')
			ft_printf("rra\n");
	}
	else
		return ;
}
