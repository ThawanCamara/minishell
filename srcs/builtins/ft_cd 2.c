/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:13:10 by tde-souz          #+#    #+#             */
/*   Updated: 2023/02/23 14:13:10 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cd_home(t_shell *shell)
{
	DIR		*dir;
	char	**env;
	char	*cwd;

	env = ft_getenv("HOME", shell->envp);
	if (env == NULL)
		return (ft_error_msg("Like spiderman, no way home", 1));
	dir = opendir(env[1]);
	if (dir == NULL)
	{
		ft_free_arr((void **) env);
		return (ft_error_msg("Could not open the directory", 1));
	}
	cwd = getcwd(NULL, 0);
	shell->envp = ft_setenv("OLDPWD", cwd, shell->envp);
	shell->envp = ft_setenv("PWD", env[1], shell->envp);
	chdir(env[1]);
	closedir(dir);
	free(cwd);
	ft_free_arr((void **) env);
	return (0);
}

int	cd_previous(t_shell *shell)
{
	DIR		*dir;
	char	**env[2];

	env[0] = ft_getenv("PWD", shell->envp);
	if (env[0] == NULL)
		return (ft_error_msg("cd : PWD not set", 1));
	env[1] = ft_getenv("OLDPWD", shell->envp);
	if (env[1] == NULL)
	{
		ft_free_arr((void **) env[0]);
		return (ft_error_msg("cd : OLDPWD not set", 1));
	}
	dir = opendir(env[1][1]);
	if (dir == NULL)
	{
		ft_nfree_arr(2, env[0], env[1]);
		return (ft_error_msg("Could not open the directory", 1));
	}
	shell->envp = ft_setenv("OLDPWD", env[0][1], shell->envp);
	shell->envp = ft_setenv("PWD", env[1][1], shell->envp);
	chdir(env[1][1]);
	closedir(dir);
	printf("%s\n", env[1][1]);
	ft_nfree_arr(2, env[0], env[1]);
	return (0);
}

int	cd_path(t_shell *shell, char *path)
{
	DIR		*dir;
	char	*cwd;

	dir = opendir(path);
	if (dir == NULL)
		return (ft_error_msg("Could not open the directory", 1));
	cwd = getcwd(NULL, 0);
	shell->envp = ft_setenv("OLDPWD", cwd, shell->envp);
	free(cwd);
	chdir(path);
	cwd = getcwd(NULL, 0);
	shell->envp = ft_setenv("PWD", cwd, shell->envp);
	free(cwd);
	closedir(dir);
	return (0);
}

int	ft_cd(t_shell *shell, char *argv[])
{
	int	ret;

	ret = 0;
	if (!argv)
		return (1);
	else if (argv[1] == NULL)
		ret = cd_home(shell);
	else if (ft_strncmp(argv[1], "-", 2) == 0)
		ret = cd_previous(shell);
	else
		ret = cd_path(shell, argv[1]);
	return (ret);
}
