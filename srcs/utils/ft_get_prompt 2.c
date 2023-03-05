/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:18:15 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/13 17:18:15 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_prompt(void)
{
	char	*cwd;
	char	*str;
	char	*tmp;

	str = NULL;
	cwd = getcwd(NULL, 0);
	if (ft_strrchr(cwd, '/') != NULL)
		str = ft_strdup(ft_strrchr(cwd, '/') + 1);
	free(cwd);
	tmp = ft_strdup(LGREEN);
	tmp = append_line(tmp, str);
	free(str);
	str = tmp;
	str = append_line(str, RESET);
	str = append_line(str, "$> ");
	return (str);
}
