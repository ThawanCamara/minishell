/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 11:21:16 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/10 02:53:13 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_str(char *eof)
{
	char	*ret;
	char	*tmp;
	char	*file;
	char	*error;

	ret = NULL;
	file = NULL;
	error = NULL;
	while ((g_status != 130) && (!ret || ft_strncmp(ret, eof, \
	ft_strlen(eof) + 1)))
	{
		tmp = file;
		if (ret)
			file = ft_strcombine(3, tmp, ret, "\n");
		ft_nfree(2, ret, tmp);
		ret = readline("> ");
		if (!ret)
		{
			error = ft_strcombine(3, "here-document delimited by \
					end-of-file (wanted `", eof, "\')");
			ft_error_msg(error, 1);
			break ;
		}
	}
	ft_nfree(2, ret, error);
	return (file);
}

char	*ft_get_here_doc(char *eof)
{
	int		fd[2];
	char	*str;

	if (pipe(fd) == -1)
	{
		ft_error_msg("Could not pipe", 1);
		return (NULL);
	}
	str = get_str(eof);
	write(fd[1], str, ft_strlen(str));
	close(fd[1]);
	free(str);
	str = ft_itoa(fd[0]);
	if (!str || g_status == 130)
	{
		close(fd[0]);
		free(str);
		return (NULL);
	}
	return (str);
}
