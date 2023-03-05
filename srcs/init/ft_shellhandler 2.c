/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shellhandler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:50:57 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/21 13:50:57 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initshell(t_shell *shell, char *envp[])
{
	shell->cmd_amount = 0;
	shell->exit = 0;
	shell->envp = ft_strarr_dup(envp);
	shell->cmd_table = NULL;
	// ft_init_check_functions(shell);
}

void	ft_updateshell(t_shell *shell, char *line)
{
	int	i;

	i = -1;
	shell->cmd_amount = ft_count_cmds(line) + 1;
	shell->cmd_table = malloc(sizeof(t_simple) * shell->cmd_amount);
	while (++i < shell->cmd_amount)
	{
		shell->cmd_table[i].tokens = NULL;
	}
}

void	ft_clearshell(t_shell *shell)
{
	ft_free_arr((void **)shell->envp);
	ft_clean(shell->cmd_table, 0);
	free(shell->fcheck);
}

// Function that verify the existance of COMMANDS, which occours in the first position after pipes. 
// int f1(t_shell *shell, t_list **lst, char *cmd, int i, int k)
// {
// 	int begin;

// 	(void) k;
// 	begin = i;

// 	while(cmd[i] != ' ' && cmd[i])
// 		i++;
// 	shell->is_command = 1;
// 	ft_lstadd_back(lst, ft_lstnew(ft_substr(cmd, begin, i - begin), CMD));
//  	printf("Conteudo do nó %i: %s\n", begin, (char *)(*lst)->content);
// 	printf("Type do nó %i: %i\n", begin, (*lst)->type);

// 	return (i - begin);
// }

// // This function verify the existence of ARGS. They occour when shell->is_command == 1 e 
// int	f2(t_shell *shell, t_list **lst, char *cmd, int i, int k)
// {
// 	int begin;

// 	(void)lst;
// 	(void)shell;
// 	(void)k;
// 	(void)cmd;
// 	(void)i;

// 	begin = i;
// 	while((cmd[i] != '>') && (cmd[i] != '<') &&
// 		cmd[i] != '$' && cmd[i] != '{' && shell->is_command == 1 && cmd[i])
// 	{
// 		i++;
// 	}
// 	ft_lstadd_back(lst, ft_lstnew(ft_substr(cmd, begin, i - begin), ARGS));
//  	printf("Conteudo do nó %i: %s\n", k, (char *)(*lst)->next->content);
// 	printf("Type do nó %i: %i\n", k, (*lst)->next->type);
// 	shell->is_command = 0;
// 	return (i - begin);
// }

// // This function identify the existance of > && >>
// int	f3(t_shell *shell, t_list **lst, char *cmd, int i, int k)
// {
// 	(void)lst;
// 	(void)shell;
// 	(void)k;
// 	(void)cmd;
// 	(void)i;

// 	int begin;

// 	begin = i;
// 	while(cmd[i])
// 	{
// 		if (cmd[i] == '>')
// 		{
// 			if (cmd[i + 1] == '>')
// 				ft_lstadd_back(lst, ft_lstnew(ft_strdup(">>"), 14));
// 			else
// 				ft_lstadd_back(lst, ft_lstnew(ft_strdup(">"), 13));
//  			printf("Conteudo do nó %i: %s\n", begin, (char *)(*lst)->next->next->content);
// 			printf("Type do nó %i: %i\n", begin, (*lst)->next->next->type);
// 		}
// 		i++;
// 	}
// 	return (i - begin);
// }

// // This function identify the existance of << && <
// int f4(t_shell *shell, t_list **lst, char *cmd, int i, int k)
// {
// 	(void)lst;
// 	(void)shell;
// 	(void)k;
// 	(void)cmd;
// 	(void)i;

// 	int begin;

// 	begin = i;
// 	while(cmd[i])
// 	{
// 		if (cmd[i] == '<')
// 		{
// 			if (cmd[i + 1] == '<')
// 				ft_lstadd_back(lst, ft_lstnew(ft_strdup("<<"), 16));
// 			else
// 				ft_lstadd_back(lst, ft_lstnew(ft_strdup("<"), 15));
//  			printf("Conteudo do nó %i: %s\n", begin, (char *)(*lst)->next->next->next->content);
// 			printf("Type do nó %i: %i\n", begin, (*lst)->next->next->next->type);
// 		}
// 		i++;
// 	}
// 	return (i - begin);
// }

// // This function identify the existance of $
// int	f5(t_shell *shell, t_list **lst, char *cmd, int i, int k)
// {
// 	(void)lst;
// 	(void)shell;
// 	(void)k;
// 	(void)cmd;
// 	(void)i;

// 	int begin;

// 	begin = i;
// 	while(cmd[i])
// 	{
// 		if (cmd[i] == '$')
// 		{
// 			ft_lstadd_back(lst, ft_lstnew(ft_strdup("$"), 17));
// 		}
// 		i++;
// 	}
// 	return (i - begin);
// }

// // This function identify the existance of {}
// int f6(t_shell *shell, t_list **lst, char *cmd, int i, int k)
// {
// 	(void)lst;
// 	(void)shell;
// 	(void)k;
// 	(void)cmd;
// 	(void)i;

// 	int begin;
// 	int start;

// 	begin = i;
// 	start = i;
// 	while(cmd[i])
// 	{
// 		if (cmd[i] == '{')
// 		{
// 			start = i + 1;
// 			while (cmd[i] && cmd[i] != '}')
// 				i++;
// 			ft_lstadd_back(lst, ft_lstnew(ft_substr(cmd, start, i - start), 18));
// 		}
// 		i++;
// 	}
// 	return (i - begin);
// }

// void	ft_init_check_functions(t_shell *shell)
// {
// 	shell->fcheck = malloc(sizeof(void *) * CHECKER_FUNCTION_COUNT);
// 	shell->fcheck[0] = f1;
// 	shell->fcheck[1] = f2;
// 	shell->fcheck[2] = f3;
// 	shell->fcheck[3] = f4;
// 	shell->fcheck[4] = f5;
// 	shell->fcheck[5] = f6;
// }