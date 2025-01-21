/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:46:19 by lkhoury           #+#    #+#             */
/*   Updated: 2025/01/21 12:24:06 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*command_line_input(void)
{
	char	*input;

	input = readline("Minishell$ ");
	return (input);
}

int	main(void)
{
	t_list	*list;
	// printf("%s", readline("Minishell$ "));
	// while (1)
	// {
		list = input_to_list(command_line_input());
		print_list(list);
		free_list(list);
	// }
	return (0);
}
// int main()
// {
//     t_list  *list;
//     // printf("%s", readline("Minishell$ "));
//     list = input_to_list(command_line_input());
//     print_list(list);
//     return (0);
// }
