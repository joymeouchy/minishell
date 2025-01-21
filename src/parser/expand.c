/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:47:40 by root              #+#    #+#             */
/*   Updated: 2025/01/21 12:25:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int find_dollar(char *str)
{
    int i;
    int in_single_quote;
    int in_double_quote;

    i = 0;
    in_single_quote = 0;
    in_double_quote = 0;
    while (str[i])
    {
        if (str[i] == '\'' && !in_double_quote)
            in_single_quote = !in_single_quote;
        else if (str[i] == '"' && !in_single_quote)
            in_double_quote = !in_double_quote;
        else if (str[i] == '$' && !in_single_quote)
            return i;
        i++;
    }
    return -1;
}

char *extract_variable_name(char *str)
{
    int i;
    int start;

    i = 0;
    if (!str || str[i] != '$')
        return NULL;
    i++;
    if (str[i] == '?')
        return ft_strdup("?");
    start = i;
    while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
        i++;
    return ft_substr(str, start, i - start);
}
