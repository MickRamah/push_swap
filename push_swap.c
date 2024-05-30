/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:00:41 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/30 16:55:52 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	affichage(t_list *a);

static void	ft_free_stash(t_list **a);

void	push_swap(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return ;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		argv = argv + 1;
	ft_init_stash(argc, argv, &a);
	affichage(a);
	if (ft_sorted_stash(a) == 0)
	{
		if (ft_stash_len(a) == 2)
			sa(a, 1);
		else if (ft_stash_len(a) == 3)
			ft_sorted_3_nb(&a);
		else
			ft_sorted_multiple_nbs(&a, &b);
	}
	affichage(a);
	ft_free_stash(&a);
}

static void	ft_free_stash(t_list **a)
{
	t_list	*current; 
	t_list	*tmp;

	current = *a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

static void	affichage(t_list *a)
{
	t_list	*last;

	last = ft_get_last_list(a);
	printf("----------------------------------\n");
	printf("(%p) ->", a->prev);
	while (a)
	{
		printf("%d -> ", a->content);
		a = a->next;
	}
	printf("(%p) \n", a);
	printf("(%p) -> ", last->next);
	while (last)
	{
		printf("%d ->", last->content);
		last = last->prev;
	}
	printf("(%p)\n", a);
	printf("----------------------------------\n");
	
}