/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shunting_yard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:39:06 by lkhoury           #+#    #+#             */
/*   Updated: 2025/03/18 21:19:58 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

void	push_stack_to_other(t_stack *src, t_stack *dst)
{
	while (src->top > -1)
	{
		push(src->stack[src->top].data, src->stack[src->top].token, dst);
		pop(src);
	}
}

t_stack	*shunting_yard(t_list *list)
{
	t_stack		*stack;
	t_stack		*cmd_stack;
	t_list_node	*temp;

	temp = list->head;
	stack = malloc(sizeof(t_stack));
	cmd_stack = malloc(sizeof(t_stack));
	init_stack(list, stack);
	init_stack(list, cmd_stack);
	while (temp)
	{
		if (temp->token == 7 || temp->token == 8)
			push(temp->data, temp->token, stack);
		else
		{
			if (cmd_stack->stack[cmd_stack->top].token == 0)
				push_stack_to_other(cmd_stack, stack);
			push(temp->data, temp->token, cmd_stack);
		}
		temp = temp->next;
	}
	if (cmd_stack->top > -1)
		push_stack_to_other(cmd_stack, stack);
	free_stack(cmd_stack);
	return (stack);
}
