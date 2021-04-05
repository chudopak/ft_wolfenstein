#include "../headers/overall.h"

static unsigned long	auxiliary(char **str)
{
	unsigned long	i;

	i = 0;
	while (**str >= '0' && **str <= '9')
	{
		i = i * 10 + (**str - '0');
		(*str)++;
		if (i > 300000)
		{
			while (**str >= '0' && **str <= '9')
				(*str)++;
			return (300000);
		}
	}
	return (i);
}

int						atoi_cub(char **str)
{
	unsigned long	i;

	i = 0;
	while (**str == ' ')
		(*str)++;
	if (**str == '+')
		(*str)++;
	else if (**str == '-')
		return (-1);
	if (**str < '0' || **str > '9')
		return (-1);
	i = auxiliary(str);
	return (i);
}
