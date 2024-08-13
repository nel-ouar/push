/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:14:55 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 01:14:56 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_b_elements(t_list **a, t_list **b)
{
	int	max;
	int	pos;

	if (*b == NULL)
		return ;
	while (*b != NULL)
	{
		max = max_element(*b);
		pos = find_position(*b, max);
		if (pos == 0)
			pa(a, b);
		else if (pos > (get_stack_size(*b) / 2))
		{
			while ((*b)->value != max)
				rrb(b);
			pa(a, b);
		}
		else
		{
			while ((*b)->value != max)
				rb(b);
			pa(a, b);
		}
	}
}

void	distribute_elements_to_stack_b(t_list **a, t_list **b, int *arr,
		int size)
{
	int	count;
	int	index;
	int	range_limit;

	count = 0;
	if (*a == NULL)
		return ;
	if (size > 5 && size <= 100)
		range_limit = 15;
	else
		range_limit = 35;
	while (*a != NULL)
	{
		index = search_element(arr, size, (*a)->value);
		if (index < count)
			push_with_rotation(a, b, &count);
		else if (index <= (count + range_limit))
		{
			pb(a, b);
			count++;
		}
		else
			ra(a);
	}
}

int	*sort_integer_array(int *arr, int size)
{
	int	outer_idx;
	int	inner_idx;
	int	temp_value;

	outer_idx = 0;
	while (outer_idx < size)
	{
		inner_idx = outer_idx + 1;
		while (inner_idx < size)
		{
			if (arr[outer_idx] > arr[inner_idx])
			{
				temp_value = arr[outer_idx];
				arr[outer_idx] = arr[inner_idx];
				arr[inner_idx] = temp_value;
			}
			inner_idx++;
		}
		outer_idx++;
	}
	return (arr);
}

int	*convert_stack_to_array(t_list *a, int size)
{
	int		*arr;
	t_list	*current;
	int		i;

	arr = (int *)malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);
	current = a;
	i = 0;
	while (current != NULL)
	{
		arr[i] = current->value;
		current = current->next;
		i++;
	}
	return (arr);
}

void	sort_big_numbers(t_list **a)
{
	t_list	*b;
	int		size;
	int		*arr;

	b = NULL;
	size = get_stack_size(*a);
	arr = convert_stack_to_array(*a, size);
	arr = sort_integer_array(arr, size);
	distribute_elements_to_stack_b(a, &b, arr, size);
	sort_stack_b_elements(a, &b);
	free(arr);
	ft_t_stack_clear(&b);
}
