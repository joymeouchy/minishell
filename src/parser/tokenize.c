/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:23:04 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/02/13 11:34:33 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int     ft_strcmp(char *s1, char *s2)
{
    int     i;

    i = 0;
     while (s1[i] != '\0' && s1[i] == s2[i])
            i++;
    return (s1[i] - s2[i]);
}

int	check_builtin(char *data)
{
	char	*builtins[8];
	int		i;

	i = 0;
	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	builtins[7] = NULL;
	while (builtins[i])
	{
		if (ft_strcmp(data, builtins[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}


int is_command(char *cmd, t_envp *envp)
{
	char	*full_path;
	int		i = 0;

	while (envp->split_path[i])
	{
		full_path = malloc(strlen(envp->split_path[i]) + strlen(cmd) + 1);
		if (!full_path)
			return (0);
		strcpy(full_path, envp->split_path[i]);
		strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
		{
			free(full_path);
			return (1);
		}
		free(full_path);
		i++;
	}
	return (0);
}


// char	*find_the_word_path_in_envp(char **envp)
// {
// 	if (!envp || !*envp)
//     	return (NULL);
// 	while (*envp)
// 	{
// 		if (ft_strnstr(*envp, "PATH=", 5))
// 			return (*envp + 5);
// 		envp++;
// 	}
// 	return (NULL);
// }

// int is_command(char *cmd, char **envp)
// {
// 	char	*path_env = find_the_word_path_in_envp(envp);
// 	char	**paths;
// 	char	*full_path;
// 	int		i = 0;

// 	if (!path_env)
// 		return (0);
// 	paths = ft_split(path_env, ':');
// 	while (paths[i])
// 	{
// 		full_path = malloc(strlen(paths[i]) + strlen(cmd) + 2);
// 		if (!full_path)
// 			return (0);
// 		strcpy(full_path, paths[i]);
// 		strcat(full_path, "/");
// 		strcat(full_path, cmd);
// 		if (access(full_path, X_OK) == 0)
// 		{
// 			free(full_path);
// 			return (1);
// 		}
// 		free(full_path);
// 		i++;
// 	}
// 	return (0);
// }


// void	tokenize(t_list *list)
// {
// 	t_list_node	*temp;
// 	// int			is_first_command;

// 	temp = list->head;
// 	// is_first_command = 1;
// 	while (temp)
// 	{
// 		if (temp->data[0] == '|')
// 			temp->token = PIPE;
// 		else if (temp->data[0] == '<' && temp->data[1] == '<')
// 			temp->token = LEFT_D_REDIRECTION;
// 		else if (temp->data[0] == '>' && temp->data[1] == '>')
// 			temp->token = RIGHT_D_REDIRECTION;
// 		else if (temp->data[0] == '<')
// 			temp->token = LEFT_REDIRECTION;
// 		else if (temp->data[0] == '>')
// 			temp->token = RIGHT_REDIRECTION;
// 		else if (temp->data[0] == '~')
// 			temp->token = TILDE;
// 		else if (check_builtin(temp->data))
// 			temp->token = BUILT_IN;
// 		// else if (is_first_command)
// 		// {
// 		// 	temp->token = COMMAND;
// 		// 	is_first_command = 0;
// 		// }
// 		else
// 			temp->token = WORD;
// 		// if (temp->token == PIPE)
// 			// is_first_command = 1;
// 		printf("im token %d\n",temp->token);
// 		temp = temp->next;
// 	}
// 	printf("done token\n");
// }

void tokenize(t_list *list, t_envp *envp)
{
    t_list_node *temp;
	
	temp = list->head;
    while (temp)
    {
        if (!temp->data)
            return;
        if (temp->data[0] == '|')
            temp->token = PIPE;
        else if (temp->data[0] == '<' && temp->data[1] == '<')
            temp->token = LEFT_D_REDIRECTION;
        else if (temp->data[0] == '>' && temp->data[1] == '>')
            temp->token = RIGHT_D_REDIRECTION;
        else if (temp->data[0] == '<')
            temp->token = LEFT_REDIRECTION;
        else if (temp->data[0] == '>')
            temp->token = RIGHT_REDIRECTION;
        else if (temp->data[0] == '~')
            temp->token = TILDE;
        else if (check_builtin(temp->data))
            temp->token = BUILT_IN;
        else if (is_command(temp->data, envp))
            temp->token = COMMAND;
        else
            temp->token = WORD;

        printf("Token assigned: %d\n", temp->token);
        temp = temp->next;
    }
}


