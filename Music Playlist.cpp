#include <iostream>
#include <string>
using namespace std;

struct Song {
    int id;
    string title;
    string artist;
    double duration;
    Song* next;
    Song* prev;
};

class Playlist {
private:
    Song* head;
    Song* current; 

public:
    Playlist() {
        head = NULL;
        current = NULL;
    }

    
    void insert(int id, string title, string artist, double duration) {
        Song* temp = new Song;
        temp->id = id;
        temp->title = title;
        temp->artist = artist;
        temp->duration = duration;
        temp->next = NULL;
        temp->prev = NULL;

        if (head == NULL) {
            head = temp;
            current = head;
        } else {
            Song* cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            cur->next = temp;
            temp->prev = cur;
        }
        cout << "Song added to playlist!" << endl;
    }

    
    void display() {
        if (head == NULL) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        Song* cur = head;
        int count = 0;
        double totalDuration = 0.0;
        cout << "\n===== Playlist =====\n";
        while (cur != NULL) {
            cout << "ID: " << cur->id << endl;
            cout << "Title: " << cur->title << endl;
            cout << "Artist: " << cur->artist << endl;
            cout << "Duration: " << cur->duration << " min" << endl;
            cout << "-------------------" << endl;
            totalDuration += cur->duration;
            count++;
            cur = cur->next;
        }
        cout << "Total Songs: " << count << endl;
        cout << "Total Duration: " << totalDuration << " min" << endl;
    }

    
    void search(string key) {
        if (head == NULL) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        Song* cur = head;
        bool found = false;
        while (cur != NULL) {
            if (cur->title == key || cur->artist == key) {
                cout << "Song Found!" << endl;
                cout << "ID: " << cur->id << endl;
                cout << "Title: " << cur->title << endl;
                cout << "Artist: " << cur->artist << endl;
                cout << "Duration: " << cur->duration << " min" << endl;
                found = true;
            }
            cur = cur->next;
        }
        if (!found) {
            cout << "No song found with given Title/Artist!" << endl;
        }
    }

    
    void modify(int id, string newTitle, string newArtist, double newDuration) {
        Song* cur = head;
        while (cur != NULL) {
            if (cur->id == id) {
                cur->title = newTitle;
                cur->artist = newArtist;
                cur->duration = newDuration;
                cout << "Song details updated!" << endl;
                return;
            }
            cur = cur->next;
        }
        cout << "Song with given ID not found!" << endl;
    }

    
    void playNext() {
        if (current == NULL) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        if (current->next != NULL) {
            current = current->next;
            cout << "Now Playing: " << current->title << " by " << current->artist << endl;
        } else {
            cout << "You are at the last song!" << endl;
        }
    }

    
    void playPrevious() {
        if (current == NULL) {
            cout << "Playlist is empty!" << endl;
            return;
        }
        if (current->prev != NULL) {
            current = current->prev;
            cout << "Now Playing: " << current->title << " by " << current->artist << endl;
        } else {
            cout << "You are at the first song!" << endl;
        }
    }
};

int main() {
    Playlist p;
    int choice;

    do {
        cout << "\n===== Music Playlist Menu =====" << endl;
        cout << "1. Insert Song" << endl;
        cout << "2. Display Playlist" << endl;
        cout << "3. Search Song" << endl;
        cout << "4. Modify Song" << endl;
        cout << "5. Play Next Song" << endl;
        cout << "6. Play Previous Song" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                int id;
                string title, artist;
                double duration;
                cout << "Enter Song ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Song Title: ";
                getline(cin, title);
                cout << "Enter Artist Name: ";
                getline(cin, artist);
                cout << "Enter Duration (minutes): ";
                cin >> duration;
                cin.ignore();
                p.insert(id, title, artist, duration);
                break;
            }
            case 2:
                p.display();
                break;
            case 3: {
                string key;
                cout << "Enter Song Title or Artist to Search: ";
                getline(cin, key);
                p.search(key);
                break;
            }
            case 4: {
                int id;
                string title, artist;
                double duration;
                cout << "Enter Song ID to Modify: ";
                cin >> id;
                cin.ignore();
                cout << "Enter New Title: ";
                getline(cin, title);
                cout << "Enter New Artist: ";
                getline(cin, artist);
                cout << "Enter New Duration (minutes): ";
                cin >> duration;
                cin.ignore();
                p.modify(id, title, artist, duration);
                break;
            }
            case 5:
                p.playNext();
                break;
            case 6:
                p.playPrevious();
                break;
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
    