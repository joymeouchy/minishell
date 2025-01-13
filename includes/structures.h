/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:16:36 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/01/13 11:29:06 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

///linked list///
typedef struct s_list_node
{
	struct s_list_node	*next;
	struct s_list_node	*prev;
	char				*data;
	int					index;
}	t_list_node;

typedef struct s_list
{
	t_list_node	*head;
	int		list_size;
}	t_list;

//tree//


//stack//

///free_structures.c///
void		free_list(t_list *list);

///linked list functions//
///linked_list_utils.c///
t_list		*init_list(void);
t_list_node	*create_list_node(char *data);
void		insert_at_end_list(t_list *list, char *new_node_data);
void		insert_at_beginning_list(t_list *list, char *new_node_data);
void		insert_at_middle_list(t_list *list, char *new_node_data, int index);

///linked_list_utils2.c///

void	print_list(t_list *list);
void	update_list_index(t_list_node *temp);
t_list_node	*get_last_node(t_list *list);
t_list_node	*get_first_node(t_list *list);
t_list_node	*get_node_at_index(t_list *list, int index);

///tree functions//
///tree_utils.c///

///stack functions//
///stack_utils.c///

#endif