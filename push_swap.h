/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zramahaz <zramahaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:58:32 by zramahaz          #+#    #+#             */
/*   Updated: 2024/05/30 15:01:35 by zramahaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				current_position;
	int				path_lenght;
	bool			above_mediane;
	bool			shortest_path;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

void	push_swap(int argc, char **argv);
void	ft_init_stash(int argc, char **argv, t_list **a);

char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
long	ft_atoi(const char *str);

int		ft_sorted_stash(t_list *a);
size_t	ft_stash_len(t_list *a);
t_list	*ft_find_highest_node(t_list *a);
t_list	*ft_find_smallest_node(t_list *a);
t_list  *ft_get_last_list(t_list *stash);

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
void	ft_rotation(t_list **a, t_list **b, t_list *shortest_path);
void	ft_reverse_rotation(t_list **a, t_list **b, t_list *shortest_path);
void	ft_finish_rotation_b(t_list **b, t_list *shortest_path);
void	ft_finish_rotation_a(t_list **a, t_list *shortest_path);

void	ft_sorted_3_nb(t_list **a);
void    ft_sorted_multiple_nbs(t_list **a, t_list **b);

void	ft_set_current_position(t_list *stash);
void	ft_set_target_node(t_list *a, t_list *b);
void	ft_set_path_lenght(t_list *a, t_list *b);
void	ft_set_shortest_path(t_list *b);

#endif
