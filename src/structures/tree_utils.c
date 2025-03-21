/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:42:48 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/03/21 14:23:49 by jmeouchy         ###   ########.fr       */
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

t_tree_node *insert(t_tree_node *node, char *data, e_tokens token, bool *flag_inserted_node)
{
    if (node == NULL){
        return (create_tree_node(data, token, flag_inserted_node));}
    
	if (*flag_inserted_node == false && (node->right == NULL || (node->right->token != 7 && node->right->token != 8)))
	{
		node->right = insert(node->right, data, token, flag_inserted_node);
	}
	if (*flag_inserted_node == false && (node->left == NULL || (node->left->token != 7 && node->left->token != 8))){
		node->left = insert(node->left, data, token, flag_inserted_node);}
	if (node->token == 8 || node->token == 7){
		return (NULL);}
    return (node);
}

void	stack_to_tree(t_stack *stack)
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
	printf("tree:\n");
	print_inorder(tree->root);
}
