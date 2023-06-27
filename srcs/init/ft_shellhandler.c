/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shellhandler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:50:57 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/21 13:50:57 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initshell(t_shell *shell, char *envp[])
{
	shell->m_din = dup(0);
	shell->m_dout = dup(1);
	shell->m_exit = 0;
	shell->m_rawline = NULL;
	shell->m_envp = ft_strarr_dup(envp);
}

void	ft_updateshell(t_shell *shell, char *line)
{
	shell->m_pidlst = NULL;
	shell->cmd_amount = ft_count_cmds(line);
	shell->line = ft_expand_var(line, shell->m_envp);
	shell->t_cmd = (t_cmd *)malloc(sizeof(t_cmd) * shell->cmd_amount);
	ft_initcmd(shell);
}

void	ft_resetshell(t_shell *shell)
{
	ft_free_lst(shell->m_pidlst);
	ft_clearcmd(shell);
	free(shell->line);
	free(shell->t_cmd);
	shell->cmd_amount = 0;
}

void	ft_clearshell(t_shell *shell)
{
	free(shell->m_rawline);
	ft_free_arr((void **)shell->m_envp);
	close(shell->m_din);
	close(shell->m_dout);
}

void	ft_exitshell(t_shell *shell, int ret)
{
	ft_resetshell(shell);
	ft_clearshell(shell);
	exit(ret);
}
