
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <vector>
#include <iostream>
using namespace std;

struct Node
{
    int data_;
    Node* next = nullptr;
    Node* last = nullptr;

    Node(int data)
    {
        data_ = data;
    }
};

struct LinkedList
{
    Node* head = nullptr;
    Node* tail = nullptr;

    LinkedList()
    {
    }

    ~LinkedList()
    {
        Node* current = head;

        while (current != nullptr) {
            Node* temp = current->next;
            delete current;
            current = temp;
        }
    }

    void AddFirst(int data)
    {
        Node* newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;
            head = newNode;
            head->next = temp;
            temp->last = head;
        }
    }

    void AddLast(int data) {
        Node* current = head;
        while (current != nullptr) {
            if (current->next == nullptr) {
                current->next = new Node(data);
                current->next->last = current;
                break;
            }
            current = current->next;
        }
    }

    bool Contains(int value) {
        Node* current = head;

        while (current != nullptr) {
            if (current->data_ == value) {
                return true;
            }
            current = current->next;
        }
    }


    bool Remove(int value) {
        Node* current = head;
        bool found = false;

        while (current != nullptr && current->next != nullptr) {

            if (current == head) {
                if (value == current->data_) {
                    Node* temp = current;
                    found = true;
                    current = current->next;
                    head = current;
                    delete temp;
                }
                else if (value == current->next->data_) {
                    Node* temp = current->next;
                    found = true;
                    current->next = current->next->next;
                    delete temp;
                }
                else {
                    current = current->next;
                }
            }
            else if (value == current->next->data_) {
                Node* temp = current->next;
                found = true;
                current->next = current->next->next;
                delete temp;
            }
            else {
                current = current->next;
            }
        }
        return found;
    }

    int GetSize() {
        int i = 0;
        Node* current = head;

        while (current != nullptr) {
            i++;
            current = current->next;
        }
        return i;
    }

    int GetFirst() {
        return head->data_;
    }

    int GetLast() {
        Node* current = head;

        while (current != nullptr) {
            if (current->next == nullptr) {
                return current->data_;
            }
            current = current->next;
        }
    }

    void Add(int data, int index) {
        Node* newNode = new Node(data);
        Node* current = head;
        int i = 0;
        while (current != nullptr && index >= 0 && current->next != nullptr) {
            if (i == index - 1) {
                Node* temp;
                temp = current->next;
                current->next = newNode;
                newNode->next = temp;
                current->next->last = current;
                current->next->next->last = current->next;

            }
            current = current->next;
            i++;
        }
    }

    void Print() {
        Node* current = head;
        int i = 0;
        while (current != nullptr) {
            current = current->next;
            i++;
        }
    }
};

int main()
{
    LinkedList myLinkedList;

    myLinkedList.AddFirst(20);
    myLinkedList.AddFirst(20);
    myLinkedList.AddLast(5);
    myLinkedList.Add(2, 1);
    myLinkedList.Add(3, 1);
    myLinkedList.Remove(5);

    if (myLinkedList.Contains(20)) {
    }
    myLinkedList.Print();
}