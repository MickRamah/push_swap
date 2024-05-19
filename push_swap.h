/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:58:32 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/19 15:32:18 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
#include <limits.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void	push_swap(int argc, char **argv);

char	**ft_split(char const *s, char c);

int		ft_atoi(const char *str);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	ft_test_and_stash(int argc, t_list **a, char **argv);

int		ft_syntax_error(char *argv_i);
void	ft_free_and_exit(t_list **a, char **argv, int argc);
int		ft_stash_and_check_repetition(t_list **a, int nb);
t_list	*ft_get_last_list(t_list *stash);

int		ft_stash_sorted(t_list *a);
int		ft_stash_len(t_list *a);

void	ss(t_list *a, t_list *b);
void	sa(t_list *a, int status);
void	sb(t_list *b, int status);
void	rr(t_list **a, t_list **b);
void	ra(t_list **a, int status);
void	rb(t_list **b, int status);
void	rrr(t_list **a, t_list **b);
void	rra(t_list **a, int status);
void	rrb(t_list **b, int status);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

void	ft_free_stash(t_list **a);

void    test(t_list **a, t_list **b);

void	affichage(t_list *stash);
void	tiny_sort(t_list **a);

void	ft_swap(t_list **a, t_list **b);
void	ft_trie_cinq_nb(t_list **a, t_list **b);

#endif
