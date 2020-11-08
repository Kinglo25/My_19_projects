#include "libft.h"

void	*memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*d;

	d = dest;
	while (n--)
	{
		if ((*d++ = *(char*)src++) == c)
			return (d);
	}
	return (0);
}
