#include <iostream>
using namespace std;


// Definition of a Node in a singly linked list
struct Node {
  
    // Data part of the node
    int data;

    // Pointer to the next node in the list
    Node* next;

    // Constructor to initialize the node with data
    Node (int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};


// C++ function to insert a new node at the beginning of the linked list
Node* insertAtBeginning(Node* head, int value)
{
    // Create a new node with the given value
    Node* newNode = new Node(value);

    // Set the next pointer of the new node to the current
    // head
    newNode->next = head;

    // Move the head to point to the new node
    head = newNode;

    // Return the new head of the linked list
    return head;
}


// C++ Function to traverse and print the elements of the linked list
void traverseLinkedList(Node* head)
{
    // Start from the head of the linked list
    Node* current = head;

    // Traverse the linked list until reaching the end (nullptr)
    while (current != nullptr) {
      
        // Print the data of the current node
        cout << current->data << " ";

        // Move to the next node
        current = current->next;
    }
}


int main()
{
    Node* head = NULL;

    int n, i, x;
    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> x;
        head = insertAtBeginning(head, x);
        traverseLinkedList(head);
        cout << "\n";
    }

    return 0;
}
