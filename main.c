/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 09:48:08 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/22 20:52:05 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int fd;
	int fd1;
	int n ;
	int i = 5;
	char *str;
	fd = open("get_next_line.h",O_RDONLY);
	fd1 = open("get_next_line.c",O_RDONLY);

	while(i > 0)
	{
		n = get_next_line(fd,&str);
		printf("|%s| |%d|\n",str,n);
		//free(str);
		i--;
	}
	i = 5;
	return 0;
}
