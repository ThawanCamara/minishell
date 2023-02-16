#include "minishell.h"

//void	get_tokens(t_list **token_lst, char **cmd);
void	get_tokens(t_list **token_lst, char *cmd);

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
		//get_tokens(&shell->cmd_table[i].tokens, ft_split(input[i], ' '));
		get_tokens(shell, &shell->cmd_table[i].tokens, input[i]);
		ft_lstiter(shell->cmd_table[i].tokens, printf_list);
	}
	ft_free_arr((void **)input);
}

void	get_tokens(t_shell *shell, t_list **token_lst, char *cmd)
{
	int	i;
	int k;
	char	*token;

	i = 0;
	k = 0;
	while (cmd[i])
	{
		k = 0;
		while (k < CHECKER_FUNCTION_COUNT)
		{
			token = ((void (*)())shell->fcheck[k])(shell, token_lst, cmd);
			if (token != NULL)
				break ;
			k++;
		}
		i += ft_strlen(token);
	}
	//ft_free_arr((void **)cmd);
}

// void	get_tokens(t_list **token_lst, char *cmd)
// {
// 	int	i;
// 	int k;
// 	char	*token;

// 	i = 0;
// 	k = 0;
// 	while (cmd[i])
// 	{
// 		if (cmd[i + 1] == ' ' || cmd[i + 1] == 0)
// 		{
// 			token = ft_substr(cmd, k, i + 1 - k);
// 			ft_lstadd_back(token_lst, ft_lstnew(token, ARGS));
// 			k = i + 1;
// 			i += ft_strlen(token) + 1;
// 			continue ;
// 		}
// 		i++;
// 	}
// 	//ft_free_arr((void **)cmd);
// }
