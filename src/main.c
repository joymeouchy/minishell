/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:56:20 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/05/22 16:42:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
    t_envp *env;

    signals();
    env = malloc(sizeof(t_envp));
    if (!env)
    {
        return (1);
    }
	env->split_path = get_split_path(envp);
    env->environment = envp;
	
    while (1)
	{
        parsing_main(env);
    }
    free(env);
    return (0);
}