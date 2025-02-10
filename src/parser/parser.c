/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:42:06 by lkhoury           #+#    #+#             */
/*   Updated: 2025/02/08 19:55:44 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	one_element_input_to_list(char *input, t_list *list, int *start, int *i)
{
	insert_at_end_list(list, ft_substr(input, *start, *i - *start));
	insert_at_end_list(list, ft_substr(input, *i, 1));
	*start = *i + 1;
}

void	two_element_input_to_list(char *input, t_list *list, int *start, int *i)
{
	insert_at_end_list(list, ft_substr(input, *start, *i - *start));
	insert_at_end_list(list, ft_substr(input, *i, 2));
	*start = ++*i + 1;
}

int	split_redirections(char *input, t_list *list, int start, int *i)
{
	if ((input[*i] == '<' && input[*i + 1] == '<')
		|| (input[*i] == '>' && input[*i + 1] == '>'))
		two_element_input_to_list(input, list, &start, i);
	else if (input[*i] == '<' || input[*i] == '>')
		one_element_input_to_list(input, list, &start, i);
	return (start);
}

int	split_symbols(char *input, t_list *list, int start, int *i)
{
	if (input[*i] == ' ')
	{
		if (*i != start)
			insert_at_end_list(list, ft_substr(input, start, *i - start));
		while (input[*i] == ' ')
			(*i)++;
		start = *i;
	}
	if (input[*i] == '|')
	{
		insert_at_end_list(list, ft_substr(input, start, *i - start));
		insert_at_end_list(list, ft_substr(input, *i, 1));
		start = *i + 1;
	}
	return (start);
}

int	double_quotes_to_node(char *input, t_list *list, int start, int *i)
{
	int	flag_quotes_closed;

	flag_quotes_closed = 1;
	while (flag_quotes_closed == 1 && input[*i] != '|' && input[*i] != '<'
		&& input[*i] != '>' && input[*i] != ' ' && input[*i] != '\0')
	{
		flag_quotes_closed = 0;
		*i += 1;
		while (input[*i] != '"' && flag_quotes_closed == 0 && input[*i] != '\0')
			(*i)++;
		if (input[*i] == '"')
			flag_quotes_closed = 1;
		(*i)++;
	}
	insert_at_end_list(list, ft_substr(input, start, *i - start));
	start = *i;
	*(i) -= 1;
	return (start);
}

int	single_quotes_to_node(char *input, t_list *list, int start, int *i)
{
	int	flag_quotes_closed;

	flag_quotes_closed = 1;
	while (flag_quotes_closed == 1 && input[*i] != '|' && input[*i] != '<'
		&& input[*i] != '>' && input[*i] != ' ' && input[*i] != '\0')
	{
		flag_quotes_closed = 0;
		*i += 1;
		while (input[*i] != 39 && input[*i] != '\0')
			(*i)++;
		if (input[*i] == 39)
			flag_quotes_closed = 1;
		(*i)++;
	}
	insert_at_end_list(list, ft_substr(input, start, *i - start));
	start = *i;
	*(i) -= 1;
	return (start);
}

t_list	*input_to_list(char *input)
{
	t_list	*list;
	int		i;
	int		start;

	if (*input == '\0' || input == NULL)
		return (free(input), NULL);
	i = 0;
	list = init_list();
	start = i;
	while (input[i])
	{
		start = split_symbols(input, list, start, &i);
		start = split_redirections(input, list, start, &i);
		if (input[i] == '"')
			start = double_quotes_to_node(input, list, start, &i);
		if (input[i] == 39)
			start = single_quotes_to_node(input, list, start, &i);
		if (input[i])
			i++;
		if (input[i] == '\0' && i != start)
			insert_at_end_list(list, ft_substr(input, start, i - start));
	}
	free(input);
	return (list);
}
