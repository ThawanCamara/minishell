/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:33:05 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/16 21:33:05 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_badchar(int c, const char *badset)
{
	if (badset == NULL)
		return (0);
	while (*badset)
	{
		if (*badset == c)
			return (*badset);
		badset++;
	}
	return (0);
}

int	ft_validate_next(char *line, const char *badset)
{
	while (*line)
	{
		if (*line == ' ' || ft_isescape(*line))
			line++;
		else
			return (ft_badchar(*line, badset));
	}
	return (-1);
}
