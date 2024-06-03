#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtBeginning(struct Node **head, int data);
void insertAtEnd(struct Node **head, int data);
void insertAfter(struct Node *prevNode, int data);
void deleteNode(struct Node **head, int data);
void display(struct Node *head);

int main() {
    struct Node *head = NULL;

    // Insert some nodes
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtBeginning(&head, 4);
    insertAfter(head->next, 5);

    // Display the list
    printf("Linked List: ");
    display(head);

    // Delete a node
    deleteNode(&head, 3);

    // Display the updated list
    printf("Linked List after deletion: ");
    display(head);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node *prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL!\n");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Function to delete a node with a given value
void deleteNode(struct Node **head, int data) {
    struct Node *temp = *head, *prev;

    // If the node to be deleted is the head node
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for the node to be deleted
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If the node with the given value is not present
    if (temp == NULL) {
        printf("Node with value %d not found!\n", data);
        return;
    }

    // Unlink the node from the linked list
    prev->next = temp->next;
    free(temp);
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

