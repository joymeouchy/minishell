/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:23:04 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/02/12 13:47:21 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*find_the_word_path_in_envp(char **envp)
{
    if (!envp || !*envp)
        return (NULL);
    while (*envp)
    {
        if (ft_strnstr(*envp, "PATH=", 5))
            return (*envp + 5);
        envp++;
    }
    return (NULL);
}
t_envp *get_split_path(char **envp)
{
    t_envp  *envp;
    char   **path;
    int i;

    envp->split_path = ft_split(find_the_word_path_in_envp(envp), ':');
    i = 0;
    while(envp->split_path[i])
    {
        envp->split_path[i] = ft_strjoin(envp->split_path[i], "/");
        i++;
    }
    return(envp);
}

