/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:52:33 by lkhoury           #+#    #+#             */
/*   Updated: 2025/01/17 10:12:27 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	check_if_word_or_command(t_list_node *temp)
// {
// }

void	tokenize(t_list *list)
{
	t_list_node	*temp;

	temp = list->head;
	while (temp)
	{
		if (temp->data[0] == '|')
			temp->token = 0;
		else if (temp->data[0] == '<' && temp->data[1] == '>')
			temp->token = 5;
		else if (temp->data[0] == '>' && temp->data[1] == '>')
			temp->token = 6;
		else if (temp->data[0] == '<')
			temp->token = 3;
		else if (temp->data[0] == '>')
			temp->token = 4;
		else
			temp->token = 7;
		temp = temp->next;
	}
}
