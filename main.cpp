// Exercise 1
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* insert(Node* head, int val) {
    if (!head) return new Node(val);
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
    return head;
}

void findMiddle(Node* head) {
    if (head == nullptr) return;

    Node *slow = head, *fast = head;
    Node *prev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == nullptr && prev != nullptr) {
        cout << "2 middle numbers are: " << prev->data << " and " << slow->data << endl;
    } else {
        cout << "The middle number is: " << slow->data << endl;
    }
}

int main() {
    Node* head = nullptr;
    int n, val;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of element " << i + 1 << ": ";
        cin >> val;
        head = insert(head, val);
    }

    findMiddle(head);

    return 0;
}
// Exercise 2
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* insert(Node* head, int val) {
    if (!head) return new Node(val);
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
    return head;
}

bool hasCycle(Node* head) {
    if (head == nullptr) return false;
    Node *slow = head, *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    Node* head = nullptr;
    int n, val;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of element " << i + 1 << ": ";
        cin >> val;
        head = insert(head, val);
    }

    if (hasCycle(head)) cout << "Cycle valid!" << endl;
    else cout << "Cycle invalid." << endl;
    return 0;
}

// Exercise 3
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}

void insert(ListNode*& head, int val) {
    ListNode* newNode = new ListNode(val);
    if (head == NULL) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
ListNode* createLinkedList(int n) {
    ListNode* head = NULL;
    cout << "Enter " << n << " sorted values for the linked list: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        insert(head, val);
    }
    return head;
}

// Helper function to print a linked list
void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " -> ";
        node = node->next;
    }
    cout << "NULL" << endl;
}

int main() {
    int n1, n2;

    cout << "Enter the number of elements in the first sorted linked list: ";
    cin >> n1;
    ListNode* l1 = createLinkedList(n1);

    cout << "Enter the number of elements in the second sorted linked list: ";
    cin >> n2;
    ListNode* l2 = createLinkedList(n2);

    ListNode* result = mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(result);

    return 0;
}


//Exercise 4
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SingleLinkedList {
public:
    Node* head;

    SingleLinkedList() : head(nullptr) {}

    void Insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void Display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void GetIntersection(SingleLinkedList L1) {
        Node* Cur = head;
        bool found = false;
        cout << "Intersection: ";
        while (Cur != nullptr) {
            Node* Cur1 = L1.head;
            while (Cur1 != nullptr) {
                if (Cur->data == Cur1->data) {
                    cout << Cur->data << " ";
                    found = true;
                }
                Cur1 = Cur1->next;
            }
            Cur = Cur->next;
        }
        if (!found) {
            cout << "No intersection";
        }
        cout << endl;
    }
};
int main() {
    SingleLinkedList L1, L2;
    int n1, n2, value;

    cout << "Enter the number of elements in the first list: ";
    cin >> n1;
    cout << "Enter elements for the first list:\n";
    for (int i = 0; i < n1; ++i) {
        cin >> value;
        L1.Insert(value);
    }

    cout << "Enter the number of elements in the second list: ";
    cin >> n2;
    cout << "Enter elements for the second list:\n";
    for (int i = 0; i < n2; ++i) {
        cin >> value;
        L2.Insert(value);
    }

    cout << "First list: ";
    L1.Display();
    cout << "Second list: ";
    L2.Display();
    L1.GetIntersection(L2);

    return 0;
}

// Exercise 5
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* insert(Node* head, int val) {
    if (!head) return new Node(val);
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
    return head;
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    Node* head = nullptr;
    int n, val;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of element " << i + 1 << ": ";
        cin >> val;
        head = insert(head, val);
    }

    Node* reversed = reverseList(head);

    cout << "List after reverse: ";
    while (reversed != nullptr) {
        cout << reversed->data << " ";
        reversed = reversed->next;
    }
    cout << endl;
    return 0;
}

//Exercise 6
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* insert(Node* head, int val) {
    if (!head) return new Node(val);
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
    return head;
}

Node* removeDuplicates(Node* head) {
    if (!head) return nullptr;
    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, val;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of element " << i + 1 << ": ";
        cin >> val;
        head = insert(head, val);
    }

    head = removeDuplicates(head);

    cout << "List after removing duplicate elements: ";
    printList(head);

    return 0;
}

// Exercise 7
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* insert(Node* head, int val) {
    if (!head) return new Node(val);
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
    return head;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next) return true;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow = reverse(slow);
    Node* firstHalf = head;

    while (slow != nullptr) {
        if (firstHalf->data != slow->data)
            return false;
        firstHalf = firstHalf->next;
        slow = slow->next;
    }
    return true;
}

int main() {
    Node* head = nullptr;
    int n, val;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of element " << i + 1 << ": ";
        cin >> val;
        head = insert(head, val);
    }

    if (isPalindrome(head))
        cout << "List is Palindrome" << endl;
    else
        cout << "List is not Palindrome" << endl;

    return 0;
}

//Exercise 8
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

Node* insert(Node* head, int val) {
    if (!head) return new Node(val);
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = new Node(val);
    return head;
}

void searchValue(Node* head, int x) {
    Node* temp = head;
    bool found = false;

    while (temp != nullptr) {
        if (temp->data == x) {
            found = true;
            cout << "Node with value " << x << " has the address: " << temp << endl;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Can not find the value " << x << " in the list." << endl;
    }
}

int main() {
    Node* head = nullptr;
    int n, val, x;
    cout << "Enter the number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value of element " << i + 1 << ": ";
        cin >> val;
        head = insert(head, val);
    }

    cout << "Enter the value to search: ";
    cin >> x;

    searchValue(head, x);

    return 0;
}