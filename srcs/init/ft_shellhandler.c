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

	i = 0;
	shell->cmd_amount = ft_count_pipes(line) + 1;
	shell->cmd_table = malloc(sizeof(t_simple) * shell->cmd_amount + 1);
	shell->cmd_amount[shell->cmd_amount] = NULL;
	while (i < shell->cmd_amount)
		shell->cmd_table->tokens = NULL;
}

// Não parece seguro dar free em cmd_table aqui. Ver depois. 
//ideia -> Liberar cmd_table com ft_clean pra garantir ponteiro pra nulo e prevenir double free
void	ft_clearshell(t_shell *shell)
{
	ft_free_arr((void **)shell->envp);
	free(shell->cmd_table);
}
