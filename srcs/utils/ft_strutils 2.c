/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:05:39 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/21 14:05:39 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// to remove
int	ft_closedquotes_check(char *str)
{
	int		i;
	char	c;

	i = -1;
	c = 0;
	while (*(str + ++i))
	{
		if (*(str + i) == '\"' || *(str + i) == '\'')
		{
			c = *(str + i);
			while (*(str + i))
			{
				if (*(str + ++i) == c)
				{
					c = 0;
					break ;
				}
			}
		}
		if (*(str + i) == 0)
			break ;
	}
	return (c != 0);
}
