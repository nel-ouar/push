/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:15:19 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 10:19:43 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		exit(1);
	}
	node->value = value;
	node->next = NULL;
	return (node);
}

void	assign_indices(t_list **stack_a, int *arr, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	apply_indices(stack_a, arr, len);
}

void	apply_indices(t_list **stack_a, int *arr, int len)
{
	t_list	*ptr;
	int		i;

	ptr = *stack_a;
	while (ptr != NULL)
	{
		i = 0;
		while (i < len)
		{
			if (arr[i] == ptr->value)
			{
				ptr->index = i;
				break ;
			}
			i++;
		}
		ptr = ptr->next;
	}
}

int	check_if_sorted(t_list **stack_a)
{
	t_list	*ptr;

	ptr = *stack_a;
	if (ptr == NULL || ptr->next == NULL)
		return (0);
	while (ptr != NULL)
	{
		if (ptr->next && (ptr->index > ptr->next->index))
			return (-1);
		ptr = ptr->next;
	}
	return (0);
}

int	stack_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
