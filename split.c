/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:15:11 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 01:15:12 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	char_counter(const char *str, char c)
{
	size_t	counter;

	counter = 0;
	while (str[counter] && str[counter] != c)
	{
		counter++;
	}
	return (counter);
}

static char	*str_cut(const char *s, size_t i)
{
	char	*str;
	size_t	j;

	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static int	words_count(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == c)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

static char	**my_copying(char **str, char *p, char c, int words_number)
{
	int		i;
	size_t	length;

	i = 0;
	while (i < words_number)
	{
		while (*p == c && *p)
			p++;
		if (*p && *p != c)
		{
			length = char_counter(p, c);
			str[i] = str_cut(p, length);
			if (!str[i])
			{
				while (i > 0)
					free(str[--i]);
				free(str);
				return (NULL);
			}
			i++;
			p += length;
		}
	}
	return (str);
}

char	**ft_split(const char *s, char c)
{
	char	*ptr;
	int		words_number;
	char	**str;

	if (!s)
		return (NULL);
	ptr = ft_strdup(s);
	if (!ptr)
		return (NULL);
	words_number = words_count(ptr, c);
	str = (char **)malloc((words_number + 1) * sizeof(char *));
	if (!str)
	{
		free(ptr);
		return (NULL);
	}
	if (!my_copying(str, ptr, c, words_number))
	{
		free(ptr);
		return (NULL);
	}
	str[words_number] = NULL;
	free(ptr);
	return (str);
}
