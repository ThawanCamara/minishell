#include "minishell.h"

// char	*expand_withkeys(char *str, char *envp[])
// {

// }

// char	*expand_basic(char *str, char *envp[])
// {

// }

char	*handler(char *str, char *envp[])
{
	char	*ret;

	(void)envp;
	ret = NULL;
	if (*str == '?' || ft_strncmp(str, "{?}", 3) == 0)
		ret = ft_itoa(g_status);
	else if (*str == '{')
		ret = ft_substr(str, 1, ft_strdiff(str + 1, '}'));
	else if (*str != '}' && *str != ' ' && *str != '$')
		ret = ft_substr(str, 0, ft_strdiff(str, ' '));
	return (ret);
}

int	get_len(char *str)
{
	int		len;
	char	*tmp;

	len = 0;
	if (*str == '?' || ft_strncmp(str, "{?}", 3) == 0)
		return (1);
	else if (*str == '{')
		tmp = ft_substr(str, 1, ft_strdiff(str + 1, '}'));
	else if (*str != '}' && *str != ' ' && *str != '$')
		tmp = ft_substr(str, 0, ft_strdiff(str, ' '));
	len = ft_strlen(tmp);
	free(tmp);
	return (len);
}

char	*ft_expand_var(char *str, char *envp[])
{
	char	*ret;
	char	*var;
	int		i;
	int		qflag;

	(void)envp;
	if (str == NULL)
		return (NULL);
	ret = NULL;
	if (ft_strchr(str, '$'))
	{
		i = -1;
		qflag = 0;
		while (*(str + ++i))
		{
			qflag = ft_quotecheck(*(str + i), qflag);
			if (*(str + i) == '$' && *(str + i + 1) && qflag == 0)
			{
				var = handler((str + i + 1), envp);
				ft_printf("var: %s\n", var);
				ft_printf("var: %s\n", ret);
				ret = ft_strcombine(2, ret, var);
				free(var);
				i += get_len((str + i)) + 1;
			}
		}
	}
	return (ret);
}
