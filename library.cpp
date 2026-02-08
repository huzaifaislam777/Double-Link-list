#include <iostream>
#include <string>
using namespace std;
struct node {
    int isbn;
    string title;
    string author;
    int year;
    node* next;
    node* prev;
};
class list {
private:
    node* head;
public:
    list() {
        head = NULL;
    }
    void insert(int i, string t, string a, int y) {
        node* temp = new node;
        temp->isbn = i;
        temp->title = t;
        temp->author = a;
        temp->year = y;
        temp->next = NULL;
        temp->prev = NULL;
        if (head == NULL) {
            head = temp;
        } else {
            node* cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = temp;
            temp->prev = cur;
        }
    }
    void display() {
        node* cur = head;

        if (cur == NULL) {
            cout << "No Books Available" << endl;
            return;
        }
        while (cur != NULL) {
            cout << "ISBN: " << cur->isbn << endl;
            cout << "Title: " << cur->title << endl;
            cout << "Author: " << cur->author << endl;
            cout << "Year: " << cur->year << endl;
            cout << "--------------------" << endl;
            cur = cur->next;
        }
    }
    void search(int key) {
        node* cur = head;
        while (cur != NULL) {
            if (cur->isbn == key) {
                cout << "Book Found" << endl;
                cout << "ISBN: " << cur->isbn << endl;
                cout << "Title: " << cur->title << endl;
                cout << "Author: " << cur->author << endl;
                cout << "Year: " << cur->year << endl;
                return;
            }
            cur = cur->next;
        }
        cout << "Book Not Found" << endl;
    }
    void modify(int key, string newTitle, string newAuthor, int newYear) {
        node* cur = head;
        while (cur != NULL) {
            if (cur->isbn == key) {
                cur->title = newTitle;
                cur->author = newAuthor;
                cur->year = newYear;
                cout << "Book Record Updated" << endl;
                return;
            }
            cur = cur->next;
        }
        cout << "Book Not Found" << endl;
    }
};
int main() {
    list l1;
    int choice;
    do {
        cout << "\n===== Library Management System =====" << endl;
        cout << "1. Insert Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Modify Book" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int isbn, year;
            string title, author;
            cout << "Enter ISBN: ";
            cin >> isbn;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter Year: ";
            cin >> year;
            l1.insert(isbn, title, author, year);
            break;
        }
        case 2:
            l1.display();
            break;
        case 3: {
            int key;
            cout << "Enter ISBN to Search: ";
            cin >> key;
            l1.search(key);
            break;
        }
        case 4: {
            int key, year;
            string title, author;
            cout << "Enter ISBN to Modify: ";
            cin >> key;
            cin.ignore();
            cout << "Enter New Title: ";
            getline(cin, title);
            cout << "Enter New Author: ";
            getline(cin, author);
            cout << "Enter New Year: ";
            cin >> year;
            l1.modify(key, title, author, year);
            break;
        }
        case 5:
            cout << "Program Exit" << endl;
            break;
        default:
            cout << "Invalid Choice" << endl;
        }
    } while (choice != 5);
    return 0;
}
    