Implement a list library (doublylist.h) for a doubly linked list with Append, Insert, Search and Delete
operations.
  
a) Write a menu driven program for the following operations.
i. Insert an element in a linked list in a particular position
ii. Search an element in a linked list.
iii. Delete a particular element from a linked list.


<doublylist_a.h>
  
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void append(struct Node **head, int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(struct Node **head, int data, int pos) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (pos == 1) {
        newNode->next = *head;
        if (*head) (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    struct Node *temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (!temp) return;

    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
    

}

int search(struct Node *head, int key) {
    int pos = 1;
    while (head) {
        if (head->data == key)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

void deleteElement(struct Node **head, int key) {
    struct Node *temp = *head;
    while (temp && temp->data != key)
        temp = temp->next;

    if (!temp) return;

    if (temp->prev) temp->prev->next = temp->next;
    else *head = temp->next;

    if (temp->next) temp->next->prev = temp->prev;

    free(temp);
}

void display(struct Node *head) {
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}


<main_a>
#include "doublylist_a.h"

int main() {
    struct Node *head = NULL;
    int choice, data, pos;

    while (1) {
        printf("\n1. Insert at Position\n2. Search Element\n3. Delete Element\n4. Display List\n5. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &data);
                pos = search(head, data);
                if (pos != -1)
                    printf("Found at position %d\n", pos);
                else
                    printf("Element not found\n");
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteElement(&head, data);
                printf("Deleted if existed.\n");
                break;
            case 4:
                display(head);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
