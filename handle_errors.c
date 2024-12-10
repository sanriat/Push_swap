/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-25 21:02:20 by damoncad          #+#    #+#             */
/*   Updated: 2024-07-25 21:02:20 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i + 1] == '\0' || !ft_isdigit(str[i + 1]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_duplicate(char **argv, char *current_arg, int current_index)
{
	int	i;

	i = 1;
	while (i < current_index)
	{
		if (strcmp(argv[i], current_arg) == 0)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
