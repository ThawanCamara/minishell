/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:07:10 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/06 14:07:10 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec_builtin(t_shell *shell, t_cmd *cmd, int builtin)
{
	if (builtin == D_ECHO)
		g_status = ft_echo(shell, cmd->argv);
	else if (builtin == D_CD)
		g_status = ft_cd(shell, cmd->argv);
	else if (builtin == D_PWD)
		g_status = ft_pwd();
	else if (builtin == D_EXPORT)
		g_status = ft_export(shell, cmd->argv);
	else if (builtin == D_UNSET)
		g_status = ft_unset(shell, cmd->argv);
	else if (builtin == D_ENV)
		g_status = ft_env(shell);
	else if (builtin == D_EXIT)
		g_status = ft_exit(shell, cmd->argv);
}
