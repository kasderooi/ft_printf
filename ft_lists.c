/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lists.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: kde-rooi <kde-rooi@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/27 11:38:01 by kde-rooi      #+#    #+#                 */
/*   Updated: 2020/12/04 13:43:33 by kde-rooi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		lst_clear(t_list **lst)
{
	t_list	*buffer;

	while ((*lst)->next)
	{
		buffer = (*lst)->next;
		free((*lst)->content);
		free((*lst));
		*lst = buffer;
	}
}

static t_list	*lstlast(t_list *lst)
{
	while (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list			*ft_lstnew(int len, void *content)
{
	t_list	*element;

	element = malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->len = len;
	element->content = content;
	element->next = NULL;
	return (element);
}

int				lstadd_before_back(t_list **lst, t_list *new)
{
	t_list *buf_before;
	t_list *buf_after;

	buf_after = *lst;
	if (!new)
	{
		lst_clear(lst);
		return (-1);
	}
	if (!*lst)
		*lst = new;
	else
	{
		while (buf_after->next != NULL)
		{
			buf_before = buf_after;
			buf_after = buf_after->next;
		}
		buf_before->next = new;
		new->next = buf_after;
	}
	return (0);
}

int				lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
	{
		lst_clear(lst);
		return (-1);
	}
	if (!*lst)
		*lst = new;
	else
		lstlast(*lst)->next = new;
	return (0);
}
