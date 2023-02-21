/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:59:55 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/21 13:59:55 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_tokens(t_shell *shell, t_list **token_lst, char *cmd);

void	printf_list(t_list *lst)
{
	ft_printf("Token: %s [%d]\n", (char *) lst->content, lst->type);
}

void	ft_build_token_list(t_shell *shell, char **input)
{
	int	i;

	i = -1;
	while (++i < shell->cmd_amount)
	{
		get_tokens(shell, &shell->cmd_table[i].tokens, input[i]);
		ft_lstiter(shell->cmd_table[i].tokens, printf_list);
	}
	ft_free_arr((void **)input);
}

void	get_tokens(t_shell *shell, t_list **token_lst, char *cmd)
{
	int	i;
	int	k;
	int	byts_read;

	byts_read = 0;
	i = 0;
	k = 0;
	while (cmd[i])
	{
		k = 0;
		while (k < CHECKER_FUNCTION_COUNT && cmd[i])
		{
			byts_read = ((int (*)())shell->fcheck[k])(shell, token_lst, cmd,
					i, k);
			if (byts_read >= ((int)ft_strlen(cmd)))
				break ;
			i = i + byts_read;
			k++;
		}
		break ;
	}
}
