#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long int	ans;

	signe = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			signe *= -1;
	}
	ans = 0;
	while (str[i] >= '0' && str[i] <= '9')
		ans = (ans * 10) + (str[i++] - '0');
	return (ans * signe);
}