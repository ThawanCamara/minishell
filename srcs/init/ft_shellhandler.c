#include "minishell.h"

void	ft_initshell(t_shell *shell, char *envp[])
{
	shell->stdin = 0;
	shell->stdout = 1;
	shell->envp = ft_strdup_arr(envp);
	shell->cmd_table = NULL;
}

// Não parece seguro dar free em cmd_table aqui. Ver depois.
void	ft_clearshell(t_shell *shell)
{
	ft_free_arr((void **)shell->envp);
}
