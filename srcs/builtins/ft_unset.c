/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:02:30 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 20:02:30 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(t_shell *shell, char *argv[])
{
	char	*key;

	if (argv && argv[1])
	{
		key = ft_strdup(argv[1]);
		shell->m_envp = ft_delenv(key, shell->m_envp);
		free(key);
	}
	return (0);
}
