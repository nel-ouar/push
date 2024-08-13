/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:14:13 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 01:27:29 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_char(char c)
{
	return (c == ' ' || c == '+' || c == '-' || (c >= '0' && c <= '9'));
}

int	validate_characters(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_valid_char(str[i]) || ((str[i] == '+' || str[i] == '-')
				&& !((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1]
					== '\0')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	count_numbers(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
		{
			i++;
		}
		if (str[i] && str[i] != ' ')
		{
			count++;
			while (str[i] && str[i] != ' ')
			{
				i++;
			}
		}
	}
	return (count);
}
