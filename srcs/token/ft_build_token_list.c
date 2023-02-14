#include "minishell.h"

void	get_tokens(t_list **token_lst, char **cmd);

void printf_list(t_list *lst)
{
	ft_printf("Token: %s [%d]\n", (char *) lst->content, lst->type);
}

void	ft_build_token_list(t_shell *shell, char **input)
{
	int	i;

	i = -1;
	while (++i < shell->cmd_amount)
	{
		get_tokens(&shell->cmd_table[i].tokens, ft_split(input[i], ' '));
		ft_lstiter(shell->cmd_table[i].tokens, printf_list);
	}
	ft_free_arr((void **)input);
}

 void	get_tokens(t_list **token_lst, char **cmd)
{
	int	i;
	//int j;
	//int k;

	//j = 0;
	i = 1;

	//printf("%p - %p\n", token_lst, *token_lst);
	ft_lstadd_back(token_lst, ft_lstnew(ft_strdup(cmd[0]), CMD));
	(void) token_lst;
	while (cmd[i])
	{
		//k = 0;
		//j = 0;
		/* while (cmd[i][j])
		{
			if (cmd[i][j] == '>' || cmd[i][j] == '<')
			{
				//ft_lstadd_back(token_lst, ft_lstnew(ft_substr(cmd[i], k, j - k)));

				//k = j + 1 + cmd[i][j + 1] == ' ';
			}
			j++;
		} */
		if (!ft_strncmp(cmd[i], "<", 2) || !ft_strncmp(cmd[i], ">", 2) || !ft_strncmp(cmd[i], ">>", 3) || !ft_strncmp(cmd[i], "<<", 3))
			ft_lstadd_back(token_lst, ft_lstnew(ft_strdup(cmd[i]), REDIR));
		else
			ft_lstadd_back(token_lst, ft_lstnew(ft_strdup(cmd[i]), ARGS));
		i++;
	}
	ft_free_arr((void **)cmd);
}
