// INCLUDE HEADER 42

#include "minishell.h"


int double_quotes(char *str, int i)
{
	i++;
    while (str[i])
	{
		if (str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

int	single_quotes(char *str, int i)
{
	i++;
	while (str[i])
	{
		if (str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

int	quotes_verification(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (single_quotes(str, i) == 1)
				return (1);
			else
				return (0);
		}
		if (str[i] == '"')
		{
			if (double_quotes(str, i) == 1)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (1);
}

// int main()
// {
// 	printf("%d\n", quotes_verification("\"hello\""));
// }