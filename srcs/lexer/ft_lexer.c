/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:33:07 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/16 21:33:07 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lexer(char *line)
{
	int	ret;
	int	qflag;

	ret = 0;
	qflag = 0;
	while (*line && ret == 0)
	{
		if (*(line - 1) != '\\')
			qflag = ft_quotecheck(*line, qflag);
		ret += ft_redir_append(line, qflag, ret);
		ret += ft_redir_heredoc(line, qflag, ret);
		ret += ft_redir_out(line, qflag, ret);
		ret += ft_redir_in(line, qflag, ret);
		line++;
	}
	if (ret == 0 && qflag != 0)
		ft_error_quotes();
	return (ret + qflag);
}
