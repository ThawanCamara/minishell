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

static char	*get_line(void);

void	minishell(t_shell *shell)
{
	static char	*line = NULL;

	while (1)
	{
		line = get_line();
		ft_build_token_list();
		free(line);
	}
	rl_clear_history();
}

static char	*get_line(void)
{
	char	*prompt;
	char	*line;

	prompt = ft_get_prompt();
	line = readline(prompt);
	if (line == NULL)
	{
		printf("exit\n");
		free(prompt);
		free(line);
		rl_clear_history();
		exit(0);
	}
	if (ft_strncmp(line, "", 1) != 0)
		add_history(line);
	free(prompt);
	return (line);
}