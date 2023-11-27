/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chopping_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:32:03 by subpark           #+#    #+#             */
/*   Updated: 2023/11/27 15:05:57 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_line(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '|')
			count ++;
		else if (str[i] == ' ' && count > 0)
			find_spaces(str, &i, &count);
		else if (str[i] == '<' || str[i] == '>')
			find_rellocator(str, &i, &count);
		else if(str[i] == '\'')
			count ++;
		else if (str[i] == '"')
			count ++;
		i ++;
	}
	if (count == 0 && i > 0)
		count ++;
	return (count);
}

char	*line_by_line(char *str, int *i)
{
	char	*line;

	while (str[*i])
	{
		if (str[*i] == ' ')
			*i ++;
		else if (str[*i] == '\'')
			return (ft_strdup("'"));//curious if it is possible just send strdup directly as return value
		else if (str[*i] == '"')
			return (ft_strdup("\""));
		else if (str[*i] == '|')
			return (ft_strdup("|"));
		else if (str[*i] == '<' || str[*i] == '>')
		{
			line = strdup_rellocator(str, i);
			return (line);
		}
		else
		{
			line = strdup_word(str, i);
			return (line);
		}
	}
}

char	**chopping_str(char *str)
{
	char	**chopped;
	int		i;
	int		index;

	chopped = (char **)malloc(sizeof(char *) * count_line(str) + 1);
	i = 0;
	index = 0;
	while (str[i])
	{
		chopped[index] = line_by_line(str, &i);
		i ++;
	}
}