/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:42:48 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/04/24 18:37:08 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tree	*init_tree(void)
{
	t_tree	*tree;

	tree = malloc(sizeof(t_tree));
	tree->root = NULL;
	return (tree);
}

void	print_inorder(t_tree_node *node)
{
	if (node == NULL)
		return ;
	print_inorder(node->left);
	printf("Data: %s, Token: %d\n", node->data, node->token);
	print_inorder(node->right);
}

t_tree_node	*create_tree_node(char *data, e_tokens token, bool *flag_inserted_node)
{
	t_tree_node	*new_node;

	new_node = (t_tree_node *)malloc(sizeof(t_tree_node));
	new_node->data = data;
	new_node->token = token;
	new_node->left = NULL;
	new_node->right = NULL;
	*flag_inserted_node = true;
	return (new_node);
}

bool check_pipe_precendence(e_tokens current_token, t_tree_node *node)
{
	if (node == NULL)
		return (true);
	if (current_token == PIPE && current_token < node->token)
		return (false);
	else
		return (true);
	
}


bool check_builtin_cmd(t_tree_node *node)
{
	if (node == NULL)
		return (true);
	if (node->token == BUILT_IN || node->token == COMMAND)
		return (false);
	else
		return (true);
}

bool check_word_cmd_branches(t_tree_node *node, t_tree_node *node_direction)
{
	if (node == NULL)
		return (true);
	// if ((node->token == WORD || node->token == COMMAND || node->token == BUILT_IN)
	// 	&& (current_token == COMMAND || current_token == BUILT_IN))
	// 	return (false);
	if ((node->token == WORD || node->token == COMMAND || node->token == BUILT_IN) && node_direction != NULL)
		return (true);
	else
		return (true);
}

t_tree_node *insert(t_tree_node *node, char *data, e_tokens token, bool *flag_inserted_node)
{
    if (node == NULL)
	{
        return (create_tree_node(data, token, flag_inserted_node));
	}
	if (*flag_inserted_node == false
		&& check_pipe_precendence(token, node->right)
		&& check_word_cmd_branches(node, node->left)
		)
	{
		node->right = insert(node->right, data, token, flag_inserted_node);
	}
	if (*flag_inserted_node == false
		&& check_pipe_precendence(token, node->left)
		&& check_word_cmd_branches(node, node->right)
	)
	{
		node->left = insert(node->left, data, token, flag_inserted_node);
	}
    return (node);
}

t_tree	*stack_to_tree(t_stack *stack)
{
	t_tree	*tree;
	bool	flag_inserted_node;

	tree = init_tree();
	flag_inserted_node = false;
	tree->root = create_tree_node(stack->stack[stack->top].data,
			stack->stack[stack->top].token, &flag_inserted_node);
	stack->top--;
	while (stack->top > -1)
	{
		flag_inserted_node = false;
		tree->root = insert(tree->root, stack->stack[stack->top].data,
				stack->stack[stack->top].token, &flag_inserted_node);
		stack->top--;
	}
	return (tree);
}
