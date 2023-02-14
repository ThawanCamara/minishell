#include "minishell.h"

void	ft_initshell(t_shell *shell, char *envp[])
{
	shell->cmd_amount = 0;
	shell->stdin = 0;
	shell->stdout = 1;
	shell->envp = ft_strdup_arr(envp);
	shell->cmd_table = NULL;
}

void	ft_updateshell(t_shell *shell, char *line)
{
	int	i;

	i = -1;
	shell->cmd_amount = ft_count_pipes(line) + 1;
	shell->cmd_table = malloc(sizeof(t_simple) * shell->cmd_amount + 1);
	//shell->cmd_table[shell->cmd_amount] = 0;
	while (++i < shell->cmd_amount)
	{
		shell->cmd_table[i].tokens = NULL;
	}
		//shell->cmd_table->tokens = malloc(sizeof(t_list)); // falta dar free
}
/* void	ft_updateshell(t_shell *shell, char *line)
{
	int	i;

	i = -1;
	shell->cmd_amount = ft_count_pipes(line) + 1;
	//shell->cmd_table[shell->cmd_amount] = 0;
	shell->cmd_table = (t_simple **)malloc(sizeof(t_simple *) * shell->cmd_amount + 1);
	while (++i < shell->cmd_amount)
	{
		shell->cmd_table[i] = malloc(sizeof(t_simple));
		shell->cmd_table[i]->tokens = NULL;
	}
		//shell->cmd_table->tokens = malloc(sizeof(t_list)); // falta dar free
} */

// Não parece seguro dar free em cmd_table aqui. Ver depois. 
//ideia -> Liberar cmd_table com ft_clean pra garantir ponteiro pra nulo e prevenir double free
void	ft_clearshell(t_shell *shell)
{
	ft_free_arr((void **)shell->envp);
	/* for (int i = 0; i < shell->cmd_amount; i++)
		free(shell->cmd_table[i]);
	free(shell->cmd_table); */
	free(shell->cmd_table);
}
