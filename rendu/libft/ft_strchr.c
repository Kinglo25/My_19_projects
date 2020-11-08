#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char *)s;
	while (tmp)
		if (*tmp++ == c)
			return (tmp - 1);
	if (*tmp == c)
		return (tmp);
	return (NULL);
}
