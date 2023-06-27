/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 06:32:30 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/07 06:32:30 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_from_bin(t_cmd *cmdt, char *path_value)
{
	char	*bin;
	char	**routes;
	int		i;

	routes = ft_split(path_value, ':');
	if (!routes)
		return (NULL);
	bin = NULL;
	i = -1;
	while (*(routes + ++i))
	{
		bin = ft_strcombine(3, *(routes + i), "/", cmdt->argv[0]);
		if (access(bin, F_OK) == 0)
			break ;
		else
		{
			free(bin);
			bin = NULL;
		}
	}
	ft_free_arr((void **)routes);
	return (bin);
}

void	ft_search_bin(t_shell *shell, t_cmd *cmdt)
{
	char	**path;
	char	*s;

	path = ft_getenv("PATH", shell->m_envp);
	s = NULL;
	if (path)
		s = get_from_bin(cmdt, path[1]);
	if (s && access(s, F_OK | X_OK) != 0)
		g_status = 126;
	ft_free_arr((void **)path);
	if (s)
	{
		free(cmdt->argv[0]);
		cmdt->argv[0] = s;
	}
}
