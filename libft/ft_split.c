/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaffa- <astaffa-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:41:10 by astaffa-          #+#    #+#             */
/*   Updated: 2024/09/28 19:41:29 by astaffa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

static char	*allocate_word(const char *start, const char *end)
{
	char	*word;
	int		len;

	len = end - start;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static char	**free_all(char **result, int i)
{
	while (i > 0)
	{
		free(result[i - 1]);
		i--;
	}
	free(result);
	return (NULL);
}

static char	**fill_result(const char *s, char c, char **result)
{
	int			i;
	int			word_count;
	const char	*word_start;

	i = 0;
	word_count = count_words(s, c);
	while (*s)
	{
		if (*s != c)
		{
			word_start = s;
			while (*s && *s != c)
				s++;
			result[i] = allocate_word(word_start, s);
			if (!result[i])
				return (free_all(result, i));
			i++;
		}
		else
		{
			s++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result = fill_result(s, c, result);
	return (result);
}
