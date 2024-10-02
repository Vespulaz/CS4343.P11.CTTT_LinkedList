#include <iostream>
#include <string>

using namespace std;

struct Song {
    string name;
    Song* next;
    Song* prev;

    Song(const string& songName) : name(songName), next(nullptr), prev(nullptr) {}
};

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addSong(const string& songName) {
        Song* newSong = new Song(songName);
        if (!head) {
            head = newSong;
            tail = newSong;
            current = newSong;
        } else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
            tail->next = head; // Make it circular
            head->prev = tail; // Make it circular
        }
    }

    void playNext() {
        if (current) {
            current = current->next;
        }
    }

    void playPrevious() {
        if (current) {
            current = current->prev;
        }
    }

    void removeSong(const string& songName) {
        Song* temp = head;
        if (!head) return; // Empty list

        do {
            if (temp->name == songName) {
                if (temp == head && temp == tail) { // Only one song
                    delete temp;
                    head = tail = current = nullptr;
                } else if (temp == head) { // Remove head
                    head = head->next;
                    head->prev = tail;
                    tail->next = head;
                    delete temp;
                } else if (temp == tail) { // Remove tail
                    tail = tail->prev;
                    tail->next = head;
                    head->prev = tail;
                    delete temp;
                } else { // Remove middle song
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    delete temp;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void displayPlaylist() {
        if (!head) {
            cout << endl; // Empty playlist
            return;
        }

        Song* temp = head;
        do {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Playlist playlist;

    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string songName;
            cin >> songName;
            playlist.addSong(songName);
        } else if (command == "NEXT") {
            playlist.playNext();
        } else if (command == "PREV") {
            playlist.playPrevious();
        } else if (command == "REMOVE") {
            string songName;
            cin >> songName;
            playlist.removeSong(songName);
        } else if (command == "DISPLAY") {
            playlist.displayPlaylist();
        }
    }

    return 0;
}
