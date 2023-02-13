/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/13 20:44:20 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_copy_envp(char *envp[])
{
	char	**ret;
	int		i;
	int		j;

	ret = 0;
	j = 0;
	i = 0;
	while (envp[j] != NULL)
		j++;
	ret = malloc(sizeof(char *) * j);
	while (i < j)
	{
		ret[i] = strdup(envp[i]);
		i++;
	}
	ret[i] = ft_strdup(NULL);
	return (ret);
}



void print(char *s)
{
	printf("%s\n", s);
}

void	nfree_arr(int n, ...)
{
	va_list args;
	void	**arr;
	
	va_start(args, n);
	while (n-- > 0)
	{
		arr = va_arg(args, void **);
		ft_striter((char **)arr, free);
		free(arr);
	}
	va_end(args);
}

//=================================

char *	ft_strdup_size(char *s1, int begin, int last)
{
	size_t	len;
	char	*ret;
	int		i;

	i = 0;
	if (s1 == NULL)
		return (0);
	len = last - begin + 1;
	ret = (char *)malloc(len * sizeof(char));
	if (ret == 0)
		return (0);
	while (begin <= last)
	{
		ret[i] = s1[begin];
		i++;
		begin++;
	}
	ret[i] = '\0';
	return (ret);
}

t_args	*ft_argsnew(void *content)
{
	t_args	*new_args;

	new_args = (t_args *)malloc(sizeof(t_args));
	if (new_args == 0)
		return (0);
	new_args->content = content;
	new_args->next = 0;
	new_args->type = -1;
	return (new_args);
}

void    create_list(char *str)
{
	int i;
	int j;
	t_args *new;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i + 1] == '|' || str[i] == '\0')
		{
			new = ft_argsnew(ft_strdup_size(str, j, i));
			printf("Valor de new->content: %s\n", (char *)new->content);
		}
		i++;
	}	
}

typedef struct s_args2
{
	void	*content;
	int		type;
} t_args2;

t_args2	*process_string(char *s)
{
	t_args2	*args2;
	char	*str;
	char	*tmp;

	tmp = ft_substr(s, 0, ft_strlen(s) - ft_strlen(ft_strchr(s, '|')));
	str = ft_strtrim(tmp, " \t\n\f\v");
	free(tmp);
	args2 = (t_args2 *)malloc(sizeof(t_args2));
	args2->content = (void *)str;
	args2->type = -1;
	return (args2);
}

t_list	**create_list2(char *input)
{
	t_list	**lst;
	int		i;

	if (input == NULL)
		return (NULL);
	lst = (t_list **)malloc(sizeof(t_list *));
	*lst = NULL;
	i = 0;
	while (ft_strchr(input + i, '|'))
	{
		ft_lstadd_back(lst, ft_lstnew(process_string((input + i))));
		i = ft_strlen(input) - ft_strlen(ft_strchr(input + i, '|')) + 1;
	}
	ft_lstadd_back(lst, ft_lstnew(process_string((input + i))));
	return (lst);
}

void print_lst(void *content)
{
	t_args2 *arg2;

	arg2 = (t_args2 *)content;
	ft_printf("%s [%d] \n", (char *)arg2->content, arg2->type);
}

void free_lst(void *content)
{
	t_args2 *arg2;

	arg2 = (t_args2 *)content;
	free(arg2->content);
	free(content);
}

int	main(int argc, char *argv[], char **envp)
{
	//t_data	data;
	//t_args	args;

	// char **s1 = ft_strdup_arr(argv);
	// char **s2 = ft_strdup_arr(argv);
	// ft_striter(s1, print);
	// ft_striter(s2, print);
	// nfree_arr(2, s1, s2);

	create_list("ls | ls -la | grep lost");
	t_list **lst = create_list2("ls | ls -la | grep lost");
	ft_lstiter(*lst, print_lst);
	ft_lstiter(*lst, free_lst);
	free(lst);

	// printf("%s==== Original ====%s\n", B_TEAL, RESET);
	// ft_striter(envp, print);
	// printf("%s==== Dup ====%s\n", B_TEAL, RESET);
	// ft_striter(s, free);
	// free(s);
	
	//free(data.env);
	//minishell(envp);
	(void) argc;
	(void) argv;
	(void) envp;
	//ft_exec();		
	return (0);
}
