/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmdhandler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 03:16:58 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/05 03:16:58 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initcmd(t_shell *shell)
{
	char	**arr;
	char	*str;
	int		i;

	i = -1;
	arr = ft_split_cmds(shell->line, '|');
	while (*(arr + ++i))
	{
		shell->t_cmd[i].cmd = NULL;
		shell->t_cmd[i].infile = NULL;
		shell->t_cmd[i].outfile = NULL;
		shell->t_cmd[i].inredir = -10;
		shell->t_cmd[i].outredir = -10;
		shell->t_cmd[i].files = NULL;
		shell->t_cmd[i].redirmode = NULL;
		str = ft_parser(shell, &shell->t_cmd[i], arr[i]);
		shell->t_cmd[i].argv = ft_split_cmds(str, ' ');
		free(str);
	}
	ft_free_arr((void **)arr);
}

void	ft_clearcmd(t_shell *shell)
{
	t_cmd	*cmdt;
	int		i;

	i = -1;
	while (++i < shell->cmd_amount)
	{
		cmdt = &shell->t_cmd[i];
		if (cmdt->inredir == 2)
			close(ft_atoi(cmdt->infile));
		ft_nfree(4, cmdt->infile, cmdt->outfile, cmdt->cmd, cmdt->redirmode);
		ft_nfree_arr(2, cmdt->argv, cmdt->files);
	}
}
