/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:16:11 by mspinnet          #+#    #+#             */
/*   Updated: 2020/11/03 16:55:31 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*str;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
		return ;
	while (*lst)
	{
		str = *lst;
		*lst = (*lst)->next;
		del(str->content);
		free(str);
	}
	*lst = NULL;
}
