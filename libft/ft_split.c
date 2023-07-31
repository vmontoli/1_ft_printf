/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmontoli <vmontoli@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 08:44:44 by vmontoli          #+#    #+#             */
/*   Updated: 2023/05/20 19:36:39 by vmontoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_split_count_substrings(char const *s, char c)
{
	size_t	result;

	result = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			result++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (result);
}

static char	*ft_split_create_substring(char **current_ptr, char c)
{
	char	*s;
	char	*start_substring;
	char	*end_substring;
	size_t	n_chars_substring;

	s = *current_ptr;
	while (*s == c)
		s++;
	start_substring = s;
	while (*s != c && *s != '\0')
		s++;
	end_substring = s;
	*current_ptr = end_substring;
	n_chars_substring = end_substring - start_substring;
	return (ft_substr(start_substring, 0, n_chars_substring));
}

static char	**ft_split_recursive_free(char **to_delete)
{
	size_t	i;

	i = 0;
	while (to_delete[i] != NULL)
		free(to_delete[i++]);
	free(to_delete);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_substrings;
	char	**result;
	char	**current_ptr;
	size_t	i;

	n_substrings = ft_split_count_substrings(s, c);
	result = (char **) ft_calloc(n_substrings + 1, sizeof(char **));
	if (result == NULL)
		return (NULL);
	current_ptr = (char **) &s;
	i = 0;
	while (i < n_substrings)
	{
		result[i] = ft_split_create_substring(current_ptr, c);
		if (result[i] == NULL)
			return (ft_split_recursive_free(result));
		i++;
	}
	return (result);
}
