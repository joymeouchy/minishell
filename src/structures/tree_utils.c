/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhoury <lkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:42:48 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/03/18 11:36:49 by lkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"


t_tree *init_tree(void)
{
    t_tree *tree;
    
    tree = malloc(sizeof(t_tree));
    tree->root = NULL;
    return (tree);
}

void printInorder(t_tree_node *node) {
    if (node == NULL)
        return;

    // Traverse the left subtree
    printInorder(node->left);

    // Print the current node's data
    printf("Data: %s, Token: %d\n", node->data, node->token);

    // Traverse the right subtree
    printInorder(node->right);
}
t_tree_node *create_tree_node(char *data, e_tokens token)
{
    t_tree_node *new_node;

    new_node = (t_tree_node *)malloc(sizeof(t_tree_node));
    new_node->data = data;
    new_node->token = token;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}



// t_tree_node *insert(t_tree_node *node, char *data, e_tokens token)
// {
//     if (node == NULL)
//         return (create_tree_node(data, token));
//     if (node->right == NULL || (node->right->token != 7 && node->right->token != 8))
//         node->right = insert(node->right, data, token);
//     else
//         node->left = insert(node->left, data, token);
//     return (node);
// }

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

t_tree_node *insert(t_tree_node *node, char *data, e_tokens token) {
    if (node == NULL) {
        return create_tree_node(data, token);
    }

    // If the token is a WORD or TILDE, always insert it on the right
    if (token == WORD || token == TILDE) {
        if (node->right == NULL) {
            node->right = insert(node->right, data, token);
        } else {
            // If the right child is already occupied, insert on the left
            node->left = insert(node->left, data, token);
        }
    } else {
        // For operators, insert on the right if possible
        if (node->right == NULL) {
            node->right = insert(node->right, data, token);
        } else {
            // If the right child is already occupied, insert on the left
            node->left = insert(node->left, data, token);
        }
    }

    return node;
}

void stack_to_tree(t_stack *stack)
{
    t_tree *tree;

    tree = init_tree();
    tree->root = create_tree_node(stack->stack[stack->top].data, stack->stack[stack->top].token);
    stack->top--;
    while(stack->top > -1)
    {
       tree->root = insert(tree->root, stack->stack[stack->top].data, stack->stack[stack->top].token);
        stack->top--;
    }
    printf("tree:\n");
    printInorder(tree->root);
}


// void print_tree(t_tree_node *node)
// {
        
//     if (node->left != NULL)
//         return 
// }
