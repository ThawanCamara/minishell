/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:15:42 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 20:15:42 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define TYPE_THRESHOLD 5

int	ft_exit(t_shell *shell, char *argv[])
{
	unsigned char	ret;
	int				i;

	ft_putstr_fd("exit\n", 2);
	if (ft_strarr_size(argv) > 2)
		return (ft_error_msg("exit: too many arguments", 1));
	ret = 0;
	i = -1;
	if (argv[1])
	{
		ret = ft_strlen(argv[1]) >= TYPE_THRESHOLD;
		while (argv[1][++i])
			if (ft_isdigit(argv[1][i]) == 0 || ret != 0)
				return (ft_error_msg("exit: numeric argument required", 2));
		if (ret == 0)
			ret = (char) ft_atoi(argv[1]);
	}
	shell->m_exit = 1;
	return (ret);
}
