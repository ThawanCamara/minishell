/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcombine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 00:22:39 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 14:02:37 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*combine_handler(int n, va_list args)
{
	char	*ret;
	char	*tmp;

	if (n <= 0)
		return (NULL);
	ret = ft_strdup(va_arg(args, char *));
	while (--n > 0)
	{
		tmp = ret;
		ret = ft_strjoin(ret, va_arg(args, char *));
		free(tmp);
	}
	return (ret);
}

char	*ft_strcombine(int n, ...)
{
	char	*ret;
	va_list	args;

	va_start(args, n);
	ret = combine_handler(n, args);
	va_end(args);
	return (ret);
}
