/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:51:42 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/12 18:36:06 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char *preserve_fds()
// {
//     char *fd
// }

void	child(t_tree_node *node, int *pipefd)
{
	int	fd;

	fd = open(argv[1], O_RDONLY, 0777);
	if (fd < 0)
	{
		perror("zsh");
		exit(1);
	}
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	close(pipefd[0]);
	ft_execute(envp, argv[2]);
}

void	parent(t_tree_node *node, int *pipefd)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd < 0)
	{
		perror("zsh");
		exit(1);
	}
	dup2(fd, 1);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	close(pipefd[1]);
	ft_execute(envp, argv[3]);
}

int	pipe_exec(t_tree_node *node)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (pipe(pipefd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		child(node->left, pipefd);
	wait(&status);
	parent(node->right, pipefd);
	return (0);
}