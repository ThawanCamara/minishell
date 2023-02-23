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

int	ft_export(t_shell *shell, char *argv[])
{
	char	*key;
	char	*value;

	if (argv && argv[1])
	{
		key = ft_substr(argv[1], 0, ft_strlen(argv[1]) -
			ft_strlen(ft_strchr(argv[1], '=')));
		value = ft_strdup(ft_strchr(argv[1], '=') + 1);
		shell->envp = ft_setenv(key, value, shell->envp);
		ft_nfree(2, key, value);
	}
	return (0);
}
