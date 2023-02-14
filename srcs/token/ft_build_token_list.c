#include "minishell.h"

static void	get_tokens(t_list *token_lst, char *cmd);

void	ft_build_token_list(t_shell *shell, char **input)
{
	int	i;

	i = -1;
	while (++i < shell->cmd_amount)
		get_tokens(shell->cmd_table[i].tokens, input[i]);
	ft_free_arr(input);
}

static void	get_tokens(t_list *token_lst, char *cmd)
{
	while (*cmd)
	{
		
		cmd++;
	}
}