/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/14 21:25:49 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void printf_list2(t_list *lst)
void printf_list2()
{
	//ft_printf("%s\n", lst->content);
	ft_printf("oi\n");
}

int main(void)
{
// 	t_list *lst;
// 	void *func;

// 	lst = NULL;
// 	func = printf_list2;
// 	ft_lstadd_back(&lst, ft_lstnew(ft_itoa(12), 0));
// 	ft_lstadd_back(&lst, ft_lstnew(ft_itoa(14), 0));
// 	//ft_lstiter(lst, func);
// 	((void (*)())func)();
	
	
	
	t_shell	shell;
	ft_initshell(&shell, NULL);
	((void (*)())shell.fcheck[0])();
	ft_clearshell(&shell);	
}

/* int	main(int argc, char *argv[], char **envp)
{
	t_shell	shell;

	(void) argc;
	(void) argv;
	ft_initshell(&shell, envp);
	minishell(&shell);
	ft_clearshell(&shell);
	return (0);
} */
