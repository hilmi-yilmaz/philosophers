/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doubly_linked_list.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 12:10:12 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/11 13:21:31 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_dclist *create_dc_list(void *content)
{
	t_dclist	*dclist;

	dclist = ft_calloc(1, sizeof(*dclist));
	if (dclist == NULL)
		return (NULL);
	dclist->content = content;
	dclist->is_last = true;
	dclist->next = NULL;
	dclist->previous = NULL;
	return (dclist);
}

void	dc_list_add_back(t_dclist **dclist, t_dclist *new_element)
{
	t_dclist	*head;
	
	head = *dclist;
	if (dclist == NULL || new_element == NULL)
		return ;
	if (head == NULL)
	{
		head = new_element;
		head->is_last = true;
	}
	while (head->next)	
		head = head->next;
	head->is_last = false;
	head->next = new_element;
	head->next->is_last = true;
	new_element->previous = head;
}

void	delete_element(t_dclist *dclist, void (*del)(void *))
{
	if (dclist == NULL || del == NULL)
		return ;
	(*del)(dclist->content);
	free(dclist);
}

void	clear_entire_list(t_dclist **dclist, void (*del)(void *))
{
	t_dclist	*head;
	t_dclist	*temp;
	
	if (dclist == NULL || del == NULL)
		return ;
	head = *dclist;
	while (head)
	{
		temp = head->next;
		(*del)(head->content);
		if (head->is_last == true)
		{
			free(head);
			return ;
		}
		free(head);
		head = temp;
	}
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	t_dclist	*dclist;
// 	t_dclist	*new_dclist_element;
// 	t_dclist	*second_new_dclist_element;

// 	dclist = create_dc_list(strdup("hilmi"));
// 	printf("|%p|\n", dclist);
// 	printf("|%s|\n", (char *)(dclist->content));
// 	printf("|%p|\n", dclist->next);
// 	printf("|%p|\n", dclist->previous);
// 	printf("|%d|\n", dclist->is_last);
// 	printf("\n");

// 	new_dclist_element = create_dc_list(strdup("yilmaz"));
// 	printf("|%p|\n", new_dclist_element);
// 	printf("|%s|\n", (char *)(new_dclist_element->content));
// 	printf("|%p|\n", new_dclist_element->next);
// 	printf("|%p|\n", new_dclist_element->previous);
// 	printf("|%d|\n", new_dclist_element->is_last);
// 	printf("\n");

// 	dc_list_add_back(&dclist, new_dclist_element);
// 	printf("|%p|\n", dclist);
// 	printf("|%s|\n", (char *)(dclist->content));
// 	printf("|%p|\n", dclist->next);
// 	printf("|%p|\n", dclist->previous);
// 	printf("|%d|\n", dclist->is_last);
// 	printf("\n");

// 	printf("|%p|\n", new_dclist_element);
// 	printf("|%s|\n", (char *)(new_dclist_element->content));
// 	printf("|%p|\n", new_dclist_element->next);
// 	printf("|%p|\n", new_dclist_element->previous);
// 	printf("|%d|\n", new_dclist_element->is_last);
// 	printf("\n");

// 	second_new_dclist_element = create_dc_list(strdup("codam"));
// 	dc_list_add_back(&dclist, second_new_dclist_element);

// 	printf("|%p|\n", dclist);
// 	printf("|%s|\n", (char *)(dclist->content));
// 	printf("|%p|\n", dclist->next);
// 	printf("|%p|\n", dclist->previous);
// 	printf("|%d|\n", dclist->is_last);
// 	printf("\n");

// 	printf("|%p|\n", new_dclist_element);
// 	printf("|%s|\n", (char *)(new_dclist_element->content));
// 	printf("|%p|\n", new_dclist_element->next);
// 	printf("|%p|\n", new_dclist_element->previous);
// 	printf("|%d|\n", new_dclist_element->is_last);
// 	printf("\n");

// 	printf("|%p|\n", second_new_dclist_element);
// 	printf("|%s|\n", (char *)(second_new_dclist_element->content));
// 	printf("|%p|\n", second_new_dclist_element->next);
// 	printf("|%p|\n", second_new_dclist_element->previous);
// 	printf("|%d|\n", second_new_dclist_element->is_last);
// 	printf("\n");

// 	clear_entire_list(&dclist, free);

// 	return (0);
// }