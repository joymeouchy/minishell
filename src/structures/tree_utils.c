/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:42:48 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/03/20 23:04:14 by jmeouchy         ###   ########.fr       */
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

t_tree_node	*create_tree_node(char *data, e_tokens token)
{
	t_tree_node	*new_node;

	new_node = (t_tree_node *)malloc(sizeof(t_tree_node));
	new_node->data = data;
	new_node->token = token;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

t_tree_node *insert(t_tree_node *node, char *data, e_tokens token)
{
    if (node == NULL){
        return (create_tree_node(data, token));}
    
	if (node->right == NULL || (node->right->token != 7 && node->right->token != 8)){
		node->right = insert(node->right, data, token);}
	if (node->left == NULL || (node->left->token != 7 && node->left->token != 8)){
		node->left = insert(node->left, data, token);}
	if (node->token == 8 || node->token == 7){
		return (NULL);}
    return (node);
}

// t_tree_node *insert(t_tree_node *node, char *data, e_tokens token)
// {
//     if (node == NULL)
//         return create_tree_node(data, token);
//     if (token != 7 && token != 8)
//     {
//         if (node->right == NULL || (node->right->token != 7 &&  node->right->token != 8)) 
//             node->right = insert(node->right, data, token);
//         else if (node->left == NULL)
//             node->left = insert(node->right, data, token);
//     } 
//     else
//     {
//         if (node->right == NULL || (node->right->token != 7 &&  node->right->token != 8))
//             node->right = insert(node->right, data, token);
//         else if (node->left != NULL && )
//             node->left = insert(node->left, data, token);
//     }
//     return node;
// }

// t_tree_node	*insert(t_tree_node *node, char *data, e_tokens token)
// {
// 	if (node == NULL)
// 		return (create_tree_node(data, token));
// 	if (token == WORD || token == TILDE)
// 	{
// 		if (node->right == NULL)
// 			node->right = insert(node->right, data, token);
// 		else
// 			node->left = insert(node->left, data, token);
// 	}
// 	else
// 	{
// 		if (node->right == NULL)
// 			node->right = insert(node->right, data, token);
// 		else
// 			node->left = insert(node->left, data, token);
// 	}
// 	return (node);
// }

void	stack_to_tree(t_stack *stack)
{
	t_tree	*tree;

	tree = init_tree();
	tree->root = create_tree_node(stack->stack[stack->top].data,
			stack->stack[stack->top].token);
	stack->top--;
	while (stack->top > -1)
	{
		tree->root = insert(tree->root, stack->stack[stack->top].data,
				stack->stack[stack->top].token);
		stack->top--;
	}
	printf("tree:\n");
	print_inorder(tree->root);
}
