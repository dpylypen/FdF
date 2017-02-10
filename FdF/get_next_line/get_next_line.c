/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:27:22 by dpylypen          #+#    #+#             */
/*   Updated: 2016/12/21 11:56:24 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew_fd(void const *content, size_t content_size, int fd)
{
	t_list	*list;
	void	*tmp;

	list = (t_list *)ft_memalloc(sizeof(t_list));
	if (list)
	{
		if ((tmp = ft_memalloc(content_size)) && content_size && content)
		{
			list->content = ft_memcpy(tmp, content, content_size);
			list->content_size = fd;
		}
		else
		{
			list->content = NULL;
			list->content_size = 0;
		}
	}
	return (list);
}

char	*get_next_part(int fd)
{
	char	*tmp;
	int		res;

	tmp = ft_memalloc(BUFF_SIZE + 1);
	res = read(fd, tmp, BUFF_SIZE);
	if (res)
		return (tmp);
	return (0);
}

t_list	*check_lst(int fd, t_list **alist)
{
	t_list *cur_lst;

	cur_lst = *alist;
	while ((cur_lst->content_size) != (size_t)fd && (cur_lst->next) != 0)
		cur_lst = cur_lst->next;
	if (cur_lst->content_size == (size_t)fd && cur_lst->content != 0)
		return (cur_lst);
	ft_lstadd(alist, ft_lstnew_fd("\0", BUFF_SIZE, fd));
	return (check_lst(fd, alist));
}

char	*create_nl(t_list *cur_lst, int fd)
{
	char *nl;
	char *ptr;
	char *tmp;

	nl = cur_lst->content;
	if (*nl)
		nl = ft_strdup(cur_lst->content);
	else
		nl = get_next_part(fd);
	if (!nl)
		return (0);
	while (!(ft_strchr(nl, '\n')))
	{
		if (!(tmp = get_next_part(fd)))
			break ;
		ptr = nl;
		nl = ft_strjoin(nl, tmp);
		free(ptr);
		free(tmp);
	}
	return (nl);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*alist = 0;
	char			*to_cut;
	char			*tmp;
	char			*nl;
	t_list			*cur_lst;

	tmp = 0;
	if (read(fd, tmp, 0) == -1)
		return (-1);
	if (!alist)
		alist = ft_lstnew_fd("\0", BUFF_SIZE, fd);
	cur_lst = check_lst(fd, &alist);
	if (!(nl = create_nl(cur_lst, fd)))
		return (0);
	if (!(to_cut = ft_strchr(nl, '\n')))
	{
		to_cut = ft_strchr(nl, '\0');
		tmp = to_cut;
	}
	else
		tmp = to_cut + 1;
	*to_cut = '\0';
	*line = nl;
	ft_strcpy(cur_lst->content, tmp);
	return (1);
}
