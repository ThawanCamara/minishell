/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:54:14 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/21 13:54:14 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quotecheck(char c, int qflag)
{
	if (c == '\"' || c == '\'')
	{
		if (qflag == 0)
			qflag = c;
		else if (qflag == c)
			qflag = 0;
		return (qflag);
	}
	return (qflag);
}
