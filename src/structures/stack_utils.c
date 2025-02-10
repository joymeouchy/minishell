/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:42:48 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/02/10 12:28:46 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"


typedef struct s_stack
{
    int top;
    char    **stack;
} t_stack;

void    init_stack(t_list *list, t_stack *stack)
{
    stack->top = -1;
    stack->stack = (char **)malloc(sizeof(char *) * list->list_size);
    stack->stack[list->list_size] = '\0';
    if (!stack->stack)
        return;
}

void push(char *data, t_stack *stack)
{
    stack->top++;
    stack->stack[stack->top] = data;
}

void pop(t_stack *stack)
{
    if (stack->top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nPopped element: %s", stack->stack[stack->top]);
        stack->top = stack->top - 1;
    }
}

void shunting_yard(t_list *list)
{
    t_stack *stack;
    t_list_node *temp = list->head;

    stack = malloc(sizeof(t_stack));
    init_stack(list, stack);
    while(temp)
    {
        push(temp->data, stack);
        temp = temp->next;
    }    
    print_stack(stack->stack);
    
}
void print_stack(char **stack)
{
    int i;

    i = 0;
    while(stack[i])
    {
        printf("stack element is:%s\n", stack[i]);
        i++;
    }
}