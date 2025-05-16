/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:51:42 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/16 10:53:24 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char *preserve_fds()
// {
//     char *fd
// }

void left_node(t_tree_node *node, int pipefd[2])
{
	// write(1, "i am in right node\n", 20);
	dup2(pipefd[0], 0);  // Read from pipe
	close(pipefd[0]);
	close(pipefd[1]);
	execution(node->left); // Execute right node command
	exit(0); // Important: exit after execution
}

void right_node(t_tree_node *node, int pipefd[2])
{
	// write(1, "i am in right node\n", 19);
	dup2(pipefd[1], 1);  // Write to pipe
	close(pipefd[0]);
	close(pipefd[1]);
	execution(node->right); // Execute left node command
	exit(0); // Important: exit after execution
}

void pipe_exec(t_tree_node *node)
{
	int pipefd[2];
	pid_t left_pid, right_pid;
	int status;

	if (pipe(pipefd) == -1)
		return ;

	left_pid = fork();
	if (left_pid == -1)
		return ;
	if (left_pid == 0)
		left_node(node, pipefd);

	right_pid = fork();
	if (right_pid == -1)
		return ;
	if (right_pid == 0)
		right_node(node, pipefd);


	// Parent: close pipe
	close(pipefd[0]);
	close(pipefd[1]);

	waitpid(left_pid, &status, 0);
	waitpid(right_pid, &status, 0);

	
}
