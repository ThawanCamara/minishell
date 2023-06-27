/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:33:03 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/16 21:33:03 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redir_out(char *line, int qflag, int ret)
{
	const char	target = '>';
	const char	*badset = "*;\n<";

	if (qflag > 0 || ret > 0)
		return (0);
	if (*line == target)
		return (ft_validate_next(line + 1, badset));
	return (0);
}

int	ft_redir_in(char *line, int qflag, int ret)
{
	const char	target = '<';
	const char	*badset = "*;\n>";

	if (qflag > 0 || ret > 0)
		return (0);
	if (*line == target)
		return (ft_validate_next(line + 1, badset));
	return (0);
}

int	ft_redir_append(char *line, int qflag, int ret)
{
	const char	target = '>';
	const char	*badset = "*;\n<>";

	if (qflag > 0 || ret > 0 || ft_strlen(line) < 2)
		return (0);
	if (*line == target)
		return (ft_validate_next(line + 2, badset));
	return (0);
}

int	ft_redir_heredoc(char *line, int qflag, int ret)
{
	const char	target = '<';
	const char	*badset = "*;\n<>";

	if (qflag > 0 || ret > 0 || ft_strlen(line) < 2)
		return (0);
	if (*line == target)
		return (ft_validate_next(line + 2, badset));
	return (0);
}
