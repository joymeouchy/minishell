/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:16:36 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/03/31 20:26:12 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
#include <fcntl.h>


typedef enum e_tokens
{
	null = -1,
	PIPE = 0,
	COMMAND = 1,
	BUILT_IN = 2,
	LEFT_REDIRECTION = 3,
	RIGHT_REDIRECTION = 4,
	LEFT_D_REDIRECTION = 5,
	RIGHT_D_REDIRECTION = 6,
	WORD = 7,
	TILDE = 8,
}	e_tokens;

typedef struct s_redir
{
	enum e_tokens token;
	char *file;
}t_redir;

typedef struct s_envp
{
	char **split_path;
	
}t_envp;

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

typedef struct s_tree_node
{
	struct s_tree_node	*left;
	struct s_tree_node	*right;
	char				*data;
	enum e_tokens		token;
}	t_tree_node;

typedef struct s_tree
{
	t_tree_node	*root;
}	t_tree;

//stack//

typedef struct s_stack_element
{
    char *data;
    e_tokens token;
} t_stack_element;

typedef struct s_stack
{
	int top;
	t_stack_element	*stack;
} t_stack;

///free_structures.c///
void		free_list(t_list *list);
void free_stack(t_stack *stack);

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
void printInorder(t_tree_node *node);
t_tree *init_tree(void);
t_tree_node     *create_tree_node(char *data, e_tokens token, bool *flag_inserted_node);
t_tree_node *insert( t_tree_node *node, char *data, e_tokens token, bool *flag_inserted_node);
// void stack_to_tree(t_stack *stack);
///stack functions//
///stack_utils.c///
void    init_stack(t_list *list, t_stack *stack);
void push(char *data, e_tokens token, t_stack *stack);
// void push(char *data, t_stack *stack);

void pop(t_stack *stack);
void print_stack(t_stack *stack);
#endif