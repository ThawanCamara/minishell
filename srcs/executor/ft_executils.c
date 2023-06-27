/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:46:18 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/08 22:46:18 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_fdin(int pipefd, t_cmd *cmdt)
{
	if (cmdt->infile == NULL)
		return (pipefd);
	else if (cmdt->inredir == 2)
		return (ft_atoi(cmdt->infile));
	else
		return (open(cmdt->infile, cmdt->inredir));
}

int	ft_fdout(int pipefd, t_cmd *cmdt)
{
	if (cmdt->outfile == NULL)
		return (pipefd);
	else
		return (open(cmdt->outfile, cmdt->outredir));
}

void	exec(t_shell *shell, int i, int fdin, int fdout)
{
	ft_search_bin(shell, &shell->t_cmd[i]);
	if (g_status != 0)
		ft_exitshell(shell, 1);
	if (execve(shell->t_cmd[i].argv[0], \
		shell->t_cmd[i].argv, shell->m_envp) < 0)
	{
		ft_putstr_fd(shell->t_cmd[i].argv[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		if (fdin != 0 && fdin != 1 && fdin != 2)
			close(fdin);
		if (fdout != 0 && fdout != 1 && fdout != 2)
			close(fdout);
		ft_exitshell(shell, 127);
	}
}

void	ft_solobuiltin(t_shell *shell, t_cmd *cmdt, int prevpipe, int i)
{
	int		fdin;
	int		fdout;

	g_status = ft_redirfiles(shell->t_cmd[i].files, \
				shell->t_cmd[i].redirmode);
	if (g_status != 0)
		return ;
	fdin = ft_fdin(prevpipe, cmdt);
	dup2 (fdin, STDIN_FILENO);
	close (prevpipe);
	fdout = ft_fdout(STDOUT_FILENO, cmdt);
	if (fdout != STDOUT_FILENO)
		dup2(fdout, STDOUT_FILENO);
	ft_exec_builtin(shell, &shell->t_cmd[i], \
		ft_isbuiltin(shell->t_cmd[i].argv[0]));
	if (fdin != 0 && fdin != 1 && fdin != 2)
		close(fdin);
	if (fdout != 0 && fdout != 1 && fdout != 2)
		close(fdout);
	dup2(shell->m_din, STDIN_FILENO);
	dup2(shell->m_dout, STDOUT_FILENO);
}
