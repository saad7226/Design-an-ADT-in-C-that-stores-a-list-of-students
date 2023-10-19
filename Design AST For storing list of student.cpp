/*Design an ADT in C++ that stores a list of students having following functionalities:
1. Insert an element
a. Beginning
b. End
c. Given index (optional/not mandatory)
2. Show all elements
a. From first to last
b. From last to first (Using Stack)
3. Delete an Element
a. You will prompt user to enter the number to be deleted
b. Use search method to find the index
c. Perform delete operation

Important Notes:
? ADT must use Liked List

*/


#include <iostream>
#include <string>
using namespace std;

struct Node {
    string student;
    Node* next;

    Node(string std) {
        student = std;
        next = NULL;
    }
};

class Stackforlist {
private:
    Node* top;

public:
    Stackforlist() {
        top = NULL;
    }

    void Push(string std) {
        Node* newNode = new Node(std);
        newNode->next = top;
        top = newNode;
    }

    string Pop() {
        if (top == NULL) {
            return "";
        }

        string poppedValue = top->student;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    bool is_Empty() {
        return top == NULL;
    }
};

class StudentList {
private:
    Node* head;

public:
    StudentList() {
        head = NULL;
    }

    void insertAtBeginning(string std) {
        Node* temp = new Node(std);
        if (head == NULL) {
            head = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void insertAtEnd(string std) {
        Node* temp = new Node(std);
        if (head == NULL) {
            head = temp;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = temp;
        }
    }

    void insertAtIndex(string std, int position) {
        if (position < 0) {
            cout << "Invalid index." << endl;
            return;
        }
        if (position == 0) {
            insertAtBeginning(std);
            return;
        }

        Node* newNode = new Node(std);
        if (newNode == NULL) {
            cout << "Memory allocation failed." << endl;
            return;
        }

        Node* current = head;
        Node* previous = NULL;
        int currentIndex = 0;

        while (current != NULL && currentIndex < position) {
            previous = current;
            current = current->next;
            currentIndex++;
        }

        if (currentIndex < position) {
            cout << "Index out of bounds." << endl;
            delete newNode;
            return;
        }

        newNode->next = current;
        if (previous != NULL) {
            previous->next = newNode;
        } else {
            head = newNode;
        }
    }

    void deleteElement(string std) {
        Node* current = head;
        Node* previous = NULL;

        while (current != NULL && current->student != std) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Student not found." << endl;
            return;
        }

        if (previous != NULL) {
            previous->next = current->next;
        } else {
            head = current->next;
        }

        delete current;
    }

    void displayFromFirstToLast() {
        Node* current = head;
        while (current != NULL) {
            cout << current->student << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void displayFromLastToFirst() {
        Node* current = head;
        Stackforlist stack;

        while (current != NULL) {
            stack.Push(current->student);
            current = current->next;
        }

        while (!stack.is_Empty()) {
            cout << stack.Pop() << " -> ";
        }
        cout << "NULL" << endl;
    }

    bool searchStudent(string std) {
        Node* current = head;
        while (current != NULL) {
            if (current->student == std) {
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

int main() {
    StudentList studentList;

    studentList.insertAtBeginning("Alice");
    studentList.insertAtEnd("Bob");
    studentList.insertAtIndex("Charlie", 1);
    studentList.insertAtIndex("David", 0);

    cout << "Students (from first to last): ";
    studentList.displayFromFirstToLast();

    cout << "Students (from last to first): ";
    studentList.displayFromLastToFirst();

    studentList.deleteElement("Bob");
    cout << "After deleting Bob:" << endl;
    cout << "Students (from first to last): ";
    studentList.displayFromFirstToLast();

    cout << "Search for Alice: " << studentList.searchStudent("Alice") << endl;
    cout << "Search for Eve: " << studentList.searchStudent("Eve") << endl;

    return 0;
}
//This code includes all the functions you provided, and it demonstrates the functionality of the StudentList class as per your requirements.






