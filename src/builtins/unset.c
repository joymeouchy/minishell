/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhoury <lkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:06:11 by lkhoury           #+#    #+#             */
/*   Updated: 2025/04/23 17:20:55 by lkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_valid_var_name(const char *name)
{
	int	i = 0;

	if (!name || (!ft_isalpha(name[0]) && name[0] != '_'))
		return (0);
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	match_key(const char *env_entry, const char *key)
{
	int	i = 0;

	while (env_entry[i] && key[i] && env_entry[i] == key[i])
		i++;
	return (key[i] == '\0' && env_entry[i] == '=');
}

void	remove_env_entry(char **env, int index)
{
	while (env[index])
	{
		env[index] = env[index + 1];
		index++;
	}
}
void	remove_var_from_env(const char *var_name)
{
	extern char	**environ;
	int			j = 0;

	while (environ[j])
	{
		if (match_key(environ[j], var_name))
		{
			remove_env_entry(environ, j);
			break;
		}
		j++;
	}
}
int	unset(t_tree *tree)
{
	t_tree_node	*arg;

	if (!tree || !tree->root || !tree->root->right)
		return (0);
	arg = tree->root->right;
	while (arg)
	{
		if (is_valid_var_name(arg->data))
			remove_var_from_env(arg->data);
		arg = arg->right;
	}
	return (0);
}

