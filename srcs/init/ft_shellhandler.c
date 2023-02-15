#include "minishell.h"

void	ft_initshell(t_shell *shell, char *envp[])
{
	shell->cmd_amount = 0;
	shell->stdin = 0;
	shell->stdout = 1;
	shell->envp = ft_strdup_arr(envp);
	shell->cmd_table = NULL;
	ft_init_check_functions(shell);
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
}

// Não parece seguro dar free em cmd_table aqui. Ver depois. 
//ideia -> Liberar cmd_table com ft_clean pra garantir ponteiro pra nulo e prevenir double free
void	ft_clearshell(t_shell *shell)
{
	ft_free_arr((void **)shell->envp);
	/* for (int i = 0; i < shell->cmd_amount; i++)
		free(shell->cmd_table[i]);
	free(shell->cmd_table); */
	free(shell->cmd_table);
	free(shell->fcheck);
}

void	f1()
{
	printf("f1\n");
}
int	f2()
{
	printf("f2\n");
	return (0);
}
void	f3(int a)
{
	printf("f3 - %d\n", a);
}

void	ft_init_check_functions(t_shell *shell)
{
	shell->fcheck = malloc(sizeof(void *) * CHECKER_FUNCTION_COUNT);
	shell->fcheck[0] = f1;
	shell->fcheck[1] = f2;
	shell->fcheck[2] = f3;
}