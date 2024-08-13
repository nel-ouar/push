/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:14:33 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 01:14:34 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push(t_list **from_stack, t_list **to_stack)
{
	t_list	*temp;

	if (!*from_stack)
		return (-1);
	temp = *from_stack;
	*from_stack = (*from_stack)->next;
	temp->next = *to_stack;
	*to_stack = temp;
	return (0);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
