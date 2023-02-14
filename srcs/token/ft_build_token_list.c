#include "minishell.h"

 void	get_tokens(t_list **token_lst, char **cmd);

void printf_list(void *content)
{
	printf("oi\n");
	ft_printf("%s\n", (char *) content);
}

void	ft_build_token_list(t_shell *shell, char **input)
{
	int	i;

	i = -1;
	while (++i < shell->cmd_amount)
	{
		printf("%p\n", &shell->cmd_table[i].tokens);
		get_tokens(&shell->cmd_table[i].tokens, ft_split(input[i], ' '));
	}
	ft_printf("Tokens built %d\n", shell->cmd_table[0].tokens == NULL);
	ft_lstiter(shell->cmd_table[0].tokens, printf_list);
	ft_free_arr((void **)input);
}


 void	get_tokens(t_list **token_lst, char **cmd)
{
	int	i;
	int j;
	int k;

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
				ft_lstadd_front(token_lst, ft_lstnew(ft_substr(cmd[i], k, j - k)));
				k = j + 1 + cmd[i][j + 1] == ' ';
			}
			j++;
		}
		i++;
	}
	ft_free_arr((void **)cmd);
}
