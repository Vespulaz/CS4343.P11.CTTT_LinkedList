#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BrowserHistory {
private:
    string history[5000];
    int currentIndex;
    int size;

public:
    BrowserHistory(string homepage) {
        history[0] = homepage;
        currentIndex = 0;
        size = 1;
    }

    void visit(string url) {
        currentIndex++;
        history[currentIndex] = url;
        size = currentIndex + 1;
    }
    
    string back(int steps) {
        currentIndex = max(0, currentIndex - steps);
        return history[currentIndex];
    }
    
    string forward(int steps) {
        currentIndex = min(size - 1, currentIndex + steps);
        return history[currentIndex];
    }
};

int main() {
    BrowserHistory browser("uit.edu.vn");
    
    browser.visit("google.com");
    browser.visit("facebook.com");
    browser.visit("youtube.com");
    
    cout << browser.back(1) << endl;
    cout << browser.back(1) << endl;
    
    cout << browser.forward(1) << endl;
    
    browser.visit("linkedin.com");
    
    cout << browser.forward(2) << endl;
    
    cout << browser.back(2) << endl;
    
    cout << browser.back(7) << endl;

    return 0;
}
