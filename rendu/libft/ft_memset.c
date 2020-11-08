#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    unsigned char *ptr;

    if (!s)
        return (NULL);
    ptr = s;
    while (n--)
        *ptr++ = c;
    return (s);
}
