
**Implement a list library (singlylist.h) for a singly linked list with Append, Insert, Search and Delete
operations**

a) Write a menu driven program for the following operations.
i. Insert an element in a linked list in a particular position
ii. Search an element in a linked list.
iii. Delete a particular element from a linked list.


<Header File Signlylist_a.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define structure for linked list node
struct Node {
    int data;
    struct Node *next;
};

// Head pointer (global)
struct Node *head = NULL;

// Insert at specific position
void insertAtPosition(int data, int position) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Inserted %d at position %d\n", data, position);
        return;
    }

    struct Node *temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    printf("Inserted %d at position %d\n", data, position);
}

// Search for an element
void searchElement(int key) {
    struct Node *temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list.\n", key);
}

// Delete an element
void deleteElement(int key) {
    struct Node *temp = head, *prev = NULL;

    // If head needs to be deleted
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        printf("Element %d deleted from the list.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Element %d deleted from the list.\n", key);
}

// Display the linked list
void displayList() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}



<Main_a.c>
// Menu-driven function
#include "Singlylist_a.h"
int main() {
    int choice, data, position;
    while (1) {
        printf("\n1. Insert at Position\n");
        printf("2. Search Element\n");
        printf("3. Delete Element\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(data, position);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchElement(data);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteElement(data);
                break;
            case 4:
                displayList();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
return 0;
}
