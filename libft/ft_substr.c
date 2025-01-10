/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:19:09 by jmeouchy          #+#    #+#             */
/*   Updated: 2024/06/19 15:09:47 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		len = 0;
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (0);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}
