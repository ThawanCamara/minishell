/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:43:29 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/08 11:43:29 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_set_cmd_input(t_cmd *cmdt, char *file, int redir)
{
	int	last_input;
	int	i;

	i = 0;
	last_input = -10;
	if (cmdt->redirmode)
	{
		while (cmdt->redirmode[i])
		{
			if (cmdt->redirmode[i] % 2 == 0)
				last_input = cmdt->redirmode[i];
			i++;
		}
	}
	if (last_input == 2)
		close(ft_atoi(cmdt->infile));
	if (redir == 4)
		cmdt->infile = ft_strdup(file);
	else if (redir == 2)
		cmdt->infile = ft_get_here_doc(file);
	cmdt->inredir = ft_open_mode(redir);
}
