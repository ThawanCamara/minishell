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

static void	get_tokens(t_list *token_lst, char **cmd)
{
	int	i;

	(void) token_lst;
	i = 0;
	while (cmd[i])
	{
		printf("token: %s\n", cmd[i]);
		i++;
	}
	ft_free_arr((void **)cmd);
}