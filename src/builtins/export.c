/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhoury <lkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:50:44 by lkhoury           #+#    #+#             */
/*   Updated: 2025/04/11 20:15:11 by lkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void print_export(char **env)
{
    int i = 0;

    while (env[i])
    {
        char *equal = ft_strchr(env[i], '=');
        if (equal)
        {
            int key_len = equal - env[i];
            char *key = ft_substr(env[i], 0, key_len);
            char *value = ft_strdup(equal + 1);

            if (key && value)
                printf("declare -x %s=\"%s\"\n", key, value);

            free(key);
            free(value);
        }
        else
        {
            printf("declare -x %s\n", env[i]);
        }
        i++;
    }
}

int export(void)
{
    extern char **environ;

    if (!environ)
        return (1);

    print_export(environ);
    return (0);
}
