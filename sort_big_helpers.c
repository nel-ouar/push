/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:14:49 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 10:58:03 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_list *a)
{
	int		count;
	t_list	*current;

	if (!a)
		return (0);
	count = 0;
	current = a;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void	push_with_rotation(t_list **a, t_list **b, int *n)
{
	pb(a, b);
	rb(b);
	(*n)++;
}

int	max_element(t_list *stack_a)
{
	t_list	*current;
	int		max;

	if (stack_a == NULL)
		return (-1);
	max = stack_a->value;
	current = stack_a->next;
	while (current != NULL)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	search_element(int *arr, int size, int data)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] != data)
			i++;
		else
			break ;
	}
	return (i);
}

// void	ft_t_stack_clear(t_list **a)
// {
// 	t_list	*temp;

// 	if (a == NULL)
// 		return ;
// 	while (*a != NULL)
// 	{
// 		temp = (*a)->next;
// 		free(*a);
// 		(*a) = temp;
// 	}
// }
