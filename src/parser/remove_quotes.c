/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:16:20 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/01/23 12:48:22 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	skip_quotes_in_string(int *count_quotes,
	char *string, int *i, int quotes_ascii)
{
	(*count_quotes)++;
	(*i)++;
	while (string[*i] && string[*i] != quotes_ascii)
		(*i)++;
	if (string[*i] == quotes_ascii)
	{
		(*count_quotes)++;
		(*i)++;
	}
}

int	check_if_quotes_balanced(char *string)
{
	int	i;
	int	count_double_quotes;
	int	count_single_quotes;

	i = 0;
	count_double_quotes = 0;
	count_single_quotes = 0;
	while (string[i])
	{
		if (string[i] == 34)
			skip_quotes_in_string(&count_double_quotes, string, &i, 34);
		else if (string[i] == 39)
			skip_quotes_in_string(&count_single_quotes, string, &i, 39);
		else
			i++;
	}
	if (count_double_quotes % 2 != 0 || count_single_quotes % 2 != 0)
		return (1);
	return (0);
}

int	check_if_contains_quotes(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == 34 || string[i] == 39)
			return (0);
		i++;
	}
	return (1);
}

char	*append_char_to_string(char *src, char c)
{
	int		len;
	int		i;
	char	*new_str;

	len = strlen(src) + 2;
	new_str = malloc(len * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = c;
	i++;
	new_str[i] = '\0';
	free(src);
	return (new_str);
}

void	remove_quotes_from_substring(char *string,
	char **copy_string, int *i, int quotes_ascii)
{
	(*i)++;
	while (string[*i] && string[*i] != quotes_ascii)
	{
		*copy_string = append_char_to_string(*copy_string, string[*i]);
		(*i)++;
	}
	(*i)++;
}

void	remove_quotes_from_string(char *string)
{
	int		i;
	char	*copy_string;

	i = 0;
	copy_string = malloc(1 * sizeof(char));
	if (copy_string == NULL)
		return ;
	copy_string[0] = '\0';
	while (string[i])
	{
		if (string[i] == 34)
			remove_quotes_from_substring(string, &copy_string, &i, 34);
		else if (string[i] == 39)
			remove_quotes_from_substring(string, &copy_string, &i, 39);
		else
		{
			copy_string = append_char_to_string(copy_string, string[i]);
			i++;
		}
	}
	ft_strlcpy(string, copy_string, ft_strlen(copy_string) + 1);
	free(copy_string);
}

int	check_and_remove_quotes(t_list *list)
{
	t_list_node	*temp;
	int			flag_balanced_quotes;

	temp = list->head;
	flag_balanced_quotes = 0;
	while (temp)
	{
		if (check_if_contains_quotes(temp->data) == 0)
			flag_balanced_quotes = check_if_quotes_balanced(temp->data);
		if (flag_balanced_quotes == 1)
		{
			printf("quotes unbalanced bro");
			return (1); // TO-DO ADD ERROR MESSAGE AND STOP PROCESS
		}
		remove_quotes_from_string(temp->data);
		temp = temp->next;
	}
	return (0);
}
