/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:15:15 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 01:15:16 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!*stack || (*stack)->next == NULL)
		return (-1);
	first = *stack;
	second = (*stack)->next;
	*stack = second;
	first->next = second->next;
	second->next = first;
	return (0);
}

void	sa(t_list **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
