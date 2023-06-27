/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:59:25 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 19:59:25 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env(char *s)
{
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
}

int	ft_env(t_shell *shell)
{
	ft_striter(shell->m_envp, print_env);
	return (0);
}
