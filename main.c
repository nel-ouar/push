/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:14:06 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 01:14:07 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		*arr;
	int		total;

	if (ac < 2)
		return (0);
	total = count_total_numbers(ac, av);
	arr = validate_and_parse_arguments(ac, av, total);
	stack_a = push_elements_to_stack(arr, total);
	stack_b = malloc(sizeof(t_list *));
	(*stack_b) = NULL;
	if (check_if_sorted(stack_a) == -1)
		perform_sorting(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
}
