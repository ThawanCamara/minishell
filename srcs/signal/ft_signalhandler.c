/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signalhandler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:55:53 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 16:55:53 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sighandler(int sig);

int	ft_signal_handler(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	signal(SIGQUIT, SIG_IGN);
	sa.sa_handler = &sighandler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa, NULL);
	return (0);
}

static void	sighandler(int sig)
{
	if (sig == SIGINT)
	{
		g_status = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	reset_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
