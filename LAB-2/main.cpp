#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class SingleLinkedList {
    private:
    Node* head;

    public:
    SingleLinkedList() {
        head = NULL;
    }

    void append(string word) {
        Node* newNode = new Node;
        newNode->data = word;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void undo() {
        if (head == NULL) {
            cout << "Silinecek bir kelime yok." << endl;
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "[" << temp->data << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SingleLinkedList editor;
    string input;

    while (true) {
        cout << "Enter a word (UNDO / EXIT): ";
        cin >> input;

        if (input == "EXIT") {
            break;
        }
        else if (input == "UNDO") {
            editor.undo();
        }
        else {
            editor.append(input);
        }

        editor.display();
    }

    return 0;
}
