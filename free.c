/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:14:01 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 10:32:35 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*ptr;
	t_list	*p;

	ptr = *stack;
	if (ptr != NULL)
		p = ptr->next;
	if (ptr != NULL)
	{
		while (ptr != NULL)
		{
			free(ptr);
			ptr = p;
			if (ptr != NULL)
				p = p->next;
		}
	}
}


void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	free(stack_a);
	if (stack_b)
		free_stack(stack_b);
	free(stack_b);
}

void	ft_perror(const char *str, int num)
{
	if (str)
	{
		while (*str)
		{
			write(2, str, 1);
			str++;
		}
	}
	exit(num);
}

void	free_free(int *arr)
{
	free(arr);
	ft_perror("Error\n", 6);
}
