#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
    int             value;
    int             current_position;
    int             push_price;
    bool            above_mediane;
    struct s_list   *next;
    struct s_list   *prev;
    struct s_list   *target_node;
}                   t_list;

int     main(int argc, char **argv);
int	    ft_atoi(const char *str);
int     stack_sorted(t_list *stack);
int     stack_len(t_list *stack);

char	**ft_split(char const *s, char c);

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);

void    stack_init(int argc, char **argv, t_list **stack);
void	push_swap(t_list **a, t_list **b);
void    affichage(t_list **stack);

t_list	*ft_get_last_list(t_list *stash);
t_list	*find_highest(t_list *stack);
t_list	*find_smallest(t_list *stack);

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

void	tiny_sort(t_list **stack);

void	set_target_node(t_list *a, t_list *b);
void	set_position_node(t_list *stack);
void	set_price(t_list *a, t_list *b);

#endif