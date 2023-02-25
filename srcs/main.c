/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:14:28 by psydenst          #+#    #+#             */
/*   Updated: 2023/02/21 15:13:24 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print(char *s)
{
	ft_printf("%s ", s);
}

// int	main(int argc, char *argv[], char **envp)
// {
// 	t_shell	shell;

// 	//char *args1[] = {"echo", "-ne", "desgraça de projeto", "insuportavel", 0};
// 	//char *args2[] = {"export", "KEY2=VALUE2", 0};
// 	//char *args3[] = {"export", "KEY3=", 0};
// 	// char *args4[] = {"unset", "HOME", 0};
// 	//char *args5[] = {"cd", "../", 0};
// 	//char *args6[] = {"cd", "-", 0};
// 	//char *args7[] = {"exit", "12345", 0};

// 	char *path = "/bin/lsd";
// 	char *args8[] = {path, "-l", 0};

// 	(void) argc;
// 	(void) argv;
// 	ft_signal_handler();
// 	ft_initshell(&shell, envp);
	
// 	int status = ft_exec(path, args8, shell.envp);
// 	printf("Return status: %d\n", status);
		
// 	ft_clearshell(&shell);
// 	//ft_echo(&shell, args1);
// 	// ft_unset(&shell, args4);
	
// 	//printf("RS: %d\n", ft_exit(&shell, args7));
// 	// ft_cd(&shell, args6);
// 	// ft_cd(&shell, args6);
	
// 	// char **env1;
// 	// char **env2;
// 	// ft_cd(&shell, args5);
// 	// env1 = ft_getenv("OLDPWD", shell.envp);
// 	// env2 = ft_getenv("PWD", shell.envp);
// 	// if (env1)
// 	// 	ft_printf("OLDPWD: %s\n", env1[1]);
// 	// if (env2)
// 	// 	ft_printf("PWD: %s\n", env2[1]);
// 	// ft_nfree_arr(2, env1, env2);
// 	// ft_cd(&shell, args5);
// 	// env1 = ft_getenv("OLDPWD", shell.envp);
// 	// env2 = ft_getenv("PWD", shell.envp);
// 	// if (env1)
// 	// 	ft_printf("OLDPWD: %s\n", env1[1]);
// 	// if (env2)
// 	// 	ft_printf("PWD: %s\n", env2[1]);
// 	// ft_nfree_arr(2, env1, env2);

// 	//ft_pwd();
// 	//minishell(&shell);
// 	//ft_env(&shell);
// 	return (0);
// }


	// ft_export(&shell, args1);
	// ft_export(&shell, args2);
	// ft_export(&shell, args3);
	// ft_unset(&shell, args4);
	// printf("return status: %d\n", ft_echo(&shell, args1));

void execute(int numsimplecommands, char *infile, char *outfile, char **scmd[], int background, char *envp[]);

int	main(int argc, char *argv[], char **envp)
{
	(void) argc;
	(void) argv;

	char *args1[] = {"/bin/ls", "-l", 0};
	char *args2[] = {"/bin/grep", "libft", 0};
	char *args3[] = {"/bin/wc", "-l", 0};

	char **argvs[] = {args1, args2, args3, 0};
	// ft_striter(argvs[0], print);
	// ft_striter(argvs[1], print);
	// ft_striter(argvs[2], print);
	execute(3, NULL, NULL, argvs, 0, envp);
	//execute(3, NULL, "file", argvs, 0, envp);
	return (0);
}

void execute(int numsimplecommands, char *infile, char *outfile, char **scmd[], int background, char *envp[]){
	//savein/out
	int	tmpin = dup(0);
	int	tmpout = dup(1);

	// int myfd = dup(1);
	//settheinitialinput
	int	fdin;
	if (infile){
		fdin = open(infile, O_RDONLY);
	}
	else{
	//Usedefaultinput
		fdin = dup(tmpin);
	}	
	int	pid;
	int	fdout;
	for (int i = 0; i < numsimplecommands; i++)
	{
		// dprintf(myfd, "> %s\n", scmd[i][0]);
		//redirectinput
		dup2(fdin, 0);
		close(fdin);
		//setupoutput
		if (i == numsimplecommands - 1){
			//Lastsimplecommand
			if (outfile){
				fdout = open(outfile, O_RDWR | O_CREAT);
			}
			else {
			// Use default output
				fdout = dup(tmpout);
			}
		}
		else {
			// Not last 
			//simple command
			//create pipe
			int fdpipe[2];
			if (pipe(fdpipe) < 0)
				perror("Error on piping\n");
			fdout = fdpipe[1];
			fdin = fdpipe[0];
		}// if/else
		// Redirect output
		dup2(fdout, 1);
		close(fdout);
		// Create child process
		pid = fork();
		if (pid == 0){
			// execvp(scmd[i].args[0], scmd[i].args);
			if (execve(scmd[i][0], scmd[i], envp) < 0)
			{
				perror("execve error\n");
				exit(0);
			}
			perror("execvp");
			//exit(1);
		}
	}//  for
	//restore in/out defaults
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	if (!background){
		// Wait for last command
		waitpid(pid, NULL, 0);
	}
}// execute 