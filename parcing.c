/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:14:19 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 10:19:06 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_number_string(const char *str)
{
	int	count;

	if (!validate_characters(str))
	{
		ft_perror("Error\n", 6);
	}
	count = count_numbers(str);
	if (count == 0)
	{
		ft_perror("Error\n", 6);
	}
	return (count);
}

int	count_total_numbers(int ac, char *av[])
{
	int	i;
	int	total;

	i = 1;
	total = 0;
	while (i < ac)
	{
		total += validate_number_string(av[i]);
		i++;
	}
	return (total);
}

void	split_and_store(char *str, int i, int *arr)
{
	char	**res;
	int		j;

	j = 0;
	res = ft_split(str, ' ');
	j = 0;
	while (res[j])
	{
		arr[i] = convert_to_int(res[j], arr);
		i++;
		j++;
	}
	free_split(res, j);
}

int	*validate_and_parse_arguments(int ac, char *av[], int total)
{
	int	i;
	int	j;
	int	num;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * total);
	i = 1;
	j = 0;
	while (i < ac)
	{
		num = validate_number_string(av[i]);
		if (num == 1)
			arr[j] = convert_to_int(av[i], arr);
		else
		{
			split_and_store(av[i], j, arr);
		}
		i++;
		j += num;
	}
	perform_comparison(arr, total);
	return (arr);
}

t_list	**push_elements_to_stack(int *arr, int total)
{
	t_list	**stack;
	t_list	*current_node;
	t_list	*new_node;
	int		index;

	stack = malloc(total * sizeof(t_list *));
	if (stack == NULL)
	{
		free(arr);
		exit(1);
	}
	current_node = NULL;
	index = total - 1;
	while (index >= 0)
	{
		new_node = create_new_node(arr[index]);
		new_node->next = current_node;
		current_node = new_node;
		stack[index--] = current_node;
	}
	assign_indices(stack, arr, total);
	free(arr);
	return (stack);
}
