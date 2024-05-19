/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:00:25 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/19 15:22:05 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_repetition(t_list *a, int nb);

int	ft_syntax_error(char *argv_i)
{
	int	j;

	j = 0;
	if (!(argv_i[j] == '+' || argv_i[j] == '-'
			|| (argv_i[j] >= '0' && argv_i[j] <= '9')))
		return (1);
	if (argv_i[j] == '+' || argv_i[j] == '-')
		j++;
	while ((argv_i[j] >= '0' && argv_i[j] <= '9') && argv_i[j])
		j++;
	if ((argv_i[j - 1] == '+' || argv_i[j - 1] == '-') && !argv_i[j])
		return (1);
	if (!argv_i[j])
		return (0);
	return (1);
}

void	ft_free_and_exit(t_list **a, char **argv, int argc)
{
	t_list	*current;
	t_list	*tmp;
	int		i;

	i = 0;
	current = *a;
	if (argc == 2)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*a = NULL;
	write(1, "error\n", 6);
	exit(1);
}

int	ft_stash_and_check_repetition(t_list **a, int nb)
{
	t_list	*new;
	t_list	*last;

	if (ft_check_repetition(*a, nb))
		return (1);
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (1);
	new->content = nb;
	new->next = NULL;
	if (*a == NULL)
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_get_last_list(*a);
		last->next = new;
		new->prev = last;
	}
	return (0);
}

static int	ft_check_repetition(t_list *a, int nb)
{
	while (a)
	{
		if (a->content == nb)
			return (1);
		a = a->next;
	}
	return (0);
}
