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
	int	i;

	if (badset == NULL)
		return (0);
	i = 0;
	while (*(badset + i))
	{
		if (*(badset + i) == c)
			return (*(badset + i));
		i++;
	}
	return (-1);
}

int	ft_validate_next(char *line, const char *badset)
{
	int	c;
	int	i;

	i = 0;
	while (*(line + i))
	{
		if (*(line + i) == ' ' || ft_isescape(*(line + i)))
			i++;
		else
		{
			c = ft_badchar(*(line + i), badset);
			if (c > 0)
				ft_error_token(c);
			return (c != -1);
		}
	}
	ft_error_token(*(line + i));
	return (1);
}
