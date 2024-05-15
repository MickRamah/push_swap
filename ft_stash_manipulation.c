/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stash_manipulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:12:10 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/15 16:37:35 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_test_and_stash(int argc, t_list **a, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	while (argv[i])
	{
		if (ft_syntax_error(argv[i]))
			ft_free_and_exit(a, argv, argc);
		nb = ft_atoi(argv[i]);
		if (ft_stash_and_check_repetition(a, nb))
			ft_free_and_exit(a, argv, argc);
		i++;
	}
	if (argc == 2)
	{
		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
	}
}

int	stash_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_stash_len(t_list *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

void	ft_free_stash(t_list *a)
{
	t_list	*current;
	t_list	*tmp;

	current = a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
}

t_list	*ft_get_last_list(t_list *stash)
{
	t_list	*last;

	last = stash;
	while (last->next)
		last = last->next;
	return (last);
}
