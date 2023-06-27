/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:52:41 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/08 10:52:41 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_open_mode(int redirmode)
{
	int	flag;

	flag = -1;
	if (redirmode == 1)
		flag = O_RDWR | O_CREAT | O_APPEND;
	else if (redirmode == 2)
		flag = 2;
	else if (redirmode == 3)
		flag = O_RDWR | O_CREAT | O_TRUNC;
	else if (redirmode == 4)
		flag = O_RDONLY;
	return (flag);
}
