/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:41:59 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/16 10:49:33 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void execution(t_tree_node *node)
{
    if (!node)
        return ;

    if (node->token == PIPE)
        return (pipe_exec(node));
    if (node->token == COMMAND || node->token == BUILT_IN)
        return (exec_commands(node));
    // if (node->token >= 3 && node->token <= 6)
        //TO-DO REDIR
}