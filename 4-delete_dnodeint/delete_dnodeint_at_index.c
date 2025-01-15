#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (0 == index)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
		if ((*head)->prev) /** Check if the previous node exists */
			(*head)->prev->next = (*head)->next; /*Update the next pointer of the prev node*/
		if ((*head)->next) /*Check if the next node exists*/
			(*head)->next->prev = (*head)->prev; /*Update the prev pointer of the next node*/
		free(*head); /*free the head node*/
		*head = saved_head; /*reinitialise head to the saved head*/
	}
	/** else  // version that doesn't work
	* {
	* 	(*head)->prev->prev = (*head)->prev;
	* 	free(*head);
	* 	if ((*head)->next)
	* 		(*head)->next->prev = (*head)->next;
	* 	*head = saved_head;
	* }
	*/
	return (1);
}
