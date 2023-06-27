/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_var_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:08:23 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/01 17:08:23 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_expand_check_mode(char *str)
{
	if (*str == '?' || ft_strncmp(str, "{?}", 3) == 0)
		return (1);
	else if (*str == '{')
		return (2);
	else if (*str != '}' && *str != ' ' && *str != '$')
		return (3);
	return (0);
}

int	ft_expand_get_len(char *str)
{
	int		len;
	int		mode;
	char	*tmp;

	tmp = NULL;
	len = 0;
	mode = ft_expand_check_mode(str);
	if (*str == '$')
		return (1);
	if (mode == 1)
		return (((*str == '{') * 2) + 1);
	else if (mode == 2)
	{
		tmp = ft_substr(str, 1, ft_strdiff(str + 1, '}'));
		len += sizeof(char) * ((tmp != NULL) * 2);
	}
	else
		tmp = ft_substr(str, 0, ft_strlen(str) - \
			ft_strlen(ft_expand_search(str, "\", $, , ")));
	len += ft_strlen(tmp);
	free(tmp);
	return (len);
}

char	*ft_expand_search(const char *s, char *set)
{
	size_t	len;
	int		i;

	len = ft_strlen(s);
	while (len + 1)
	{
		i = -1;
		while (*(set + ++i))
		{
			if (*s == *(set + i))
				return ((char *)s);
		}
		s++;
		len--;
	}
	return (0);
}
