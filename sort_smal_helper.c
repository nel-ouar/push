/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smal_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:15:01 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 10:35:32 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	should_swap(t_list *a, t_list *b)
{
	return (a->value > b->value);
}

int	min_element(t_list *stack_a)
{
	t_list	*current;
	int		min;

	if (stack_a == NULL)
		return (-1);
	min = stack_a->value;
	current = stack_a->next;
	while (current != NULL)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	update_index(t_list **stack_a)
{
	t_list	*current;
	int		index;

	if (*stack_a == NULL)
		return (1);
	current = *stack_a;
	index = 0;
	while (current != NULL)
	{
		current->index = index;
		current = current->next;
		++index;
	}
	return (0);
}

int	find_position(t_list *stack_a, int value)
{
	int	pos;

	pos = 0;
	while (stack_a != NULL)
	{
		if (stack_a->value == value)
			return (pos);
		stack_a = stack_a->next;
		pos++;
	}
	return (-1);
}

void	move_min_elements(t_list **stack_a, t_list **stack_b)
{
	int	min;

	*stack_b = NULL;
	min = min_element(*stack_a);
	while ((*stack_a)->value != min)
	{
		if (find_position(*stack_a, min) >= 3)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
}
