/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:04:58 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/02 12:59:00 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


void exec_builtin(t_tree_node *node)
{
    if(ft_strcmp(node->data, "echo"))
        echo(node);
    else if (ft_strcmp(node->data, "env"))
        //TO-DO CHECK ENV
    else if (ft_strcmp(node->data, "export"))
        export(); //TO-DO MAKE EXPORT WORK WITH ARGS
    else if (ft_strcmp(node->data, "pwd"))
        pwd(); //TO-DO 
        
}


void exec_commands(t_tree_node *node)
{
    if (node->token == BUILT_IN)
        exec_builtin(node);
    if (node->token == COMMAND)
        exec_cmd(node);
}
