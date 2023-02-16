/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psydenst <psydenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/15 19:53:19 by psydenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//void printf_list2(t_list *lst)
void printf_list2()
{
	//ft_printf("%s\n", lst->content);
	ft_printf("oi\n");
}

// int main(void) // TEST
// {
// // 	t_list *lst;
// // 	void *func;

// // 	lst = NULL;
// // 	func = printf_list2;
// // 	ft_lstadd_back(&lst, ft_lstnew(ft_itoa(12), 0));
// // 	ft_lstadd_back(&lst, ft_lstnew(ft_itoa(14), 0));
// // 	//ft_lstiter(lst, func);
// // 	((void (*)())func)();
	
	
	
// 	t_shell	shell;
// 	ft_initshell(&shell, NULL);
// 	for (int i = 0; i < CHECKER_FUNCTION_COUNT; i++)
// 		((void (*)())shell.fcheck[i])();
// 		//((void (*)())shell.fcheck[i])(1); // da pra passar argumentos, as funções que podem usar usam e as que nao podem ignoram, q louco
// 	ft_clearshell(&shell);	
// }

int	main(int argc, char *argv[], char **envp) // MINISHELL
{
	t_shell	shell;

	(void) argc;
	(void) argv;
	ft_initshell(&shell, envp);
	minishell(&shell);
	ft_clearshell(&shell);
	return (0);
}
