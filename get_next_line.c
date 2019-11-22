/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:26:31 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/22 20:52:10 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int leak(char **buff)
{
	if(buff != NULL || *buff != NULL)
	{
		free(*buff);
		buff = NULL;
	}
	return (-1);
}
<<<<<<< HEAD

t_list *check(t_list **lst,int fd)
{
	t_list  **ptr;
	if(*lst == NULL)
	{
		if(!((*lst) = (t_list*)malloc(sizeof(t_list))))
			return NULL;
		(*lst)->fd = fd;
		(*lst)->str = NULL;
		return (*lst);
	}
=======
int 	continuey(char **str,char **line,int n)
{
	char *tmp ;
	tmp= *str;

	int i = 0;
	if (n < 0)
		return (0);
	if(!*str && !n)
		return 0;
	while((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr((*str),0,i);
	if ((*str)[i] == '\n')
		(*str) = ft_strdup((*str) + i + 1);
	else
		(*str) = NULL;
	leak(&tmp);
	return (1);
}
int		get_next_line(int fd, char **line)
{
	int n;
	int i;
	char *buff;
	char	*tmp;
	static char *str;
>>>>>>> 6ed4b18601cc63ca935b4af2e0717d93aedd8ec0

	ptr = lst;
	if ((*ptr)->fd == fd)
		return (*ptr);
	while(((*ptr)->next) != NULL)
	{
		if(((*ptr)->next)->fd == fd)
			return ((*ptr)->next);
		*ptr = (*ptr)->next;
	}
<<<<<<< HEAD
	if(!(((*ptr)->next)= (t_list*)malloc(sizeof(t_list))))
		return NULL;
	((*ptr)->next)->fd = fd;
	(*ptr)->next->str = NULL;
	return ((*ptr)->next);
}

int gnl_continue(char **str,char **line,int n)
{
	char *temp;
	int i;

	i = 0;
	temp = *str;
	if(n < 0)
		return(-1);
	if(!(*str) && !n)
		return 0;
	i = 0;
	while((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr((*str),0,i);
	if ((*str)[i] == '\n' && (*str)[i + 1])
		*str = ft_strdup(*str + i + 1);
	else
		*str = NULL;
	return (1);
}

int		get_next_line(int fd, char **line)
=======
	leak(&buff);
	if (n < 0)
		return (0);
	return (continuey(&str,line,n));
}

int main()

>>>>>>> 6ed4b18601cc63ca935b4af2e0717d93aedd8ec0
{
	int n;
//	int i = 1;
	char *buff;
	static t_list *head;
	t_list *lst;
	lst = head;
	lst = check(&head,fd);
	buff = (char*)malloc((BUFFER_SIZE + 1));
	if(buff == NULL || fd < 0 || fd > 4682 || read(fd,buff,0) || line == NULL)
		return(leak(&buff));
	while((n = read(fd,buff,BUFFER_SIZE)) > 0)
	{
		buff[n] = '\0';
		if(!(lst->str))
		{
			lst->str = ft_strdup(buff);
		//	printf("{%s}\n", lst->str);
			free(buff);
		}
		else
		{
		//	printf("[%s]\n", lst->str);
			lst->str = ft_strjoin(lst->str,buff);
			free(buff);
		}
		if(ft_strchr(lst->str,'\n'))
			break;
	}
	return (gnl_continue(&lst->str,line,n));
}
