/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcommands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:26:00 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/21 12:26:00 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	count_words(const char *s, char c)
{
	size_t	count;
	int		qflag;

	count = 0;
	qflag = 0;
	while (*s)
	{
		qflag = ft_quotecheck(*s, qflag);
		if (qflag > 0 && s++)
			continue ;
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	*get_next_word(const char *s, char c)
{
	size_t	len;
	int		qflag;

	len = 0;
	qflag = 0;
	while (*(s + len))
	{
		qflag = ft_quotecheck(*(s + len), qflag);
		if (qflag > 0 && len++)
			continue ;
		if (*(s + len) == c)
			break ;
		len++;
	}
	return (ft_substr(s, 0, len));
}

char	**ft_split_cmds(char const *s, char c)
{
	char	**ret;
	size_t	i;
	char	*tmp;

	if (s == NULL)
		return (NULL);
	ret = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (ret == 0)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			tmp = get_next_word(s, c);
			*(ret + i) = ft_strtrim(tmp, " ");
			s += ft_strlen(tmp);
			i++;
			free(tmp);
		}
		if (*s)
			s++;
	}
	*(ret + i) = 0;
	return (ret);
}
