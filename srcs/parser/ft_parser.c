/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:49:02 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/03 21:49:02 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getfile(char *str)
{
	char	*ret;

	while (*str == ' ' || ft_isescape(*str) || ft_isredir(str))
		str++;
	ret = ft_substr(str, 0, ft_strdiff(str, ' '));
	return (ret);
}

int	getindex(char *str)
{
	int	index;

	index = 0;
	while (*str == ' ' || ft_isescape(*str) || ft_isredir(str))
	{
		str++;
		index++;
	}
	index += ft_strdiff(str, ' ');
	return (index);
}

void	setfile(t_cmd *cmdt, char *file, int redir)
{
	char	*tmp[3];
	char	**tmp_arr;

	tmp[0] = cmdt->infile;
	tmp[1] = cmdt->outfile;
	if (redir % 2)
	{
		cmdt->outfile = ft_strdup(file);
		cmdt->outredir = ft_open_mode(redir);
		free(tmp[1]);
	}
	else
	{
		ft_set_cmd_input(cmdt, file, redir);
		free(tmp[0]);
	}
	tmp_arr = cmdt->files;
	cmdt->files = ft_strarr_expand(cmdt->files, file);
	ft_free_arr((void **)tmp_arr);
	tmp[2] = cmdt->redirmode;
	cmdt->redirmode = ft_straddchar(cmdt->redirmode, redir);
	free(tmp[2]);
}

char	*ft_parser(t_shell *shell, t_cmd *cmdt, char *line)
{
	char	*tmp;
	char	*ret;
	char	*file;
	int		qflag;
	int		i;

	(void)shell;
	i = -1;
	qflag = 0;
	ret = ft_strdup(line);
	while (*(ret + ++i))
	{
		qflag = ft_quotecheck(*(ret + i), qflag);
		if (qflag == 0 && ft_isredir((ret + i)))
		{
			tmp = ret;
			file = getfile(ret + i);
			setfile(cmdt, file, ft_isredir((ret + i)));
			ret = ft_str_detach(ret, i, getindex(ret + i) + i - 1);
			ft_nfree(2, tmp, file);
			qflag = 0;
			i = -1;
		}
	}
	return (ret);
}
