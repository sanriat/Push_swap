/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damoncad <damoncad@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-25 21:03:55 by damoncad          #+#    #+#             */
/*   Updated: 2024-07-25 21:03:55 by damoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **lst)
{
	t_list	*first;
	t_list	*second;

	if (!*lst || !(*lst)->next)
		return ;
	first = *lst;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
	*lst = second;
}

void	sa(t_list	**a, bool flag)
{
	swap(a);
	if (!flag)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, bool flag)
{
	swap(b);
	if (!flag)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, bool flag)
{
	swap(a);
	swap(b);
	if (!flag)
		write(1, "ss\n", 3);
}
