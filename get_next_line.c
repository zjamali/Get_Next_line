/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:26:31 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/24 02:07:15 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int leak(char **buff)
  {
  if(buff != NULL || *buff != NULL)
  {
  free(*buff);
  buff = NULL;
  }
  return (-1);
  }*/
void lst_print(t_list **head)
{
	t_list *temp = *head;
	//printf("#%p#",*head);
	if(temp ==NULL)
	{
		printf("VIDE");
	}
	while(temp)
	{
		printf("[%d]",temp->fd);
		temp = temp->next;
	}
}
void delete_node(t_list **head, int fd) 
{
      	t_list  *temp;
	t_list *prev;
	temp = *head;
	
    if (temp != NULL && temp->fd == fd) 
    { 
	//printf("%p",*head);
        *head = temp->next;
	//printf("%p",*head);
    	printf("@%p@",temp);
        free(temp);
	temp = NULL;
    	printf("@%p@",temp);
        return;
    } 
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->fd != fd) 
    { 
        prev = temp;
        temp = temp->next; 
    } 
    // If key was not present in linked list 
    if (temp == NULL) 
	    return;  
    // Unlink the node from linked list 
    prev->next = temp->next; 
    printf("#%p#",temp);
    free(temp);  // Free memory
    temp = NULL;
    printf("#%p#",temp);
}

t_list *lstnew(int fd)
{
	t_list *lst;
	if(!(lst = (t_list*)malloc(sizeof(t_list))))
		return NULL;
	lst->fd = fd;
	lst->next = NULL;
	lst->str = NULL;

    	printf("{%p}\n",lst);
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

/*int gnl_continue(char **str,char **line,int n,t_list **head,int fd)
{
	//char *temp;
	int i;

	i = 0;
	//temp = *str;
	if(n < 0)
		return(-1);
	if(!(*str) && !n)
		return 0;
	i = 0;
	while((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr((*str),0,i);
	if ((*str)[i] == '\n' && (*str)[i + 1])
	{
		*str = ft_strdup(*str + i + 1);
	}
	else
	{
		freenode(head,fd);
		*str = NULL;
	}
	return (1);
}
*/
int		get_next_line(int fd, char **line)
{
	int n;
	int i;

	char *buff;
	static t_list *head;
	//printf("$%p$",head);
	t_list *lst;
	lst = check(&head,fd);
	printf("[%p]",head);
	printf("%p",head->next);
	lst_print(&head);
	buff = (char*)malloc((BUFFER_SIZE + 1));
	if(buff == NULL || fd < 0 || fd > 4682 || read(fd,buff,0) ||
		       	line == NULL)
		return(-1);
	while((n = read(fd,buff,BUFFER_SIZE)) > 0)
	{
		buff[n] = '\0';
		if(lst->str == NULL)
		{
			lst->str = ft_strdup(buff);
		}
		else
		{
			lst->str = ft_strjoin(lst->str,buff);
		}
		if(ft_strchr(lst->str,'\n'))
			break;
	}
	if(n < 0)
		return(-1);
	if(!(lst->str) && !n)
		return 0;
	i = 0;
	while((lst->str)[i] != '\n' && (lst->str)[i] != '\0')
		i++;
	*line = ft_substr((lst->str),0,i);
	if ((lst->str)[i] == '\n' && (lst->str)[i + 1])
	{
		lst->str = ft_strdup(lst->str + i + 1);
	}
	else
	{
		lst->str = NULL;
		delete_node(&head,fd);
	}
	return (1);
}
