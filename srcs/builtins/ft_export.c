/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:59:45 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 19:59:45 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*erase_quotes(char *s)
{
	char	*ret;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = -1;
	j = -1;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (*(s + ++i))
	{
		if (*(s + i) != '\'' && *(s + i) != '\"')
			*(ret + ++j) = *(s + i);
	}
	*(ret + ++j) = 0;
	return (ret);
}

int	ft_export(t_shell *shell, char *argv[])
{
	char	*key;
	char	*value;
	char	*chr;
	char	*tmp;

	if (argv && argv[1])
	{
		tmp = erase_quotes(argv[1]);
		key = ft_substr(tmp, 0, ft_strlen(tmp)
				- ft_strlen(ft_strchr(tmp, '=')));
		chr = ft_strchr(tmp, '=');
		if (chr == NULL)
		{
			ft_nfree(2, tmp, key);
			return (0);
		}
		value = ft_strdup(chr + 1);
		shell->m_envp = ft_setenv(key, value, shell->m_envp);
		ft_nfree(3, tmp, key, value);
	}
	return (0);
}
