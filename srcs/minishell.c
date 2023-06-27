/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:16:50 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/13 17:16:50 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_line(t_shell *shell);

void	minishell(t_shell *shell)
{
	while (shell->m_exit == 0)
	{
		shell->m_rawline = get_line(shell);
		if (shell->m_rawline[0] && ft_lexer(shell->m_rawline) == 0)
		{
			ft_updateshell(shell, shell->m_rawline);
			if (!(shell->cmd_amount == 1 && !shell->t_cmd[0].argv[0]))
				ft_exec3(shell);
			ft_resetshell(shell);
		}
		free(shell->m_rawline);
		shell->m_rawline = NULL;
	}
	rl_clear_history();
}

char	*get_line(t_shell *shell)
{
	char	*prompt;
	char	*line;

	prompt = ft_get_prompt();
	line = readline(prompt);
	free(prompt);
	if (line == NULL)
	{
		ft_putstr_fd("exit\n", 2);
		rl_clear_history();
		ft_clearshell(shell);
		exit(0);
	}
	if (ft_strncmp(line, "", 1) != 0)
		add_history(line);
	return (line);
}
