/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 19:50:44 by lkhoury           #+#    #+#             */
/*   Updated: 2025/05/22 21:23:01 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// static void print_key_value(char *env_var)
// {
//     char *equal;
//     int key_len;
//     char *key;
//     char *value;
    
//     equal = ft_strchr(env_var, '=');
//     if (equal)
//     {
//         key_len = equal - env_var;
//         key = ft_substr(env_var, 0, key_len);
//         value = ft_strdup(equal + 1);
//         if (key && value)
//             printf("declare -x %s=\"%s\"\n", key, value);
//         free(key);
//         free(value);
//     }
//     else
//         printf("declare -x %s\n", env_var);
// }

// static void sort_env(char **env)
// {
//     int i;
//     int j;
//     int swapped;
//     char *tmp;

//     swapped = 1;
//     j = 1;
//     i = 0;
//     while (env[i])
//         i++;
//     while (swapped)
//     {
//         swapped = 0;
//         j = 0;
//         while (j < i - 1)
//         {
//             if (ft_strcmp(env[j], env[j + 1]) > 0)
//             {
//                 tmp = env[j];
//                 env[j] = env[j + 1];
//                 env[j + 1] = tmp;
//                 swapped = 1;
//             }
//             j++;
//         }
//     }
// }

// void print_export(char **env)
// {
//     int i = 0;
//     sort_env(env);
//     while (env[i])
//         print_key_value(env[i++]);
// }

// int export(void)
// {
//     extern char **environ;
//     if (!environ)
//         return (1);
//     print_export(environ);
//     return (0);
// }

static int is_valid_key(const char *str) {
	int i = 0;
	if (!str || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	while (str[i] && str[i] != '=') {
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int count_env_vars(char **env) {
	int count = 0;
	while (env && env[count])
		count++;
	return count;
}

// Safely duplicate original environment once
static void duplicate_environment(t_envp *env) {
	int size = count_env_vars(env->environment);
	int i = 0;
	char **copy = malloc(sizeof(char *) * (size + 1));
	if (!copy)
		return;
	while (i < size) {
		copy[i] = ft_strdup(env->environment[i]);
		i++;
	}
	copy[i] = NULL;
	env->environment = copy;
}

static void update_env(char *arg, t_envp *env) {
	int i = 0;
	int key_len;
	char *key;
	char *equal;
	int size;
	char **new_env;

	equal = ft_strchr(arg, '=');
	if (!equal)
		return;

	key_len = equal - arg;
	key = ft_substr(arg, 0, key_len);
	if (!key)
		return;

	// First time update — duplicate original env if needed
	if (env->environment && !ft_strchr(env->environment[0], '=')) {
		duplicate_environment(env);
	}

	while (env->environment && env->environment[i]) {
		if (ft_strncmp(env->environment[i], key, key_len) == 0 &&
			env->environment[i][key_len] == '=') {
			free(env->environment[i]);
			env->environment[i] = ft_strdup(arg);
			free(key);
			return;
		}
		i++;
	}

	size = count_env_vars(env->environment);
	new_env = malloc(sizeof(char *) * (size + 2));
	if (!new_env) {
		free(key);
		return;
	}

	i = 0;
	while (env->environment && env->environment[i]) {
		new_env[i] = env->environment[i];
		i++;
	}
	new_env[i++] = ft_strdup(arg);
	new_env[i] = NULL;

	free(env->environment);
	env->environment = new_env;
	free(key);
}

static void print_key_value(char *env_var) {
	char *equal = ft_strchr(env_var, '=');
	int key_len;
	char *key;
	char *value;
	if (equal) {
		key_len = equal - env_var;
		key = ft_substr(env_var, 0, key_len);
		value = ft_strdup(equal + 1);
		if (key && value)
			printf("declare -x %s=\"%s\"\n", key, value);
		free(key);
		free(value);
	} else
		printf("declare -x %s\n", env_var);
}

static void sort_env(char **env) {
	int i = 0, j, swapped;
	char *tmp;
	while (env[i])
		i++;
	swapped = 1;
	while (swapped) {
		swapped = 0;
		j = 0;
		while (j < i - 1) {
			if (ft_strcmp(env[j], env[j + 1]) > 0) {
				tmp = env[j];
				env[j] = env[j + 1];
				env[j + 1] = tmp;
				swapped = 1;
			}
			j++;
		}
	}
}

int export(t_tree_node *root, t_envp *env) {
	t_tree_node *arg;

	if (!root || !env || !env->environment)
		return (1);

	arg = root->right;

	// No args → print
	if (!arg) {
		sort_env(env->environment);
		for (int i = 0; env->environment[i]; i++)
			print_key_value(env->environment[i]);
		return (0);
	}

	// With args → update
	while (arg) {
		if (is_valid_key(arg->data))
			update_env(arg->data, env);
		else
			printf("minishell: export: `%s': not a valid identifier\n", arg->data);
		arg = arg->right;
	}
	return (0);
}

