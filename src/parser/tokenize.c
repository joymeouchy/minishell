/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:23:04 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/01/31 23:27:09 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	tokenize(t_list *list)
{
	t_list_node	*temp;
	int			is_first_command;

	temp = list->head;
	is_first_command = 1;
	while (temp)
	{
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
		else if (ft_strchr(temp->data, '*'))
			temp->token = WILDCARD;
		else if (is_builtin(temp->data))
			temp->token = BUILT_IN;
		else if (is_first_command)
		{
			temp->token = COMMAND;
			is_first_command = 0;
		}
		else
			temp->token = WORD;
		if (temp->token == PIPE)
			is_first_command = 1;
		temp = temp->next;
	}
}
