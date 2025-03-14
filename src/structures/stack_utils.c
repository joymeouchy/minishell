/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhoury <lkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 06:42:48 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/03/14 17:49:40 by lkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"

void    init_stack(t_list *list, t_stack *stack)
{
    stack->top = -1;
    stack->stack = (char *)malloc(sizeof(char *) * list->list_size + 1);
    stack->stack[list->list_size].data = '\0';
    stack->stack[list->list_size].token = -1;
    if (!stack->stack)
        return;
}

void push(char *data, e_tokens token, t_stack *stack)
{
    stack->top++;
    stack->stack[stack->top].data = data;
    stack->stack[stack->top].token = token;
}

void pop(t_stack *stack)
{
    if (stack->top == -1)
        printf("\nUnderflow!!\n");
    else
        stack->top = stack->top - 1;
}

void print_stack(t_stack *stack)
{
    int i;

    i = 0;
    printf("\nstack:\n");
    while(stack->stack[i].data )
    {
        printf("stack element is:%s\n", stack->stack[i].data);
        i++;
    }
}
