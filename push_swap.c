/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-25 21:09:58 by damoncad          #+#    #+#             */
/*   Updated: 2024-07-25 21:09:58 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**split_argv;

	a = NULL;
	b = NULL;
	split_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split_argv = split(argv[1], ' ');
		argv = split_argv;
	}
	if (verify(argv, split_argv))
		return (1);
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
		what_sort(&a, &b);
	free_stack(&a);
	if (split_argv != NULL)
		ft_free_split(split_argv);
	return (0);
}
