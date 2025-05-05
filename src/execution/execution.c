/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:41:59 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/01 21:03:41 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void execution(t_tree_node *node)
{
    if (!node)
        retrun ;
    if (node->toke == PIPE)
        //TO-DO PIPE;
    if (node->token == COMMAND || node->toke == BUILT_IN)
        //TO-DO COMMAND/BUILTIN EXEC
    if (node->token >= 3 && node->token <= 6)
        //TO-DO REDIR
    execution(node->right);
    execution(node->left);
}