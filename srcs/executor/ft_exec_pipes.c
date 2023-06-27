/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:22:31 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/03 13:22:31 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_last2(t_shell *shell, t_cmd *cmdt, int prevpipe, int i)
{
	pid_t	cpid;
	int		fdin;
	int		fdout;

	cpid = fork();
	if (cpid == 0)
	{
		reset_signal();
		fdin = ft_fdin(prevpipe, cmdt);
		dup2 (fdin, STDIN_FILENO);
		close (prevpipe);
		fdout = ft_fdout(STDOUT_FILENO, cmdt);
		if (fdout != STDOUT_FILENO)
			dup2(fdout, STDOUT_FILENO);
		execv_or_builtin(shell, i, fdin, fdout);
	}
	else
	{
		ft_lstadd_back(&shell->m_pidlst, ft_lstnew(0, cpid));
		close (prevpipe);
		pids_wait(shell->m_pidlst);
	}
}

void	pids_wait(t_list *m_pidlist)
{
	t_list	*current_pid;
	int		c_status;

	c_status = 0;
	current_pid = m_pidlist;
	while (current_pid)
	{
		waitpid(current_pid->value, &c_status, 0);
		current_pid = current_pid->next;
		if (WIFEXITED(c_status))
			g_status = WEXITSTATUS(c_status);
		if (WIFSIGNALED(c_status))
			g_status = 128 + WTERMSIG(c_status);
	}
}

//26
void	ft_pipe2(t_shell *shell, t_cmd *cmdt, int *prevpipe, int i)
{
	int		pipefd[2];
	pid_t	cpid;
	int		fd[2];

	pipe(pipefd);
	cpid = fork();
	if (cpid == 0)
	{
		reset_signal();
		close (pipefd[0]);
		fd[1] = ft_fdout(pipefd[1], cmdt);
		dup2(fd[1], STDOUT_FILENO);
		close (pipefd[1]);
		fd[0] = ft_fdin(*prevpipe, cmdt);
		dup2 (fd[0], STDIN_FILENO);
		close (*prevpipe);
		execv_or_builtin(shell, i, fd[0], fd[1]);
	}
	else
	{
		ft_lstadd_back(&shell->m_pidlst, ft_lstnew(0, cpid));
		close (pipefd[1]);
		close (*prevpipe);
		*prevpipe = pipefd[0];
	}
}

void	execv_or_builtin(t_shell *shell, int i, int fdin, int fdout)
{
	int	builtin;

	if (g_status != 0)
		ft_exitshell(shell, 1);
	builtin = ft_isbuiltin(shell->t_cmd[i].argv[0]);
	if (builtin >= 0)
	{
		ft_exec_builtin(shell, &shell->t_cmd[i], builtin);
		if (fdin != 0 && fdin != 1 && fdin != 2)
			close(fdin);
		if (fdout != 0 && fdout != 1 && fdout != 2)
			close(fdout);
		ft_exitshell(shell, g_status);
	}
	else
		exec(shell, i, fdin, fdout);
}

void	ft_exec3(t_shell *shell)
{
	int	prevpipe;
	int	i;

	prevpipe = dup(0);
	i = -1;
	if (shell->cmd_amount == 1 && ft_isbuiltin(shell->t_cmd[0].argv[0]) >= 0)
		ft_solobuiltin(shell, &shell->t_cmd[0], prevpipe, 0);
	else
	{
		while (++i < shell->cmd_amount)
		{
			g_status = ft_redirfiles(shell->t_cmd[i].files, \
				shell->t_cmd[i].redirmode);
			if (i == shell->cmd_amount - 1)
				ft_last2(shell, &shell->t_cmd[i], prevpipe, i);
			else
				ft_pipe2(shell, &shell->t_cmd[i], &prevpipe, i);
		}
	}
}
