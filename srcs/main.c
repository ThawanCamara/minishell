/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/14 19:38:30 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void printf_list2(void *content)
{
	ft_printf("%s\n", (char *) content);
}

/* typedef struct s_test
{
	t_list **lst;
} t_test;

int main(void)
{
	t_test *tst;

	tst = malloc(sizeof(t_test));
	tst->lst = (t_list **)malloc(sizeof(t_list *) * 3);
	tst->lst[0] = NULL;
	tst->lst[1] = NULL;
	tst->lst[2] = NULL;
	int i = 0;
	while (i < 10)
	{
		ft_lstadd_back(&tst->lst[0], ft_lstnew(ft_itoa(i)));
		ft_lstadd_back(&tst->lst[1], ft_lstnew(ft_itoa(i)));
		ft_lstadd_back(&tst->lst[2], ft_lstnew(ft_itoa(i)));
		i++;
	}
	ft_lstiter(tst->lst[0], printf_list2);
	ft_lstiter(tst->lst[1], printf_list2);
	ft_lstiter(tst->lst[2], printf_list2);
	return (0);
} */

/* int main(void)
{
	t_list *lst;

	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_itoa(12)));
	ft_lstadd_back(&lst, ft_lstnew(ft_itoa(14)));
	ft_lstiter(lst, printf_list2);
}
 */
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
