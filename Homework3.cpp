#include <iostream>
#include <string>

using namespace std;

struct Node {
    int exPireTime;
    string tokenId;
    Node *next;

    Node(string id, int time) : exPireTime(time), tokenId(id), next(nullptr) {}
};

class AuthenticationManager {
private:
    int timeTolive;
    Node *head;

    void removeExpireTime(int currentTime) {
        while (head != nullptr && head->exPireTime < currentTime) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    AuthenticationManager(int timeToLive) : timeTolive(timeToLive), head(nullptr) {}

    void generate(string tokenId, int currentTime) {
        removeExpireTime(currentTime);
        Node *newNode = new Node(tokenId, currentTime + timeTolive);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void renewToken(string tokenId, int currentTime) {
        removeExpireTime(currentTime);
        Node *temp = head;

        while (temp) {
            if (temp->tokenId == tokenId && temp->exPireTime > currentTime) {
                temp->exPireTime = timeTolive + currentTime;
                return;
            }
            temp = temp->next;
        }
    }

    int countUnexpiredTokens(int currentTime) {
        removeExpireTime(currentTime);
        Node *temp = head;
        int count = 0;
        while (temp) {
            if (temp->exPireTime > currentTime) count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    int time;
    cout << "Enter the time to live for the token (in seconds): ";
    cin >> time;

    AuthenticationManager auth(time);
    cout << "Authentication Manager initialized. Type 'help' for available commands." << endl;

    string command;
    cin.ignore();

    while (true) {
        cout << "\nEnter command: ";
        getline(cin, command);

        if (command == "help") {
            cout << "Available commands:" << endl;
            cout << " - generate: Create a new token." << endl;
            cout << " - renew: Renew an existing token." << endl;
            cout << " - counttoken: Count the number of valid tokens." << endl;
            cout << " - exit: Exit the program." << endl;
        } else if (command == "generate") {
            string tokenId;
            cout << "Enter token ID: ";
            getline(cin, tokenId);
            int currentTime;
            cout << "Enter current time (in seconds): ";
            cin >> currentTime;
            cin.ignore();

            auth.generate(tokenId, currentTime);
            cout << "Token generated successfully." << endl;
        } else if (command == "renew") {
            string tokenId;
            cout << "Enter token ID to renew: ";
            getline(cin, tokenId);
            int currentTime;
            cout << "Enter current time (in seconds): ";
            cin >> currentTime;
            cin.ignore();

            auth.renewToken(tokenId, currentTime);
            cout << "Token renewed successfully, if it was valid." << endl;
        } else if (command == "counttoken") {
            int currentTime;
            cout << "Enter current time (in seconds): ";
            cin >> currentTime;
            cin.ignore();

            int count = auth.countUnexpiredTokens(currentTime);
            cout << "Number of valid tokens: " << count << endl;
        } else if (command == "exit") {
            cout << "Exiting the program." << endl;
            break;
        } else {
            cout << "Invalid command. Type 'help' for a list of available commands." << endl;
        }
    }

    return 0;
}
