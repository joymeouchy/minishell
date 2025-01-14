/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhoury <lkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:52:33 by lkhoury           #+#    #+#             */
/*   Updated: 2025/01/14 16:08:04 by lkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int check_if_word_or_command(t_list_node *temp)
{
		
}
void tokenize(t_list *list)
{
	t_list_node *temp;

	temp = list->head;
	while (temp)
	{
		if (temp->data[0] == '|')
			temp->token = 0;
		else if (temp->data[0] == '<' && temp->data[1] == '>')
			temp->token = 4;
		else if (temp->data[0] == '>' && temp->data[1] == '>')
			temp->token = 5;
		else if (temp->data[0] == '<')
			temp->token = 2;
		else if (temp->data[0] == '>')
			temp->token = 3;
		else
			check_if_word_or_command(temp);

}
}
typedef	enum e_tokens
{
	PIPE = 0,
	COMMAND = 1,
	LEFT_REDIRECTION = 2,
	RIGHT_REDIRECTION = 3,
	LEFT_D_REDIRECTION = 4,
	RIGHT_D_REDIRECTION = 5,
	WORD = 6
};
