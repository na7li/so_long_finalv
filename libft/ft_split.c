/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnahli <mnahli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:46:59 by mnahli            #+#    #+#             */
/*   Updated: 2024/11/18 12:17:35 by mnahli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_count(char const *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	n;

	i = 0;
	n = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			n++;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (n);
}

static char	*ft_get_word(char const *s, char c, size_t *index)
{
	size_t	start;
	size_t	len;
	char	*word;
	size_t	i;

	while (s[*index] == c && s[*index])
		(*index)++;
	start = *index;
	len = 0;
	while (s[*index] != c && s[*index])
	{
		(*index)++;
		len++;
	}
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[start + i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	ft_free_split(char **arr)
{
	size_t	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	size_t	index;

	if (!s)
		return (NULL);
	result = (char **)malloc((ft_word_count(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	i = 0;
	while (i < ft_word_count(s, c))
	{
		result[i] = ft_get_word(s, c, &index);
		if (!result[i])
		{
			ft_free_split(result);
			return (NULL);
		}
		i++;
	}
	result[ft_word_count(s, c)] = NULL;
	return (result);
}
