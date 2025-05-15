/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:41:59 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/15 14:53:38 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void execution(t_tree_node *node)
{
    if (!node)
        return ;
    // if (node->token == PIPE)
        //TO-DO PIPE;
    if (node->token == COMMAND || node->token == BUILT_IN)
        exec_commands(node);
    // if (node->token >= 3 && node->token <= 6)
        //TO-DO REDIR
    execution(node->right);
    execution(node->left);
}