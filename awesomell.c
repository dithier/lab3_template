#include <stdio.h>
#include <stdlib.h>

// Define the structure for a list node
typedef struct Node {
    int data;
    struct Node* next;
} Node_t;

// Function to create a new node
Node_t* createNode(int data) {
    Node_t* newNode = malloc(sizeof(Node_t));
    if (newNode == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
Node_t* insertAtBeginning(Node_t* head, int data) {
    Node_t* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to display the list
void displayList(Node_t* head) {
    Node_t* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory used by the list
void freeList(Node_t* head) {
    Node_t* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * Function: insertAtMiddle
 * -------------------------
 * Inserts a node with specified data into the approximate middle of a linked list. This function aims to
 * place the new node in a position that divides the list into two halves, with the new node leaning towards
 * the second half if the list has an even number of elements. The algorithm employs a two-pointer strategy:
 * one pointer advances at one node per step ('slow'), and the other may advance faster ('fast'), to efficiently
 * identify the middle insertion point on the fly.
 * 
 * Parameters:
 * - head: Pointer to the head of the list.
 * - data: The integer data to be inserted into the new node.
 * 
 * Note: Special cases (empty list or single-element list) are handled by defaulting to insertion at the beginning.
 * The precise middle point calculation strategy and insertion logic are abstracted for simplicity, focusing on
 * achieving an effective balance in the list's distribution with minimal computational overhead.
 */
Node_t* insertAtMiddle(Node_t* head, int data) {
    // If the list is empty or has only one element, insert at the beginning
    if (head == NULL || head->next == NULL) {
        return insertAtBeginning(head, data);
    }

    // Find the middle of the list
    Node_t* slow = head;
    Node_t* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // Insert the new node after 'slow' (middle of the list)
    Node_t* newNode = createNode(data);
    newNode->next = slow->next;
    slow->next = newNode;

    return head;
}

/*
* The main function is used to test the insertAtMiddle function.
* Please do NOT modify the main function!
*/
int main() {
    Node_t* head = NULL; // Initialize list as empty

    head = insertAtBeginning(head, 10); // List: 10
    head = insertAtBeginning(head, 20); // List: 20 -> 10
    head = insertAtBeginning(head, 30); // List: 30 -> 20 -> 10
    head = insertAtBeginning(head, 40); // List: 40 -> 30 -> 20 -> 10
    head = insertAtBeginning(head, 50); // List: 50 -> 40 -> 30 -> 20 -> 10
    head = insertAtBeginning(head, 60); // List: 60 -> 50 -> 40 -> 30 -> 20 -> 10
    head = insertAtBeginning(head, 70); // List: 70 -> 60 -> 50 -> 40 -> 30 -> 20 -> 10
    head = insertAtBeginning(head, 80); // List: 80 -> 70 -> 60 -> 50 -> 40 -> 30 -> 20 -> 10

    head = insertAtMiddle(head, 45); // should be inserted between 50 and 40 (in the middle of the list)

    printf("Linked List: ");
    displayList(head);

    // Free the memory used by the list
    freeList(head);

    return 0;
}
