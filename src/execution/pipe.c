/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:51:42 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/13 17:38:29 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char *preserve_fds()
// {
//     char *fd
// }

int	*right_node(t_tree_node *node, int *pipefd)
{
	int	fd;

	dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	close(pipefd[0]);
	return (pipefd);
}

int	*left_node(t_tree_node *node, int *pipefd)
{
	int	fd;

	dup2(fd, 1);
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	close(pipefd[1]);
	return (pipefd);
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
		node->right->pipefd = right_node(node->left, pipefd);
	wait(&status);
	node->left->pipefd = left_node(node->right, pipefd);
	return (0);
}