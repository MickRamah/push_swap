/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:00:41 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/15 16:31:23 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sorted_three_nb(t_list **a);
static void	ft_sorted_nbs(t_list **a, t_list **b);
static void	ft_sorted_five_nbs(t_list **a, t_list **b);
static void	ft_search_min_and_swap(t_list *a);

void	push_swap(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	ft_test_and_stash(argc, &a, argv);
	if (!stash_sorted(a))
	{
		if (ft_stash_len(a) == 2)
			sa(a, 1);
		else if (ft_stash_len(a) == 3)
			ft_sorted_three_nb(&a);
		else
			ft_sorted_nbs(&a, &b);
	}
	ft_free_stash(a);
}

static void	ft_sorted_three_nb(t_list **a)
{
	t_list	*current;

	current = *a;
	if (current->content > current->next->content)
	{
		if (current->content < current->next->next->content)
			sa(*a, 1);
		else if (current->next->content < current->next->next->content)
			ra(a, 1);
		else
		{
			sa(*a, 1);
			rra(a, 1);
		}
	}
	else
	{
		if (current->content < current->next->next->content)
		{
			sa(*a, 1);
			ra(a, 1);
		}
		else
			rra(a, 1);
	}
}

static void	ft_sorted_nbs(t_list **a, t_list **b)
{
	if (ft_stash_len(*a) <= 5 && ft_stash_len(*a) >= 4)
	{
		ft_sorted_five_nbs(a, b);
	}
}

static void	ft_sorted_five_nbs(t_list **a, t_list **b)
{
	if (ft_stash_len(*a) == 5)
	{
		while (ft_stash_len(*a) > 3)
		{
			ft_search_min_and_swap(*a);
			pb(a, b);
		}
		ft_sorted_three_nb(a);
		pa(b, a);
		pa(b, a);
	}
	else
	{
		while (ft_stash_len(*a) > 3)
		{
			ft_search_min_and_swap(*a);
			pb(a, b);
		}
		ft_sorted_three_nb(a);
		pa(b, a);
	}
}

static void	ft_search_min_and_swap(t_list *a)
{
	int		min;
	int		tmp;
	t_list	*pos;
	t_list	*current;

	min = a->content;
	pos = a;
	current = a->next;
	while (current)
	{
		if (min > current->content)
		{
			min = current->content;
			pos = current;
		}
		current = current->next;
	}
	tmp = a->content;
	a->content = min;
	pos->content = tmp;
}
