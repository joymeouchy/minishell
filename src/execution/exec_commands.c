/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:04:58 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/14 11:30:21 by jmeouchy         ###   ########.fr       */
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

char *get_path_with_command(t_tree_node *node)
{
    char	*path_command;
	int		i;

	i = 0;
	while (node->path->split_path[i])
	{
		path_command = ft_strjoin(node->path->split_path[i], node->data);
		if (access(path_command, X_OK | F_OK) == 0)
		{
			return (path_command);
		}
		free(path_command);
		i++;
	}
	return (NULL);
}

void    exec_cmd(t_tree_node *node)
{
    t_tree_node *arg;
    char *path;
    int         fd;
    
    arg = node->right;
    while(arg->right)
    {
        fd = open(arg->data ,O_WRONLY | O_TRUNC | O_CREAT | O_RDONLY, 0777);
        if(fd < 0)
        {
            path = get_path_with_command(arg);
            if (!path)
                return ;
            execve(path, &arg->data, arg->path->environment);
        }
    }
}


void exec_commands(t_tree_node *node)
{
    if (node->token == BUILT_IN)
        exec_builtin(node);
    if (node->token == COMMAND)
        exec_cmd(node);
}
