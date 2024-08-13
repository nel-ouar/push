/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:13:36 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 10:57:13 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
}

// void	free_stacks(t_list **stack_a, t_list **stack_b)
// {
// 	t_list	*ptr;
// 	t_list	*s;

// 	ptr = *stack_a;
// 	s = ptr->next;
// 	while (ptr->next)
// 	{
// 		free(ptr);
// 		ptr = s;
// 		s = s->next;
// 	}
// 	free(ptr);
// 	free(stack_a);
// 	free(stack_b);
// }

void	ft_t_stack_clear(t_list **a)
{
	t_list	*temp;

	if (a == NULL)
		return ;
	while (*a != NULL)
	{
		temp = (*a)->next;
		free(*a);
		(*a) = temp;
	}
}
