/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:05:32 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/04/26 15:02:40 by jmeouchy         ###   ########.fr       */
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
	printf("Data: %s, Token: %d\n", node->data, node->token);
	if (node->right)
		printf("right:%s\n", node->right->data);
	if(node->left)
		printf("left:%s\n", node->left->data);
	print_inorder(node->left);
	print_inorder(node->right);
}

// t_tree_node	*create_tree_node(char *data, e_tokens token, bool *flag_inserted_node)
// {
// 	t_tree_node	*new_node;

// 	new_node = (t_tree_node *)malloc(sizeof(t_tree_node));
// 	new_node->data = data;
// 	new_node->token = token;
// 	new_node->left = NULL;
// 	new_node->right = NULL;
// 	*flag_inserted_node = true;
// 	return (new_node);
// }

bool check_pipe_precendence(e_tokens current_token, t_tree_node *node)
{
	if (node == NULL)
		return (true);
	if (current_token == PIPE && current_token < node->token)
		return (false);
	else
		return (true);

}


bool check_builtin_cmd(e_tokens token,t_tree_node *node)
{
	if (node == NULL)
		return (true);
	if ((node->token == BUILT_IN || node->token == COMMAND) && (token == BUILT_IN || token == COMMAND))
		return (false);
	else
		return (true);
}

bool check_right_word_branches(t_tree_node *node, t_tree_node *node_direction)
{
	if (node == NULL)
		return (true);
	if (node->token == WORD && node_direction != NULL)
		return (false);
	else
		return (true);
}


void swap_parent_and_child(t_tree_node *parent, t_tree_node *child)
{
    if (!parent || !child)
        return;

    e_tokens temp_token = parent->token;
    char *temp_data = parent->data;

    parent->data = child->data;
    parent->token = child->token;

    child->data = temp_data;
    child->token = temp_token;
}


void tree_rotations(t_tree_node *node)
{
    if (!node)
		return;

	tree_rotations(node->left);	
	tree_rotations(node->right);
	if (node->token != PIPE && node->right &&
		(node->right->token == COMMAND || node->right->token == BUILT_IN))
	{
		swap_parent_and_child(node, node->right);
		tree_rotations(node);
		return;
	}			
}





// t_tree_node *insert(t_tree_node *node, char *data, e_tokens token, bool *flag_inserted_node)
// {
// 	if (node == NULL){
// 		return (create_tree_node(data, token, flag_inserted_node));}
	
// 	if (*flag_inserted_node == false
// 		&& check_pipe_precendence(token, node->right)
// 		&& check_builtin_cmd(token, node->right)
// 		&& check_right_word_branches(node, node->left))
// 	{
// 		node->right = insert(node->right, data, token, flag_inserted_node);
// 	}
// 	if (*flag_inserted_node == false
// 		&& check_pipe_precendence(token, node->left)
// 		&& check_builtin_cmd(token, node->left)
// 		&& check_right_word_branches(node, node->right))
// 	{
// 		node->left = insert(node->left, data, token, flag_inserted_node);
// 	}
// 		return (node);
// }

// t_tree	*stack_to_tree(t_stack *stack)
// {
// 	t_tree	*tree;
// 	bool	flag_inserted_node;

// 	tree = init_tree();
// 	flag_inserted_node = false;
// 	tree->root = create_tree_node(stack->stack[stack->top].data,
// 			stack->stack[stack->top].token, &flag_inserted_node);
// 	stack->top--;
// 	while (stack->top > -1)
// 	{
// 		flag_inserted_node = false;
// 		tree->root = insert(tree->root, stack->stack[stack->top].data,
// 				stack->stack[stack->top].token, &flag_inserted_node);
// 		stack->top--;
// 	}
// 	// tree_rotations(tree->root);
	
// 	return (tree);
// }




t_tree_node	*create_tree_node(t_stack *stack)
{
	t_tree_node	*new_node;

	new_node = (t_tree_node *)malloc(sizeof(t_tree_node));
	new_node->data = stack->stack[stack->top].data;
	new_node->token = stack->stack[stack->top].token;
	stack->top--;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}


t_tree_node *build_tree(t_stack *stack)
{
	t_tree_node *new_node;

	new_node = create_tree_node(stack);
	if ((new_node->token == COMMAND || new_node->token == BUILT_IN) && stack->stack[stack->top].token != PIPE)
		new_node->right = build_tree(stack);
	if (new_node->token == WORD && stack->stack[stack->top].token > 6)
		new_node->right = build_tree(stack);
	if (new_node->token == PIPE)
	{
		new_node->right = build_tree(stack);
		new_node->left = build_tree(stack);
	}
	return (new_node);
}

t_tree	*stack_to_tree(t_stack *stack)
{
	t_tree	*tree;

	tree = init_tree();
	tree->root = build_tree(stack);	
	return (tree);
}