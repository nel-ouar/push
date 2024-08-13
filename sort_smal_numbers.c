/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smal_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:15:06 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 10:56:25 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_2(t_list **stack_a)
{
	if (should_swap(*stack_a, (*stack_a)->next))
	{
		sa(stack_a);
		return (1);
	}
	return (0);
}

void	sort_3(t_list **a)
{
	if (stack_sorted(a) == 1)
		return ;
	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
	{
		ra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
		sa(a);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		rra(a);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
	{
		rra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
}

int	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	min;

	if (stack_sorted(stack_a))
		return (0);
	*stack_b = NULL;
	min = min_element(*stack_a);
	while ((*stack_a)->value != min)
	{
		if (find_position(*stack_a, min) >= 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	if (update_index(stack_a) )
		return (0);
	return (1);
}

// int	sort_5(t_list **stack_a, t_list **stack_b)
// {
// 	move_min_elements(stack_a, stack_b);
// 	move_min_elements(stack_a, stack_b);
// 	// sort_4(stack_a, stack_b);
// 	sort_3(stack_a);
// 	pa(stack_a, stack_b);
// 	pa(stack_a, stack_b);
// 	if (update_index(stack_a) == 1)
// 		return (0);
// 	return (1);
// }
void	sort_5(t_list **a)
{
	t_list	*b;
	int		min;

	b = NULL;
	min = min_element(*a);
	while ((*a)->value != min)
	{
		if (find_position(*a, min) >= 2)
			rra(a);
		else
			ra(a);
	}
	pb(a, &b);
	sort_4(a, &b);
	pa(a, &b);
	ft_t_stack_clear(&b);
}

void	perform_sorting(t_list **a, t_list **b)
{
	int	size;

	size = get_stack_size(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a);
	else if (size <= 100 && size > 5)
		sort_big_numbers(a);
	else if (size > 100)
		sort_big_numbers(a);
}
