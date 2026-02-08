#include <iostream>
#include <string>
using namespace std;

struct Song {
    int id;
    string title;
    Song* next;
    Song* prev;
};

class Playlist {
private:
    Song* head;

public:
    Playlist() {
        head = NULL;
    }

    void insert(int id, string title) {
        Song* temp = new Song;
        temp->id = id;
        temp->title = title;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL) {
            head = temp;
        } else {
            Song* cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = temp;
            temp->prev = cur;
        }
    }

    void display() {
        Song* cur = head;
        while (cur != NULL) {
            cout << cur->id << "  " << cur->title << endl;
            cur = cur->next;
        }
    }

    void moveToFront(int id) {
        Song* cur = head;

        while (cur != NULL && cur->id != id) {
            cur = cur->next;
        }

        if (cur == NULL || cur == head) {
            return;
        }

        cur->prev->next = cur->next;
        if (cur->next != NULL) {
            cur->next->prev = cur->prev;
        }

        cur->prev = NULL;
        cur->next = head;
        head->prev = cur;
        head = cur;
    }
};

int main() {
    Playlist p;
    int choice, id;
    string title;

    do {
        cout << "\n1. Insert Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Move To Front\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter Song ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Song Title: ";
            getline(cin, title);
            p.insert(id, title);
            break;

        case 2:
            p.display();
            break;

        case 3:
            cout << "Enter ID to move to front: ";
            cin >> id;
            p.moveToFront(id);
            break;

        case 4:
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
