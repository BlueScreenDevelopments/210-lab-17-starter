#include <iostream>
using namespace std;
//FORK'D

const int SIZE = 7;

struct Node {
    float value;
    Node* next;
};

// Function prototypes
void output(Node*);
Node* addNodeToFront(Node*, float);
Node* addNodeToTail(Node*, float);
Node* deleteNode(Node*, int);
Node* insertNode(Node*, int, float);
void deleteLinkedList(Node*);

int main() {
    Node* head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        head = addNodeToFront(head, tmp_val);
    }
    output(head);

    // deleting a node
    int entry;
    cout << "Which node to delete? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    head = deleteNode(head, entry);
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    Node* current = head;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;
    head = insertNode(head, entry, 10000);
    output(head);

    // deleting the linked list
    deleteLinkedList(head);
    output(head);

    return 0;
}

void output(Node* hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node* current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

Node* addNodeToFront(Node* head, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* addNodeToTail(Node* head, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    if (!head) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    return head;
}

Node* deleteNode(Node* head, int entry) {
    Node* current = head;
    Node* prev = head;
    for (int i = 0; i < (entry - 1); i++) {
        prev = prev->next;
        current = current->next;
    }
    prev->next = current->next;
    delete current;
    current = nullptr;
    return head;
}

Node* insertNode(Node* head, int entry, float value) {
    Node* newNode = new Node;
    newNode->value = value;
    Node* current = head;
    Node* prev = head;
    for (int i = 0; i < (entry - 1); i++) {
        prev = prev->next;
        current = current->next;
    }
    newNode->next = current;
    prev->next = newNode;
    return head;
}

void deleteLinkedList(Node* head) {
    Node* current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}