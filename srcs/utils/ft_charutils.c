#include "minishell.h"

int	ft_count_pipes(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (0);
	while (*str)
		count += *str++ == '|';
	return (count);
}
