/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/14 18:26:52 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void printf_list2(void *content)
{
	ft_printf("%s\n", (char *) content);
}

int main(void)
{
	t_list *lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("ola")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("ola")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("ola")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("ola")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("ola")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("ola")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("ola")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("ola")));
	//printf("%s\n", (char *) lst->content);
	ft_lstiter(lst, printf_list2);
	return (0);
} */

int	main(int argc, char *argv[], char **envp)
{
	t_shell	shell;

	(void) argc;
	(void) argv;
	ft_initshell(&shell, envp);
	minishell(&shell);
	ft_clearshell(&shell);
	return (0);
}
