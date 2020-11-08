#include "libft.h"

static int	find_nb_str(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	find_len_str(char const *s, char c, int i)
{
	int		len;

	len = 0;
	while (s[i] && s[i] != c)
		len++;
	return (len);
}

static void	fill(char const *s, char c, int nb_str, char **split)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (nb_str--)
	{
		while (s[i] == c && s[i])
			i++;
		if (!(split[j] = malloc(find_len_str(s, c, i) + 1)))
		{
			while (j--)
				free(split[j]);
			free (split);
			return ;
		}
		while (s[i] != c && s[i])
			split[j][k++] = s[i++];
		split[j++][k] = '\0';
	}
}

char		**ft_split(char const *s, char c)
{
	int		nb_str;
	char	**split;

	if (!s)
		return (NULL);
	nb_str = find_nb_str(s, c);
	if (!(split = malloc(sizeof(char*) * (nb_str + 1))))
		return (NULL);
	split[nb_str] = NULL;
	fill(s, c, nb_str, split);
	return (split);
}
