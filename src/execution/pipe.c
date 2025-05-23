/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:51:42 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/23 11:06:02 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void left_node(t_tree_node *node, int pipefd[2])
{
	dup2(pipefd[0], 0);  // stdin = read end
	close(pipefd[0]);
	close(pipefd[1]);
	execution(node->left);
	exit(0);
}

void right_node(t_tree_node *node, int pipefd[2])
{
	dup2(pipefd[1], 1);  // stdout = write end
	close(pipefd[0]);
	close(pipefd[1]);
	execution(node->right);
	exit(0);
}
void pipe_exec(t_tree_node *node)
{
    int     pipefd[2];
    pid_t   right_pid;
    pid_t   left_pid;

    if (pipe(pipefd) == -1)
        return;
    right_pid = fork();
    if (right_pid == -1)
        return;
    if (right_pid == 0)
    {
        if (node->right->token == PIPE || node->left->token == PIPE)
            left_node(node->left, pipefd);
        else
            right_node(node, pipefd);
        exit(1); // Should not reach
    }
    left_pid = fork();
    if (left_pid == -1)
        return;
    if (left_pid == 0)
    {
       if (node->right->token == PIPE || node->left->token == PIPE)
            right_node(node->right, pipefd);
        else
            left_node(node, pipefd);
        exit(1); // Should not reach
    }
    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(right_pid, NULL, 0);
    waitpid(left_pid, NULL, 0);
}
