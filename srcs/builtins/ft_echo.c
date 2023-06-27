/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 07:07:40 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/23 07:07:40 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_putstr_fd2(char *s, int fd)
{
	int	qflag;

	qflag = 0;
	while (*s != 0)
	{
		if (!((*s == '\'' || *s == '\"') && (qflag == *s || qflag == 0)))
			write(fd, s, 1);
		qflag = ft_quotecheck(*s, qflag);
		s++;
	}
}

// Waits for "CMD" "FLAG" "ARG[" 
int	ft_echo(t_shell *shell, char *argv[])
{
	int		i;
	int		flag;

	(void)shell;
	flag = 0;
	if (argv[1] != NULL)
	{
		i = 1;
		flag = ft_strncmp(argv[i], "-n", 3) == 0;
		while (argv[i + flag])
		{
			ft_putstr_fd2(argv[i + flag], 1);
			if (argv[++i + flag])
				ft_putchar_fd(' ', 1);
		}
	}
	if (flag == 0)
		ft_putchar_n('\n', 1);
	return (0);
}
