/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:42:06 by lkhoury           #+#    #+#             */
/*   Updated: 2025/01/14 09:42:55 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*command_line_input()
{
	char	*input;
	
	input = readline("Minishell$ ");
	return (input);
}


void one_element_input_to_list(char *input, t_list *list, int *start, int *i)
{
	insert_at_end_list(list, ft_substr(input, *start, *i - *start));
	insert_at_end_list(list, ft_substr(input, *start, 1));
	*start = *i + 1;
}
void two_element_input_to_list(char *input, t_list *list, int *start, int *i)
{
	insert_at_end_list(list, ft_substr(input, *start, *i - *start));
	insert_at_end_list(list, ft_substr(input, *start, 2));
	*start = ++*i + 1;
}

int split_redirections(char *input, t_list *list, int start, int *i)
{
	if ((input[*i] == '<' && input[*i + 1] == '<') ||(input[*i] == '>' && input[*i + 1] == '>'))
			two_element_input_to_list(input, list, &start, i);
	else if (input[*i] == '<' || input[*i] == '>')
		one_element_input_to_list(input, list, &start, i);	
	return (start);
}

int split_symbols(char *input, t_list *list, int start, int *i)
{

	if (input[*i] == '|')
	{
		insert_at_end_list(list, ft_substr(input, start, *i - start));
		insert_at_end_list(list, ft_substr(input, start, 1));
		start = *i + 1;
	}
	else if (input[*i] == ' ') 
	{
		insert_at_end_list(list, ft_substr(input, start, *i - start));
		while (input[*i] == ' ')
			(*i)++;
		start = *i;
		// insert_at_end_list(list, ft_substr(input, start, *i - start));
	}
	return (start);
}

void quotes_to_node(char *input, t_list *list, int start, int *i)
{
	while(input[*i] != 22 && input[*i] != 27)
		i++;
	insert_at_end_list(list, ft_substr(input, start, *i - start));
	start = *i + 1;
}

t_list	*input_to_list(char *input)
{
	t_list	*list;
	int i;
	int start;
	
	i = 0;
	list = init_list();
	start = i;
	while (input[i])
	{
		if (input[i] == 22 || input[i] == 27)
			quotes_to_node(input, list, start, &i);
		start = split_symbols(input, list, start, &i);
		start = split_redirections(input, list, start, &i);
		i++;
		if (!input[i])
			insert_at_end_list(list, ft_substr(input, start, i - start));
	}
	return (list);
}


int main()
{
    t_list  *list;
    // printf("%s", readline("Minishell$ "));
    list = input_to_list(command_line_input());
    
    print_list(list);
    return (0);
}