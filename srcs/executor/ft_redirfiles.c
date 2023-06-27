/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirfiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:55:18 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/08 13:55:18 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_redir_error(char *file, int redirmode, int ret)
{
	perror(file);
	(void)redirmode;
	return (ret);
}

int	ft_redirfiles(char **files, char *redirmode)
{
	int	i;
	int	fd;

	if (!files || !redirmode)
		return (0);
	i = -1;
	while (*(files + ++i))
	{
		if (*(redirmode + i) == 4)
		{
			if (access(*(files + i), F_OK | R_OK) != 0)
				return (ft_redir_error(*(files + i), *(redirmode + i), 1));
		}
		else if (*(redirmode + i) == 1 || *(redirmode + i) == 3)
		{
			fd = open(*(files + i), ft_open_mode(*(redirmode + i)), 0755);
			if (fd < 0)
				return (ft_redir_error(*(files + i), *(redirmode + i), 1));
			write(fd, NULL, 0);
			close(fd);
		}
	}
	return (0);
}
