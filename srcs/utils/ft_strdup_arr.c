#include "minishell.h"

char	**ft_strdup_arr(char **arr)
{
	char	**ret;
	int		i;

	if (arr == NULL || *arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
		i++; 
	ret = (char **)malloc(sizeof(char *) * ++i);
	ret[--i] = NULL;
	while (--i >= 0)
		ret[i] = ft_strdup(arr[i]);
	return (ret);
}
