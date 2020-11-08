#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	
	if (!dest)
		return (NULL);
	d = dest;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
