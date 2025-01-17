/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:42:06 by lkhoury           #+#    #+#             */
/*   Updated: 2025/01/17 11:07:59 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// char	*one_element_input_to_list(char *input, int *start, int *i)
// {
// 	char	*string;

// 	string = ft_substr(input, *i, 1);
// 	// *start = (*i) + 1;
// 	*i+=1;
// 	return (string);
// }

// char	*two_element_input_to_list(char *input, int *start, int *i)
// {
// 	char	*string;
	
// 	string = ft_substr(input, *i, 2);
// 	(*i)+=2;
// 	*start = *i;
// 	return (string);
// }

char	*split_redirections(char *input, int *start, int *i)
{
	if ((input[*i] == '<' && input[*i + 1] == '<')
		|| (input[*i] == '>' && input[*i + 1] == '>'))
		{
			(*i) +=2;
			*start = *i;
			return (ft_substr(input, *i - 2, 2));
		// return (two_element_input_to_list(input, start, i));
		}
	else if (input[*i] == '<' || input[*i] == '>')
	{
		(*i)+=1;
		*start = *i;
		return (ft_substr(input, *i - 1, 1));
		// return (one_element_input_to_list(input, start, i));
	}
	return (NULL);
}

char	*split_symbols(char *input, int *start, int *i)
{
	char	*string;

	string = NULL;
	if (input[*i] == ' ')
	{
		if (input[*start] != ' ')
			string = ft_substr(input, *start, *i - *start);
		while (input[*i] == ' ')
			(*i)++;
		*start = *i;
		if (!string)
			return (NULL);
		return (string);
	}
	if (input[*i] == '|')
	{
		string = ft_substr(input, *i, 1);
		*start = (*i) + 1;
		if(!string)
			return (NULL);
		return (string);
	}
	return (NULL);
}

// To be removed later ""//
char	*quotes_to_str(char *input, int *start, int *i, int quotes_in_ascii)
{
	int		flag_quotes_closed;
	char	*string;

	flag_quotes_closed = 1;
	while (flag_quotes_closed == 1 && input[*i] != '|' && input[*i] != '<'
		&& input[*i] != '>' && input[*i] != ' ' && input[*i] != '\0')
	{
		flag_quotes_closed = 0;
		*i += 1;
		while (input[*i] != quotes_in_ascii && input[*i] != '\0')
			(*i)++;
		if (input[*i] == quotes_in_ascii)
			flag_quotes_closed = 1;
		(*i)++;
	}
	string = ft_substr(input, *start, *i - *start);
	*start = *i;
	*(i) -= 1;
	return (string);
}

t_list  *input_to_list(char *input)
{
	t_list	*list;
	int		i;
	int		start;

	if (*input == '\0')
		return (NULL);
	i = 0;
	list = init_list();
	start = i;
	while (input[i])
	{
		printf("is is: %d, start is %d, input[i] is:%c\n", i, start, input[i]);
		if (i != start && (input[i] == '|' || input[i] == '<' || input[i] == '>'))
		{
			printf("im in the if statement\n");
			insert_at_end_list(list, ft_substr(input, start, i - start));
			start = i;
			printf("is is: %d, start is %d, input[i] is:%c\n", i, start, input[i]);
		}
		insert_at_end_list(list, split_symbols(input, &start, &i));
		printf("is is: %d, start is %d, input[i] is:%c\n", i, start, input[i]);

		insert_at_end_list(list, split_redirections(input, &start, &i));
				printf("is is: %d, start is %d, input[i] is:%c\n", i, start, input[i]);

		if (input[i] == 34)
		{
			insert_at_end_list(list, quotes_to_str(input, &start, &i, 34));
					printf("is is: %d, start is %d, input[i] is:%c\n", i, start, input[i]);
		}
		if (input[i] == 39)
		{
			insert_at_end_list(list, quotes_to_str(input, &start, &i, 39));
				printf("is is: %d, start is %d, input[i] is:%c\n", i, start, input[i]);
		}
		i++;
		if (!input[i] && start != i && input[i] != ' ')
			insert_at_end_list(list, ft_substr(input, start, i - start));
	}
	return (list);
}