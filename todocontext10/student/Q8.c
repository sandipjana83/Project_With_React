#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to left shift linked list by k nodes
struct Node* leftShift(struct Node* head, int k, int n) {
    if (head == NULL || k == 0 || k == n) return head;

    struct Node* temp = head;
    int count = 1;

    // Traverse to kth node
    while (count < k && temp != NULL) {
        temp = temp->next;
        count++;
    }

    // kth node
    struct Node* kthNode = temp;

    // Traverse to last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Connect last node to head
    temp->next = head;

    // New head is (k+1)th node
    head = kthNode->next;

    // kth node becomes last
    kthNode->next = NULL;

    return head;
}

// Driver code
int main() {
    int n = 5;
    struct Node* head = newNode(22);
    head->next = newNode(44);
    head->next->next = newNode(77);
    head->next->next->next = newNode(88);
    head->next->next->next->next = newNode(99);

    int k = 3;
    printf("Original list: ");
    printList(head);

    head = leftShift(head, k, n);

    printf("Shifted list: ");
    printList(head);

    return 0;
}
