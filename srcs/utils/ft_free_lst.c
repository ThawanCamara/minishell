/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:48:25 by tde-souz          #+#    #+#             */
/*   Updated: 2023/03/10 00:11:04 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_lst(t_list *lst)
{
	t_list	*next;

	if (!lst)
		return ;
	while (lst)
	{
		next = lst->next;
		free(lst);
		lst = next;
	}
	lst = 0;
}
