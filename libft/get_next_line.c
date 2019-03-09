/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikoloshy <ikoloshy@unit.student.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 19:29:53 by ikoloshy          #+#    #+#             */
/*   Updated: 2019/03/07 17:11:59 by ikoloshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_current_fd_data(const int fd)
{
	static t_list	*storage;
	t_list			*current;
	t_tail			tail;

	current = storage;
	while (current)
		if (((t_tail*)(current->content))->fd == fd)
			return (current);
		else
			current = current->next;
	tail.fd = fd;
	ft_bzero(tail.tail, BUFF_SIZE);
	current = ft_lstnew(&tail, sizeof(t_tail));
	ft_lstadd(&storage, current);
	return (current);
}

int				check_tail(char **line, t_list *list)
{
	char	*endl;

	if (!(endl = ft_strchr(((t_tail*)(list->content))->tail, (int)'\n')))
		return (0);
	*endl++ = '\0';
	*line = ft_strdup(((t_tail*)(list->content))->tail);
	ft_strcpy(((t_tail*)(list->content))->tail, endl);
	return (1);
}

int				make_line(t_list *list, char *buff, char **line)
{
	char	*endl;
	char	*temp;

	if (!(endl = ft_strchr(buff, (int)'\n')))
	{
		temp = ft_strjoin(*line, buff);
		free(*line);
		*line = temp;
		return (0);
	}
	*endl++ = '\0';
	temp = ft_strjoin(*line, buff);
	free(*line);
	*line = temp;
	ft_bzero(((t_tail*)(list->content))->tail, BUFF_SIZE);
	ft_strcpy(((t_tail*)(list->content))->tail, endl);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	t_list	*current;
	char	buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, 0, 0))
		return (-1);
	current = get_current_fd_data(fd);
	if (check_tail(line, current))
		return (1);
	ft_bzero(buff, (BUFF_SIZE + 1));
	*line = ft_strdup(((t_tail*)(current->content))->tail);
	ft_bzero(((t_tail*)(current->content))->tail, BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		if (make_line(current, buff, line))
			return (1);
		ft_bzero(buff, (BUFF_SIZE + 1));
	}
	if (*line[0] != '\0')
		return (1);
	return (0);
}
