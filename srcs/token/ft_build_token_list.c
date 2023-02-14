#include "minishell.h"

static void	get_tokens(t_list *token_lst, char **cmd);

void	ft_build_token_list(t_shell *shell, char **input)
{
	int	i;

	i = -1;
	while (++i < shell->cmd_amount)
		get_tokens(shell->cmd_table[i].tokens, ft_split(input[i], ' '));
	ft_free_arr((void **)input);
}

void printf_list(void *token)
{
	printf("%s\n", token);
}

static void	get_tokens(t_list *token_lst, char **cmd)
{
	int	i;
	int j;
	int k;

	(void) token_lst;
	j = 0;
	i = 0;
	while (cmd[i])
	{
		k = 0;
		j = 0;
		while (cmd[i][j])
		{
			if (cmd[i][j + 1] == ' ' || cmd[i][j + 1] == '>' || cmd[i][j + 1] == '<')
			{
				ft_lstadd_front(&token_lst, ft_lstnew(ft_substr(cmd[i], k, j - k)));
				k = j + 1 + cmd[i][j + 1] == ' ';
			}
			j++;
		}
		i++;
	}
	ft_lstiter(token_lst, printf_list);
	ft_free_arr((void **)cmd);
}
