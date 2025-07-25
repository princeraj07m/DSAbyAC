#include <iostream>
using namespace std;

class Node {
     public:
    int data;
    Node* next;
    Node* prev;
    
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
class DoublyLinkedList {
    Node* head;
    Node* tail;

    public:
        DoublyLinkedList() {
            head = tail = NULL;
        }

        // Insert at the front
        void push_front(int val) {
            Node* newNode = new Node(val);
            if (head == NULL) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        // Insert at the back
        void push_back(int val) {
            Node* newNode = new Node(val);
            if (tail == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void pop_front() {
            if (head == NULL) return; // List is empty
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL; // List is now empty
            }
            delete temp;
        }
        void pop_back() {
            if (tail == NULL) return; // List is empty
            Node* temp = tail;
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            } else {
                head = NULL; // List is now empty
            }
            delete temp;
        }

        // Display the list
        void printList() {
            Node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " <-> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main() {
    DoublyLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.push_front(0);
    dll.printList();

    return 0;
}