/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:15:24 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 01:15:25 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	convert_to_int(const char *str, int *arr)
{
	int long	r;
	int			s;
	int			i;

	r = 0;
	s = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		if ((r * s > 2147483647) || (r * s < -2147483648))
			free_free(arr);
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		free_free(arr);
	return (s * r);
}

void	perform_comparison(int *arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] == arr[j])
			{
				free_free(arr);
			}
			j++;
		}
		i++;
	}
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i])
		i++;
	res = (char *)malloc(sizeof(*res) * i + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
