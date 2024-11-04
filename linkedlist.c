#include "linkedlist.h"
Node *buy(int data)
{
    Node *a = (Node *)malloc(sizeof(Node));
    a->data = data;
    a->next = NULL;
    return a;
}
void showLinked_list(Node *head)
{
    Node *pcur = head;
    while (pcur != NULL)
    {
        printf("%d->", pcur->data);
        pcur = pcur->next;
    }
    printf("NULL");
}
void insertAtBeginning(struct Node **head, int data)
{
    Node *pcur = buy(data);
    pcur->next = (*head);
    (*head) = pcur;
}
void insertAtEnd(struct Node **head, int data)
{
    Node *prev = buy(data);
    Node *pcur = (*head);
    while (pcur->next != NULL)
    {
        pcur = pcur->next;
    }
    pcur->next = prev;
}
void insertAtPosition(struct Node **head, int data, int position)
{
    Node *prev = buy(data);
    Node *pcur = (*head);
    if (position == 1)
    {
        insertAtBeginning(head, data);
    }
    else
    {
        int n = position - 2;
        while (n--)
        {
            pcur = pcur->next;
        }
        Node *tmp = pcur->next;
        pcur->next = prev;
        prev->next = tmp;
    }
}
void deleteAtBeginning(struct Node **head)
{
    Node *pcur = (*head)->next;
    free((*head));
    (*head) = pcur;
}
void deleteAtEnd(struct Node **head)
{
    Node *pcur = (*head);
    if (pcur->next == NULL)
    {
        free(pcur);
        (*head) = NULL;
    }
    else
    {
        while (pcur->next->next != NULL)
        {
            pcur = pcur->next;
        }
        Node *prev = pcur->next;
        free(prev);
        pcur->next = NULL;
        prev = NULL;
    }
}
void deleteNode(struct Node **head, int key)
{
    Node *pcur = (*head);
    Node *prev = NULL;
    while (pcur->next != NULL)
    {
        if (pcur->data == key)
        {
            break;
        }
        prev = pcur;
        pcur = pcur->next;
    }
    if ((*head)->data == key)
    {
        deleteAtBeginning(head);
    }
    else
    {
        Node *plist = pcur->next;
        free(pcur);
        prev->next = plist;
        pcur = NULL;
    }
}
void deleteNodeAtPosition(struct Node **head, int position)
{
    Node *pcur = (*head);
    if (position == 1)
    {
        deleteAtBeginning(head);
    }
    else
    {
        int n = position - 2;
        while (pcur->next != NULL && n--)
        {
            pcur = pcur->next;
        }
        Node *prev = pcur->next;
        Node *plist = prev->next;
        free(prev);
        pcur->next = plist;
        prev = NULL;
    }
}
void reverseList(struct Node **head)
{
    Node *pcur = (*head);
    Node *prev = NULL;
    Node *plist = pcur->next;
    while (plist)
    {
        pcur->next = prev;
        prev = pcur;
        pcur = plist;
        plist = plist->next;
    }
    pcur->next = prev;
    (*head) = pcur;
}
void sortList(struct Node **headRef)
{
    struct Node *sorted = NULL;
    struct Node *current = *headRef;
    while (current != NULL)
    {
        struct Node *next = current->next;
        struct Node *pos = sorted;
        if (sorted == NULL || sorted->data >= current->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            while (pos->next != NULL && pos->next->data < current->data)
            {
                pos = pos->next;
            }
            current->next = pos->next;
            pos->next = current;
        }
        current = next;
    }
    *headRef = sorted;
}
void free_linked_list(struct Node *head)
{
    Node *pcur = head;
    while (pcur)
    {
        Node *prev = pcur->next;
        free(pcur);
        pcur = prev;
    }
}