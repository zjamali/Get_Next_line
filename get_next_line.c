/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:26:31 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/26 18:58:04 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void delete_node(t_list **head, int fd) 
{
	t_list  *temp;
	t_list *prev;

	temp = *head;
	if (temp != NULL && temp->fd == fd) 
	{ 
		*head = temp->next;
		free(temp);
		temp = NULL;
		return;
	} 
	while (temp != NULL && temp->fd != fd) 
	{ 
		prev = temp;
		temp = temp->next; 
	} 
	if (temp == NULL) 
		return;  
	prev->next = temp->next; 
	free(temp); 
	temp = NULL;
}

t_list *lstnew(int fd)
{
	t_list *lst;
	if(!(lst = (t_list*)malloc(sizeof(t_list))))
		return NULL;
	lst->fd = fd;
	lst->next = NULL;
	lst->str = NULL;
	return lst;
}

t_list *check(t_list **lst,int fd)
{
	t_list  *ptr;

	if(*lst == NULL)
	{
		(*lst) = lstnew(fd);
		return (*lst);
	}
	ptr = *lst;
	if ((ptr)->fd == fd)
	{
		return (ptr);
	}
	while(((ptr)->next) != NULL)
	{
		if(((ptr)->next)->fd == fd)
		{
			return ((ptr)->next);
		}
		ptr = (ptr)->next;
	}
	ptr->next = lstnew(fd);
	return ((ptr)->next);
}
int gnl_continue(char **str,char **line,int *tab,t_list **head)
{
	char *temp;
	int i;

	 if(tab[0] < 0)
		          return(-1);
	  if(!(*str) && !(tab[0]))
		           return 0;
	temp = *str;
	i = 0;
	while((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr((*str),0,i);
	if ((*str)[i] == '\n' && (*str)[i + 1])
		*str = ft_strdup(*str + i + 1);
	else
	{
		*str = NULL;
		delete_node(head,tab[1]);
	}
	free(temp);
	return (1);
}
int		get_next_line(int fd, char **line)
{
	int tab[3];
	char *buff;
	static t_list *head;
	t_list *lst;
	char *temp;

	lst = check(&head,fd);
	if(lst->str != NULL)
	{
		if(ft_strchr(lst->str,'\n'))
			return (gnl_continue(&(lst->str),line,tab,&head));
	}
	if(fd < 0 || fd > 4682 || (buff = (char*)malloc(BUFFER_SIZE + 1)) == NULL \
			|| read(fd,buff,0) || line == NULL )
		return(-1);
	while((tab[0] = read(fd,buff,BUFFER_SIZE)) > 0)
	{
		temp = lst->str;
		buff[tab[0]] = '\0';
		if(lst->str == NULL)
			lst->str = ft_strdup(buff);
		else
			lst->str = ft_strjoin(lst->str,buff);
		free(temp);
		if(ft_strchr(lst->str,'\n'))
			break;
	}
	free(buff);
	tab[1] = fd;
	return (gnl_continue(&(lst->str),line,tab,&head));
}
