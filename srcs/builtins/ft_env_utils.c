/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:38:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 12:38:53 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_and_replace(char *var, char *newvar, char **envp);

char	**ft_getenv(char *var, char **envp)
{
	int		i;
	size_t	len;
	char	**ret;

	if (var == NULL)
		return (NULL);
	i = -1;
	var = ft_strjoin(var, "=");
	len = ft_strlen(var);
	ret = NULL;
	while (*(envp + ++i))
	{
		if (ft_strncmp(var, *(envp + i), len) == 0)
		{
			ret = (char **)malloc(sizeof(char *) * 3);
			ret[0] = ft_substr(*(envp + i), 0, ft_strdiff(*(envp + i), '='));
			ret[1] = ft_strdup(ft_strchr(*(envp + i), '=') + 1);
			ret[2] = NULL;
			break ;
		}
	}
	free(var);
	return (ret);
}

char	**ft_setenv(char *var, char *value, char **envp)
{
	char	**ret;
	char	*newvar;

	if (var == NULL || value == NULL || envp == NULL)
		return (envp);
	newvar = ft_strcombine(3, var, "=", value);
	if (find_and_replace(var, newvar, envp))
		return (envp);
	ret = ft_strarr_expand(envp, newvar);
	free(newvar);
	ft_free_arr((void **) envp);
	return (ret);
}

char	**ft_delenv(char *var, char **envp)
{
	char	**ret;

	if (var == NULL || envp == NULL)
		return (envp);
	var = ft_strjoin(var, "=");
	ret = ft_strarr_remove(envp, var);
	if (ret != envp)
		ft_free_arr((void **) envp);
	free(var);
	return (ret);
}

static int	find_and_replace(char *var, char *newvar, char **envp)
{
	int		i;
	size_t	len;

	i = -1;
	var = ft_strjoin(var, "=");
	len = ft_strlen(var);
	while (*(envp + ++i))
	{
		if (ft_strncmp(var, *(envp + i), len) == 0)
		{
			free(*(envp + i));
			*(envp + i) = newvar;
			free(var);
			return (1);
		}
	}
	free(var);
	return (0);
}
