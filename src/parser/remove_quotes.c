/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 09:03:43 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/01/17 09:41:21 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	remove_quotes(t_list *list)
{
	t_list_node	*current_node;

	current_node = list->head;
	while(current_node->next)
	{
		if(current_node->token == 7)
		{
			printf("current node is: %s\n", current_node->data);
		}
		current_node = current_node->next;
	}
}