/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:27:02 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/22 13:27:02 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarr_expand(char **array, char *new)
{
	char	**ret;
	size_t	len;
	int		i;

	len = ft_strarr_size(array);
	ret = (char **)malloc(sizeof(char *) * (len + 2));
	i = -1;
	while (*(array + ++i))
		*(ret + i) = ft_strdup(*(array + i));
	*(ret + i++) = ft_strdup(new);
	*(ret + i) = NULL;
	return (ret);
}
