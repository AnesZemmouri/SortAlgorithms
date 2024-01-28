#include <iostream>
#include <iomanip>
using namespace std;

#include <iostream>
#include "sortarray.h"
using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};
void bubbleSortLinked(Node*& head) {
    if (!head || !head->next) {
        // Empty list or a list with only one element is already sorted
        return;
    }

    bool swapped;
    Node* current;
    Node* lastSorted = nullptr;

    do {
        swapped = false;
        current = head;

        while (current->next != lastSorted) {
            if (current->data > current->next->data) {
                // Swap data if the current node is greater than the next node
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }

            current = current->next;
        }

        lastSorted = current; // Mark the last sorted node
    } while (swapped);
}

void printList(const Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
/*
// Linked List Node
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the head of the linked list
void insertHead(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Function to free the memory allocated for the linked list
void freeList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Bubble sort for the linked list
void bubbleSortLinkedList(Node*& head) {
    if (!head || !head->next) {
        // Already sorted or empty list
        return;
    }

    bool swapped;
    Node* end = nullptr;
    do {
        swapped = false;
        Node* current = head;
        Node* previous = nullptr;

        while (current->next != end) {
            Node* nextNode = current->next;

            if (current->data > nextNode->data) {
                // Swap nodes
                if (previous) {
                    previous->next = nextNode;
                } else {
                    head = nextNode;
                }

                current->next = nextNode->next;
                nextNode->next = current;

                previous = nextNode;
                swapped = true;
            } else {
                previous = current;
                current = current->next;
            }
        }
        end = current;

    } while (swapped);
}

// Insertion sort for the linked list
void insertionSortLinkedList(Node*& head) {
    if (!head || !head->next) {
        // Already sorted or empty list
        return;
    }

    Node* sorted = nullptr;
    Node* current = head;

    while (current) {
        Node* nextNode = current->next;

        if (!sorted || sorted->data >= current->data) {
            // Insert at the beginning
            current->next = sorted;
            sorted = current;
        } else {
            // Search for the correct position
            Node* temp = sorted;
            while (temp->next && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }

        current = nextNode;
    }

    head = sorted;
}
void splitList(Node* source, Node*& front, Node*& back) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    front = source;
    back = slow->next;
    slow->next = nullptr;
}
// Selection sort for the linked list
void selectionSortLinkedList(Node*& head) {
    if (!head || !head->next) {
        // Already sorted or empty list
        return;
    }

    Node* current = head;

    while (current) {
        Node* minNode = current;
        Node* temp = current->next;

        while (temp) {
            if (temp->data < minNode->data) {
                minNode = temp;
            }
            temp = temp->next;
        }

        // Swap nodes
        int tempData = current->data;
        current->data = minNode->data;
        minNode->data = tempData;

        current = current->next;
    }
}

// Merge sort for the linked list
Node* mergeSortLinkedList(Node* currentHead) {
    if (!currentHead || !currentHead->next) {
        return currentHead;
    }

    Node* front;
    Node* back;

    splitList(currentHead, front, back);

    front = mergeSortLinkedList(front);
    back = mergeSortLinkedList(back);

    return merge(front, back);
}
// Split the linked list into two halves
void splitList(Node* source, Node*& front, Node*& back) {
    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    front = source;
    back = slow->next;
    slow->next = nullptr;
}

// Merge two sorted linked lists
Node* merge(Node* a, Node* b) {
    Node* result = nullptr;

    if (!a) {
        return b;
    } else if (!b) {
        return a;
    }

    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

// Quick sort for the linked list
void quickSortLinkedList(Node*& head) {
    if (!head || !head->next) {
        // Already sorted or empty list
        return;
    }

    Node* pivot = head;
    Node* less = nullptr;
    Node* equal = nullptr;
    Node* greater = nullptr;

    partitionLinkedList(head, pivot->data, less, equal, greater);

    quickSortLinkedList(less);
    quickSortLinkedList(greater);

    head = concatenateLinkedList(less, equal, greater);
}

// Partition the linked list into elements less, equal, and greater than the pivot
void partitionLinkedList(Node* source, int pivotData, Node*& less, Node*& equal, Node*& greater) {
    Node* current = source;

    while (current) {
        Node* nextNode = current->next;

        if (current->data < pivotData) {
            current->next = less;
            less = current;
        } else if (current->data == pivotData) {
            current->next = equal;
            equal = current;
        } else {
            current->next = greater;
            greater = current;
        }

        current = nextNode;
    }
}

// Concatenate three linked lists
Node* concatenateLinkedList(Node* less, Node* equal, Node* greater) {
    Node* result = nullptr;

    if (less) {
        result = less;
        while (less->next) {
            less = less->next;
        }
    }

    if (equal) {
        if (!result) {
            result = equal;
        } else {
            less->next = equal;
        }
        while (equal->next) {
            equal = equal->next;
        }
    }

    if (greater) {
        if (!result) {
            result = greater;
        } else {
            equal->next = greater;
        }
    }

    return result;
}
void menu1() {
    cout << "Choose an operation:\n";
    cout << "1. Insert at the head\n";
    cout << "2. Bubble Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Selection Sort\n";
    cout << "5. Merge Sort\n";
    cout << "6. Quick Sort\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Node* head = nullptr;

    int userChoice;
    while (userChoice != 0) {
        menu();
        cin >> userChoice;

        switch (userChoice) {
            case 1: {
                int data;
                cout << "Enter data to insert at the head: ";
                cin >> data;
                insertHead(head, data);
                cout << "Updated Linked List: ";
                printList(head);
                break;
            }
            case 2: {
                // Bubble sort the linked list
                bubbleSortLinkedList(head);
                cout << "Sorted Linked List (Bubble Sort): ";
                printList(head);
                break;
            }
            case 3: {
                // Insertion sort the linked list
                insertionSortLinkedList(head);
                cout << "Sorted Linked List (Insertion Sort): ";
                printList(head);
                break;
            }
            case 4: {
                // Selection sort the linked list
                selectionSortLinkedList(head);
                cout << "Sorted Linked List (Selection Sort): ";
                printList(head);
                break;
            }
            case 5: {
                // Merge sort the linked list
                mergeSortLinkedList(head);
                cout << "Sorted Linked List (Merge Sort): ";
                printList(head);
                break;
            }
            case 6: {
                // Quick sort the linked list
                quickSortLinkedList(head);
                cout << "Sorted Linked List (Quick Sort): ";
                printList(head);
                break;
            }
            // Add more linked list operations as needed
            case 0:
                cout << "Exiting...\n";
                freeList(head); // Free memory before exiting
                break;
            default:
                cout << "Invalid choice. Please choose a valid option.\n";
                break;
        }
    }

    return 0;
}*/

#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED



#endif // LINKEDLIST_H_INCLUDED
