#include <fstream>
#include <iostream>

using namespace std;

struct Node {
    Node(int x) : data(x), next(nullptr) {}
    Node* next;
    int data;
};

class Queue {
    Node* head;
    Node* tail;
    int count = 0;
public:
    Queue() {}
    ~Queue() {
        while(!empty()) {
            pop();
        }
    }
    void push(int x) {
        Node* n = new Node(x);
        if(count == 0) {
            tail = n;
            head = n;
        }
        else {
            tail->next = n;
            tail = n;
        }
        count++;
    }
    int pop() {
        if(empty())
            return -1;
        int v = head->data;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        count--;
        return v;
    }
    int size() {
        return count;
    }
    int empty() {
        return count == 0 ? 1 : 0;
    }
    int front() {
        if(empty())
            return -1;
        return head->data;
    }
    int back() {
        if(empty())
            return -1;
        return tail->data;
    }
};

int main(int argc, char const *argv[])
{
    ifstream ifs("input.txt");
    // istream& is = ifs;
    istream& is = cin;

    int n = 0;
    is >> n;

    Queue q;
    for(int i=0;i<n;++i) {
        std::string c;
        is >> c;

        if (c.compare("push") == 0) {
            int d;
            is >> d;
            q.push(d);
        }
        else if (c.compare("pop") == 0) {
            cout << q.pop() << "\n";
        }
        else if (c.compare("size") == 0) {
            cout << q.size() << "\n";
        }
        else if (c.compare("empty") == 0) {
            cout << q.empty() << "\n";
        }
        else if (c.compare("front") == 0) {
            cout << q.front() << "\n";
        }
        else if (c.compare("back") == 0) {
            cout << q.back() << "\n";
        }
        else {
            cout << "None\n";
        }
    }

    return 0;
}
