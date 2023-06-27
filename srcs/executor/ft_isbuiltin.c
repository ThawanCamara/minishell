/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbuiltin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:47:46 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/06 13:47:46 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isbuiltin(char *name)
{
	const char	*builtins[] = {"echo", "cd", "pwd", "export", "unset", "env",
		"exit", 0};
	int			ret;
	int			i;

	ret = -1;
	i = -1;
	while (*(builtins + ++i))
	{
		if (ft_strncmp(name, *(builtins + i), \
			ft_strlen(*(builtins + i)) + 1) == 0)
		{
			ret = i;
			break ;
		}
	}
	return (ret);
}
