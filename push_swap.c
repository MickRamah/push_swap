/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:00:41 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/19 15:32:46 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_highest(t_list *stack);

void	push_swap(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*current;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (argc == 2)
		argv = ft_split(argv[1], ' '); // malloc
	else
		argv = argv + 1;
	ft_test_and_stash(argc, &a, argv);

	// /*--------------------test--------------------*/
	// test(&a, &b);
	// /*--------------------test--------------------*/

	if (!ft_stash_sorted(a))
	{
		if (ft_stash_len(a) == 2)
			sa(a, 1);
		else if (ft_stash_len(a) == 3)
			tiny_sort(&a);
		else
			ft_swap(&a, &b);
			
	}
	affichage(a);
	ft_free_stash(&a);
}








































static t_list	*find_highest(t_list *stack)
{
	int				highest;
	t_list	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->content > highest)
		{
			highest = stack->content;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	tiny_sort(t_list **a)
{
	t_list	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		ra(a, 1);
	else if ((*a)->next == highest_node)
		rra(a, 1);
	if ((*a)->content > (*a)->next->content)
		sa(*a, 1);
}

// static void	ft_sorted_three_nb(t_list **a)
// {
// 	t_list	*current;
// 	t_list	*last;
	
// 	current = *a;
// 	last = ft_get_last_list(*a);
// 	if (current->content < last->prev->content)
// 	{
// 		if (current->content < last->content) // 1 3 2
// 		{
// 			sa(*a, 1);
// 			ra(a, 1);
// 		}
// 		else if (current->content > last->content) // 2 3 1
// 			rra(a, 1);	
// 	}
// 	else if (current->content > last->prev->content)
// 	{
// 		if (current->content < last->content) // 2 1 3
// 			sa(*a, 1);
// 		else
// 		{
// 			if (last->prev->content > last->content) // 3 2 1
// 			{
// 				sa(*a, 1);
// 				rra(a, 1);
// 			}
// 			else if (last->prev->content < last->content) // 3 1 2
// 				ra(a, 1);
// 		}
// 	}
// }

void	affichage(t_list *stash)
{
	printf("------------------------------------------------\n");
	printf("stash(tete): ");
	while (stash)
	{
		printf("%d ", stash->content);
		stash = stash->next;
	}
	printf("\n");
	printf("------------------------------------------------\n");
}