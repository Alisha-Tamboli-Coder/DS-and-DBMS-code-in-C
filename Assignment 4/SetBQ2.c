b) Write a menu driven program for the following operations.
i. Reverse a linked list and display it.
ii. Accept an element from user and Concatenate it with a created link list.
iii. Merge two linked list and display it


#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Append node at end
void append(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
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

// Display forward
void display(struct Node *head) {
    while (head) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Reverse a doubly linked list
void reverse(struct Node **head) {
    struct Node *temp = NULL;
    struct Node *curr = *head;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Concatenate (append element to list)
void concatenate(struct Node **head, int data) {
    append(head, data);
}

// Merge two lists
struct Node* merge(struct Node *list1, struct Node *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    struct Node *temp = list1;
    while (temp->next)
        temp = temp->next;

    temp->next = list2;
    list2->prev = temp;
    return list1;
}


#include "doublylist.h"
int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int choice, val, n;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Reverse a linked list and display it\n");
        printf("2. Accept an element from user and Concatenate it with List1\n");
        printf("3. Merge two linked lists and display it\n");
        printf("4. Append to List1 (for testing)\n");
        printf("5. Display List1\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reverse(&list1);
                printf("List1 reversed:\n");
                display(list1);
                break;

            case 2:
                printf("Enter element to concatenate: ");
                scanf("%d", &val);
                concatenate(&list1, val);
                printf("Updated List1:\n");
                display(list1);
                break;

            case 3:
                printf("Enter number of elements for List2: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Element %d: ", i + 1);
                    scanf("%d", &val);
                    append(&list2, val);
                }
                list1 = merge(list1, list2);
                printf("Merged List:\n");
                display(list1);
                break;

            case 4:
                printf("Enter value to append to List1: ");
                scanf("%d", &val);
                append(&list1, val);
                break;

            case 5:
                printf("List1: ");
                display(list1);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
