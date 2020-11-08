#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	if (!s)
		return (NULL);
	ptr = (unsigned char *)s;
	while (n--)
		if (*ptr++ == c)
			return (ptr - 1);
	return (NULL);
}
