/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:42:48 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/02/12 10:20:45 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"

void    init_stack(t_list *list, t_stack *stack)
{
    stack->top = -1;
    stack->stack = (char **)malloc(sizeof(char *) * list->list_size + 1);
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

void print_stack(t_stack *stack)
{
    int i;

    i = 0;
    while(stack->stack[i])
    {
        printf("stack element is:%s\n", stack->stack[i]);
        i++;
    }
}
