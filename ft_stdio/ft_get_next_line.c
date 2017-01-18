/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervac <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 09:13:34 by pcervac           #+#    #+#             */
/*   Updated: 2016/12/23 18:12:51 by pcervac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_stdio.h"

static int		rbf(const int fd, char **bf)
{
	ft_strdel(bf);
	if (NULL != (*bf = ft_strnew(BUFF_SIZE)))
	{
		if (ER == read(fd, *bf, BUFF_SIZE))
			ft_strdel(bf);
		else
			return (ft_strlen(*bf));
	}
	return (ER);
}

static int		write_line(char **line, char **bf)
{
	char	*tln;
	char	*tbf;
	char	*eln;

	tln = *line;
	tbf = *bf;
	eln = ft_strchr(*bf, '\n');
	if (eln != NULL)
	{
		*eln = '\0';
		*bf = ft_strdup(eln + 1);
	}
	else
		*bf = NULL;
	*line = ft_strjoin(*line, tbf);
	ft_strdel(&tln);
	ft_strdel(&tbf);
	return (*bf != NULL);
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_buff	bf[MAX_FD];
	char			fendl;

	if (line == NULL || fd < 0 || fd >= MAX_FD)
		return (ER);
	*line = ft_strdup("");
	fendl = 0;
	while (1)
	{
		if (bf[fd].bf == NULL && ER == (bf[fd].rf = rbf(fd, &bf[fd].bf)))
		{
			ft_strdel(line);
			return (ER);
		}
		fendl = write_line(line, &bf[fd].bf);
		if (fendl || !bf[fd].rf || bf[fd].rf < BUFF_SIZE)
			break ;
	}
	return (**line != '\0' || bf[fd].bf != NULL);
}
