#include <iostream>
#include "sortarray.h"
#include "tree.h"
#include "linkedlist.h" // Assuming this is the header for linked list functions

using namespace std;

int main() {
    int userChoice1 = -1; // Initialize userChoice1 to a default value
    while (userChoice1 != 0) {
        menu1();
        cin >> userChoice1;

        switch (userChoice1) {
            case 1: {
                int a[5];
                scanArray(a, 5);
                printArray(a, 5);

                bool solvedArray = false;
                int userChoice = -1; // Initialize userChoice to a default value
                while (userChoice != 0 || !solvedArray) {
                    menu();
                    cin >> userChoice;

                    switch (userChoice) {
                        case 1:
                            bubbleSort(a, 5);
                            solvedArray = true;
                            break;
                        case 2:
                            insertionSort(a, 5);
                            solvedArray = true;
                            break;
                        case 3:
                            selectionSort(a, 5);
                            solvedArray = true;
                            break;
                        case 4:
                            quickSort(a, 0, 4);
                            cout << "The sorted array using quickSort is :\n";
                            printArray(a, 5);
                            solvedArray = true;
                            break;
                        case 5:
                            mergeSort(a, 0, 4);
                            cout << "The sorted array using mergeSort is :\n";
                            printArray(a, 5);
                            solvedArray = true;
                            break;
                        case 0:
                            cout << "Exiting...\n";
                            break;
                        default:
                            cout << "Invalid choice. Please choose a valid option.\n";
                            break;
                    }
                }
                break;
            }
            case 2: {
                node *root = nullptr;
                insertt(root, 13);
                insertt(root, 5);
                insertt(root, 17);
                insertt(root, 19);
                insertt(root, 10);
                insertt(root, 20);
                insertt(root, 7);
                insertt(root, 18);
                insertt(root, 4);

                cout << "\npreorder :";
                preorder(root);
                cout << endl;
                cout << "\ninorder :";
                inorder(root);
                cout << endl;
                cout << "\npostorder :";
                postorder(root);
                cout << endl;
                cout << "\n";
                break;
            }
            case 3: {
                Node* head = new Node(5);
                head->next = new Node(3);
                head->next->next = new Node(8);
                head->next->next->next = new Node(1);

                cout << "\nOriginal list: ";
                printList(head);

                bubbleSortLinked(head);

                cout << "\nSorted list Using BubbleSort: ";
                printList(head);
                 cout << "\n";

                // Clean up allocated memory
                Node* current = head;
                while (current) {
                    Node* next = current->next;
                    delete current;
                    current = next;
                }
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please choose a valid option.\n";
                break;
        }
    }

    return 0;
}
