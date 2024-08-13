/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-ouar <nel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 01:14:28 by nel-ouar          #+#    #+#             */
/*   Updated: 2024/08/13 10:56:48 by nel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

t_list				*create_new_node(int value);
void				assign_indices(t_list **stack_a, int *arr, int len);
void				apply_indices(t_list **stack_a, int *arr, int len);
t_list				**push_elements_to_stack(int *arr, int total);
int					search_element(int *arr, int size, int data);
void				sort_big_numbers(t_list **a);
void				sort_stack_b_elements(t_list **a, t_list **b);
void				distribute_elements_to_stack_b(t_list **a, t_list **b,
						int *arr, int size);
int					*sort_integer_array(int *arr, int size);
int					*convert_stack_to_array(t_list *a, int size);
void				move_min_elements(t_list **stack_a, t_list **stack_b);
int					sort_2(t_list **stack_a);
void				sort_3(t_list **a);
int					sort_4(t_list **stack_a, t_list **stack_b);
// int					sort_5(t_list **stack_a, t_list **stack_b);
void				perform_sorting(t_list **a, t_list **b);
void				ft_t_stack_clear(t_list **a);
char				*ft_strdup(const char *s);
int					ft_push(t_list **from_stack, t_list **to_stack);
void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);
int					ft_reverse_rotate(t_list **stack);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rrr(t_list **stack_a, t_list **stack_b);
int					ft_rotate(t_list **stack);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
int					get_stack_size(t_list *a);
void				push_with_rotation(t_list **a, t_list **b, int *n);
int					update_index(t_list **stack_a);
int					stack_sorted(t_list **stack);
void				sa(t_list **stack_a);
void				free_split(char **res, int j);
void				ft_free(t_list **stack_a, t_list **stack_b);
void				ft_perror(const char *str, int num);
void				free_free(int *arr);
void				free_stack(t_list **stack);
void				free_stacks(t_list **stack_a, t_list **stack_b);
int					validate_number_string(const char *str);
int					count_total_numbers(int ac, char *av[]);
int					*validate_and_parse_arguments(int ac, char *av[],
						int total);
void				split_and_store(char *str, int i, int *arr);
int					convert_to_int(const char *str, int *arr);
void				perform_comparison(int *arr, int len);
int					should_swap(t_list *a, t_list *b);
int					min_element(t_list *stack_a);
int					max_element(t_list *stack_a);
int					find_position(t_list *stack_a, int value);
int					check_if_sorted(t_list **stack_a);
char				**ft_split(const char *s, char c);

int					count_numbers(const char *str);
int					is_valid_char(char c);
int					validate_characters(const char *str);
void	sort_5(t_list **a);

void	ft_t_stack_clear(t_list **a);

#endif
