/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:08:35 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/01 17:08:35 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var(char *str, char *envp[])
{
	char	**env;
	char	*ret;

	env = ft_getenv(str, envp);
	if (env)
	{
		ret = ft_strdup(env[1]);
		ft_free_arr((void **) env);
	}
	else
		ret = ft_strdup("");
	return (ret);
}

char	*handler(char *str, char *envp[])
{
	char	*ret;
	char	*tmp;
	int		mode;

	if (str == NULL || envp == NULL)
		return (NULL);
	tmp = NULL;
	mode = ft_expand_check_mode(str);
	if (mode == 1)
	{
		tmp = ft_itoa(g_status);
		return (tmp);
	}
	else if (mode == 2)
		tmp = ft_substr(str, 1, ft_strdiff(str + 1, '}'));
	else if (mode == 3)
		tmp = ft_substr(str, 0, ft_strlen(str) - \
			ft_strlen(ft_expand_search(str, "\", $, , ")));
	ret = get_var(tmp, envp);
	free(tmp);
	return (ret);
}

char	*combine_var(char *cache, char *str, char **envp)
{
	char	*ret;
	char	*tmp;

	if (*str == '$')
		tmp = ft_strdup("$");
	else
		tmp = handler((str), envp);
	ret = ft_strcombine(2, cache, tmp);
	free(tmp);
	return (ret);
}

char	*expand_loop(char *str, char *envp[])
{
	int		i;
	int		qflag;
	char	*ret;
	char	*tmp;

	i = -1;
	qflag = 0;
	ret = NULL;
	while (*(str + ++i))
	{
		tmp = ret;
		qflag = ft_quotecheck(*(str + i), qflag);
		if (*(str + i) == '$' && *(str + i + 1) && qflag != '\'')
		{
			ret = combine_var(ret, (str + i + 1), envp);
			i += ft_expand_get_len((str + i + 1));
		}
		else
			ret = ft_straddchar(ret, *(str + i));
		free(tmp);
	}
	return (ret);
}

char	*ft_expand_var(char *str, char *envp[])
{
	char	*ret;

	if (str == NULL)
		return (NULL);
	if (ft_strchr(str, '$'))
		ret = expand_loop(str, envp);
	else
		ret = ft_strdup(str);
	return (ret);
}
