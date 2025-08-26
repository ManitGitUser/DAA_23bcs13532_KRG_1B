#include <iostream>
using namespace std;

class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;
    DoublyNode(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
    DoublyNode* head;
    DoublyNode* tail;

    public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    void insertAtBeginning(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int val) {
        DoublyNode* newNode = new DoublyNode(val);
        if (!tail) {
            head = tail = newNode;
        } 
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        DoublyNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr; 
        cout << "Deleted " << temp->data << " from beginning.\n";
        delete temp;
    }

    void deleteAtEnd() {
        if (!tail) {
            cout << "List is empty!\n";
            return;
        }
        DoublyNode* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr; 
        cout << "Deleted " << temp->data << " from end.\n";
        delete temp;
    }

    void display() {
        DoublyNode* curr = head;
        cout << "Doubly List: ";
        while (curr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

class CircularNode {
    public:
    int data;
    CircularNode* next;
    CircularNode(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
    CircularNode* tail; 
    public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void insertAtBeginning(int val) {
        CircularNode* newNode = new CircularNode(val);
        if (!tail) {
            tail = newNode;
            newNode->next = newNode;
        } 
        else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }

    void insertAtEnd(int val) {
        CircularNode* newNode = new CircularNode(val);
        if (!tail) {
            tail = newNode;
            newNode->next = newNode;
        } 
        else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteAtBeginning() {
        if (!tail) {
            cout << "List is empty!\n";
            return;
        }
        CircularNode* head = tail->next;
        if (head == tail) {
            cout << "Deleted " << head->data << " from beginning.\n";
            delete head;
            tail = nullptr;
        } 
        else {
            tail->next = head->next;
            cout << "Deleted " << head->data << " from beginning.\n";
            delete head;
        }
    }

    void deleteAtEnd() {
        if (!tail) {
            cout << "List is empty!\n";
            return;
        }
        CircularNode* curr = tail->next;
        if (curr == tail) {
            cout << "Deleted " << tail->data << " from end.\n";
            delete tail;
            tail = nullptr;
        } 
        else 
            while (curr->next != tail) 
                curr = curr->next;
        curr->next = tail->next;
        cout << "Deleted " << tail->data << " from end.\n";
        delete tail;
        tail = curr;
    }

    void display() {
        if (!tail) {
            cout << "Circular List is empty!\n";
            return;
        }
        CircularNode* curr = tail->next;
        cout << "Circular List: ";
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != tail->next);
        cout << endl;
    }
};

int main() {
    cout << "DOUBLY LINKED LIST OPERATIONS\n";
    DoublyLinkedList dll;
    dll.insertAtBeginning(10);
    dll.insertAtBeginning(20);
    dll.insertAtEnd(30);
    dll.display();
    dll.deleteAtBeginning();
    dll.display();
    dll.deleteAtEnd();
    dll.display();

    cout << "\nCIRCULAR LINKED LIST OPERATIONS\n";
    CircularLinkedList cll;
    cll.insertAtBeginning(10);
    cll.insertAtBeginning(20);
    cll.insertAtEnd(30);
    cll.display();
    cll.deleteAtBeginning();
    cll.display();
    cll.deleteAtEnd();
    cll.display();
    return 0;
}