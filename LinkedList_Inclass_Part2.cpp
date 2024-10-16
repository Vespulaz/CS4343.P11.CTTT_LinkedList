// STT: 8
// Full Name: Tran Duy Hai Dang
// In-class Exercise - Part 2

// Exercise 1
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values from both lists or 0 if list ended
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            // Calculate sum and carry
            int sum = carry + x + y;
            carry = sum / 10;

            // Create new node with ones digit of sum
            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            // Move to next nodes if available
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummyHead->next;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create first linked list: 2 -> 4 -> 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Create second linked list: 5 -> 6 -> 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}

// Exercise 2
#include <iostream>
using namespace std;

// Definition for Node with a random pointer
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // First pass: create copy nodes and insert them after original nodes
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        // Second pass: assign random pointers for copy nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Third pass: separate original and copy lists
        Node* dummyHead = new Node(0);
        Node* copyTail = dummyHead;
        curr = head;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            copyTail->next = copy;
            copyTail = copy;
            curr = curr->next;
        }

        return dummyHead->next;
    }
};

// Helper function to print the list (only next pointers)
void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Set some random pointers
    head->random = head->next->next; // 1's random points to 3
    head->next->random = head; // 2's random points to 1
    head->next->next->random = head->next; // 3's random points to 2

    Solution solution;
    Node* copiedList = solution.copyRandomList(head);

    cout << "Original list: ";
    printList(head);
    cout << "Copied list: ";
    printList(copiedList);

    return 0;
}

// Exercise 3
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        ListNode* first = nullptr;

        // Move fast pointer to the kth node
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
        first = fast;  // Save the kth node from the beginning

        // Move both pointers until fast reaches the end
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        // Swap the values of the kth node from the beginning and kth node from the end
        int temp = first->val;
        first->val = slow->next->val;
        slow->next->val = temp;

        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    int k = 2;  // Swap the 2nd node from the beginning with the 2nd node from the end
    ListNode* result = solution.swapNodes(head, k);

    cout << "List after swapping (k=" << k << "): ";
    printList(result);

    return 0;
}

// Exercise 4
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;

        // Advance first pointer so that the gap between first and second is n nodes apart
        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }

        // Move first to the end, maintaining the gap
        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        // Remove the nth node from the end
        second->next = second->next->next;

        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    int n = 2;  // Remove the 2nd node from the end
    ListNode* result = solution.removeNthFromEnd(head, n);

    cout << "List after removing " << n << "th node from the end: ";
    printList(result);

    return 0;
}

// Exercise 5
#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* result = solution.oddEvenList(head);

    cout << "List after separating odd and even nodes: ";
    printList(result);

    return 0;
}

// Exercise 6
#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Count the length of the linked list
        int length = 0;
        ListNode* current = head;
        while (current) {
            length++;
            current = current->next;
        }

        // Calculate the size of each part and the number of extra nodes
        int base_size = length / k;
        int extra = length % k;

        vector<ListNode*> result(k, nullptr);
        current = head;

        for (int i = 0; i < k; i++) {
            if (!current) break;

            result[i] = current;
            int part_size = base_size + (i < extra ? 1 : 0);

            for (int j = 0; j < part_size - 1; j++) {
                current = current->next;
            }

            ListNode* next = current->next;
            current->next = nullptr;
            current = next;
        }

        return result;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    for (int i = 2; i <= 10; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }

    cout << "Original list: ";
    printList(head);

    Solution solution;
    int k = 3;  // Divide the list into 3 parts
    vector<ListNode*> result = solution.splitListToParts(head, k);

    cout << "List divided into " << k << " parts:" << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << "Part " << i+1 << ": ";
        printList(result[i]);
    }

    return 0;
}

// Exercise 7
#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Simple hash table implementation
const int TABLE_SIZE = 10007;  // A prime number for better distribution

struct HashNode {
    int key;
    ListNode* value;
    HashNode* next;
    HashNode(int k, ListNode* v) : key(k), value(v), next(nullptr) {}
};

class HashMap {
private:
    HashNode* table[TABLE_SIZE];

    int hash(int key) {
        return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
    }

public:
    HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void put(int key, ListNode* value) {
        int index = hash(key);
        HashNode* newNode = new HashNode(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    ListNode* get(int key) {
        int index = hash(key);
        HashNode* current = table[index];
        while (current) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return nullptr;
    }

    void remove(int key) {
        int index = hash(key);
        HashNode* current = table[index];
        HashNode* prev = nullptr;
        while (current) {
            if (current->key == key) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    table[index] = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        HashMap prefixSum;
        int sum = 0;

        for (ListNode* current = dummy; current != nullptr; current = current->next) {
            sum += current->val;

            if (prefixSum.get(sum) != nullptr) {
                ListNode* prev = prefixSum.get(sum);
                ListNode* toRemove = prev->next;
                int tempSum = sum + toRemove->val;

                while (tempSum != sum) {
                    prefixSum.remove(tempSum);
                    toRemove = toRemove->next;
                    tempSum += toRemove->val;
                }

                prev->next = current->next;
            } else {
                prefixSum.put(sum, current);
            }
        }

        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> -3 -> 3 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    std::cout << "Original list: ";
    printList(head);

    Solution solution;
    ListNode* result = solution.removeZeroSumSublists(head);

    std::cout << "List after removing zero-sum consecutive nodes: ";
    printList(result);

    return 0;
}

// Exercise 8
#include <iostream>
#include <cstdlib>
#include <ctime>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to insert a node at the end of the list
void insertAtEnd(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to generate a random integer within a given range
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Function to create a list with random values
ListNode* createRandomList() {
    ListNode* head = nullptr;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Randomly choose the number of entries [39, 59]
    int numEntries = randomInt(39, 59);

    // Generate random values and insert them into the list
    for (int i = 0; i < numEntries; ++i) {
        int value = randomInt(-99, 99);
        insertAtEnd(head, value);
    }

    return head;
}

// Helper function to print the list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* myList = createRandomList();

    std::cout << "Generated list: " << std::endl;
    printList(myList);

    // Count the number of nodes
    int count = 0;
    ListNode* current = myList;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    std::cout << "Number of nodes: " << count << std::endl;

    // Clean up the memory
    while (myList != nullptr) {
        ListNode* temp = myList;
        myList = myList->next;
        delete temp;
    }

    return 0;
}


