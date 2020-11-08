#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!(new = malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	new[len] = '\0';
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}
