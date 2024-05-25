#include "push_swap.h"

static char	**ft_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	ft_count_strs(char const *s, char c)
{
	size_t	i;
	size_t	nb_strs;

	i = 0;
	nb_strs = 0;
	if (!s[0])
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
		}
		else
			i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void	ft_get_next_str(char **next_str, size_t *len, char c)
{
	size_t	i;

	*next_str = *next_str + *len;
	*len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char		**tab;
	char		*next_str;
	size_t		len;
	size_t		i;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_strs(s, c) + 1));
	if (!tab)
		return (NULL);
	next_str = (char *)s;
	len = 0;
	i = 0;
	while (i < ft_count_strs(s, c))
	{
		ft_get_next_str(&next_str, &len, c);
		tab[i] = ft_substr(next_str, 0, len);
		if (!tab[i])
			return (ft_malloc_error(tab));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	resultat;
	int	signe;

	i = 0;
	resultat = 0;
	signe = 1;
	while ((unsigned char)str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			signe *= -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		resultat *= 10;
		resultat += str[i] - 48;
		i++;
	}
	resultat *= signe;
	return (resultat);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*copy;
	size_t		i;
	size_t		new_len;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		copy[i] = s[start++];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}