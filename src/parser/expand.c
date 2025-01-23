/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 19:47:40 by root              #+#    #+#             */
/*   Updated: 2025/01/23 13:29:23 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_dollar(char *str)
{
	int	i;
	int	in_single_quote;
	int	in_double_quote;

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
			return (i);
		i++;
	}
	return (-1);
}

char	*extract_variable_name(char *str)
{
	int	i;
	int	start;

	i = 0;
	if (!str || str[i] != '$')
		return (NULL);
	i++;
	if (str[i] == '?')
		return (ft_strdup("?"));
	start = i;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	return (ft_substr(str, start, i - start));
}

char	*replace_variable(char *str, char *var_name,
	char *replacement, int dollar_pos)
{
	char	*before;
	char	*after;
	char	*result;
	char	*temp;

	before = ft_substr(str, 0, dollar_pos);
	after = ft_substr(str, dollar_pos
			+ ft_strlen(var_name) + 1, ft_strlen(str));
	result = ft_strjoin(before, replacement);
	temp = result;
	result = ft_strjoin(result, after);
	free(before);
	free(after);
	free(temp);
	return (result);
}

char	*expand(char *str)
{
	int		dollar_pos;
	char	*var_name;
	char	*replacement;
	char	*expanded_str;

	dollar_pos = find_dollar(str);
	while ((dollar_pos) != -1)
	{
		dollar_pos = find_dollar(str);
		var_name = extract_variable_name(&str[dollar_pos]);
		if (!var_name)
		{
			free(str);
			return (NULL);
		}
		replacement = getenv(var_name);
		if (!replacement)
			replacement = "";
		expanded_str = replace_variable(str, var_name, replacement, dollar_pos);
		free(str);
		str = expanded_str;
		free(var_name);
	}
	return (str);
}



