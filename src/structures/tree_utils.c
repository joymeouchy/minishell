/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhoury <lkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:42:48 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/03/14 12:55:18 by lkhoury          ###   ########.fr       */
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

t_tree_node *create_tree_node(int data)
{
    t_tree_node *new_node;

    new_node = (t_tree_node *)malloc(sizeof(t_tree_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

void insert(t_tree *tree, int data)
{
    t_tree_node *new_node;
    t_tree_node *temp;

    new_node = create_tree_node(data);
    if (tree->root == NULL)
    {
        tree->root = new_node;
        return;
    }

    // Level order traversal to find the appropriate place for insertion
    t_tree_node *queue[100];
    int front = -1, rear = -1;
    queue[++rear] = tree->root;

    while (front != rear)
    {
        temp = queue[++front];

        // Insert new node as the left child
        if (temp->left == NULL)
        {
            temp->left = new_node;
            return;
        }
        else
        {
            queue[++rear] = temp->left;
        }

        // Insert new node as the right child
        if (temp->right == NULL)
        {
            temp->right = new_node;
            return;
        }
        else
        {
            queue[++rear] = temp->right;
        }
    }
}
