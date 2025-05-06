/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:04:58 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/06 10:31:44 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void exec_builtin(t_tree_node *node)
{
    if (ft_strcmp(node->data, "echo") == 0)
        echo(node);
    // else if (ft_strcmp(node->data, "env"))
        //TO-DO CHECK ENV
    else if (ft_strcmp(node->data, "export") == 0)
        export(); //TO-DO MAKE EXPORT WORK WITH ARGS
    else if (ft_strcmp(node->data, "pwd") == 0)
        pwd(); //TO-DO 
    else if (ft_strcmp(node->data, "unset") == 0)
        unset(node); //TO-DO 
        
}


void exec_commands(t_tree_node *node)
{
    if (node->token == BUILT_IN)
        exec_builtin(node);
    // if (node->token == COMMAND)
        //exec_cmd(node);
}
