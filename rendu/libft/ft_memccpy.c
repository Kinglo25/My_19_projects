#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*d;

	d = dest;
	while (n--)
	{
		if ((*d++ = *(unsigned char*)src++) == c)
			return (d);
	}
	return (0);
}
