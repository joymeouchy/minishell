/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhoury <lkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:50:44 by lkhoury           #+#    #+#             */
/*   Updated: 2025/04/23 17:06:38 by lkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void print_export(char **env)
// {
//     int i = 0;

//     while (env[i])
//     {
//         char *equal = ft_strchr(env[i], '=');
//         if (equal)
//         {
//             int key_len = equal - env[i];
//             char *key = ft_substr(env[i], 0, key_len);
//             char *value = ft_strdup(equal + 1);

//             if (key && value)
//                 printf("declare -x %s=\"%s\"\n", key, value);

//             free(key);
//             free(value);
//         }
//         else
//         {
//             printf("declare -x %s\n", env[i]);
//         }
//         i++;
//     }
// }

// int export(void)
// {
//     extern char **environ;

//     if (!environ)
//         return (1);

//     print_export(environ);
//     return (0);
// }

static void print_key_value(char *env_var)
{
    char *equal;
    int key_len;
    char *key;
    char *value;
    
    equal = ft_strchr(env_var, '=');
    if (equal)
    {
        key_len = equal - env_var;
        key = ft_substr(env_var, 0, key_len);
        value = ft_strdup(equal + 1);
        if (key && value)
            printf("declare -x %s=\"%s\"\n", key, value);
        free(key);
        free(value);
    }
    else
        printf("declare -x %s\n", env_var);
}

static void sort_env(char **env)
{
    int i;
    int j;
    int swapped;
    char *tmp;

    swapped = 1;
    j = 1;
    i = 0;
    while (env[i])
        i++;
    while (swapped)
    {
        swapped = 0;
        j = 0;
        while (j < i - 1)
        {
            if (ft_strcmp(env[j], env[j + 1]) > 0)
            {
                tmp = env[j];
                env[j] = env[j + 1];
                env[j + 1] = tmp;
                swapped = 1;
            }
            j++;
        }
    }
}

void print_export(char **env)
{
    int i = 0;
    sort_env(env);
    while (env[i])
        print_key_value(env[i++]);
}

int export(void)
{
    extern char **environ;
    if (!environ)
        return (1);
    print_export(environ);
    return (0);
}
