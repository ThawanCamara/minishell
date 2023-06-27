/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 17:24:04 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 17:24:04 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error_quotes(void)
{
	const char	*shell = "-minishell:";
	const char	*err = "syntax error near unexpected dangling quote";
	char		*msg;

	msg = ft_strcombine(4, shell, " ", err, "\n");
	ft_putstr_fd(msg, STDERR_FILENO);
	free(msg);
}

void	ft_error_token(char token)
{
	const char	*shell = "-minishell:";
	const char	*err = "syntax error near unexpected token";
	char		*tmptok;
	char		*msg;

	if (token == 0)
		tmptok = ft_strdup("newline");
	else
		tmptok = ft_ctoa(token);
	msg = ft_strcombine(6, shell, " ", err, " `", tmptok, "'\n");
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_nfree(2, msg, tmptok);
}

int	ft_error_msg(char *msg, int ret)
{
	const char	*shell = "-minishell:";
	char		*print;

	if (msg == NULL)
		return (ret);
	print = ft_strcombine(4, shell, " ", msg, "\n");
	ft_putstr_fd(print, STDERR_FILENO);
	free(print);
	return (ret);
}
