/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:16:36 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/01/28 11:26:51 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


typedef enum e_tokens
{
	PIPE = 0,
	COMMAND = 1,
	BUILT_IN = 2,
	LEFT_REDIRECTION = 3,
	RIGHT_REDIRECTION = 4,
	LEFT_D_REDIRECTION = 5,
	RIGHT_D_REDIRECTION = 6,
	WORD = 7,
	TILDE = 8,
	WILDCARD = 9
}	e_tokens;
///linked list///
typedef struct s_list_node
{
	struct s_list_node	*next;
	struct s_list_node	*prev;
	char				*data;
	int					index;
	enum e_tokens		token;
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