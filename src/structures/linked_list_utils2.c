/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:42:48 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/02/06 17:03:32 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"

void	print_list(t_list *list)
{
	t_list_node	*temp;

	if (!list || !list->head)
		return ;
	list->head->index = 0;
	temp = list->head;
	printf("list:\n");
	while (temp)
	{
		if (temp->data)
			printf("index %d node:%s\n", temp->index, temp->data);
		else if (temp->data == NULL)
				printf("index %d node:NULL\n", temp->index);
		temp = temp->next;
	}
}

void	update_list_index(t_list_node *temp)
{
	while (temp != NULL)
	{
		temp->index++;
		temp = temp->next;
	}
}

t_list_node	*get_last_node(t_list *list)
{
	t_list_node	*temp;

	if (!list->head)
		return (NULL);
	temp = list->head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_list_node	*get_first_node(t_list *list)
{
	if (!list->head)
		return (NULL);
	return (list->head);
}

t_list_node	*get_node_at_index(t_list *list, int index)
{
	t_list_node	*temp;

	if (!list->head)
		return (NULL);
	temp = list->head;
	while (temp->next && temp->index < index)
		temp = temp->next;
	return (temp);
}
