/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shunting_yard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:39:06 by lkhoury           #+#    #+#             */
/*   Updated: 2025/02/11 18:03:44 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// void shunting_yard(t_list *list)
// {
//     t_stack *stack;
    
//     t_list_node *temp = list->head;

//     stack = malloc(sizeof(t_stack));
//     init_stack(list, stack);
//     while(temp)
//     {
//         push(temp->data, stack);
//         temp = temp->next;
//     }    
//     print_stack(stack->stack);
    
// }

void push_stack_to_other(t_stack *src, t_stack *dst)
{
    while(src->top > -1)
    {
        push(src->stack[src->top], dst);
        pop(src);
    }
}

void shunting_yard(t_list *list)
{
    t_stack *stack;
    t_stack *cmd_stack;
    t_list_node *temp;

    temp = list->head;
    stack = malloc(sizeof(t_stack));
    cmd_stack = malloc(sizeof(t_stack));
    init_stack(list, stack);
    init_stack(list, cmd_stack);
    while (temp)
    {
        if (temp->token == 7 || temp->token == 8)
            push(temp->data, stack);
        else 
        {
            if (stack->stack[stack->top] == 0 && cmd_stack->top > 0)
                push_stack_to_other(stack, cmd_stack);
            push(temp->data, cmd_stack);    
        }
        temp = temp->next;
    }
    // while (cmd_stack->top > 0)
    //     push_stack_to_other(stack, cmd_stack);

    print_stack(stack);
    print_stack(cmd_stack);

    // free_stack(cmd_stack);
    // return (stack);
}
