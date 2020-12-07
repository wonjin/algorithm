#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    Node* next;
    Node* prev;
    int data;
};

class Deque
{
    Node* header;
    Node* tail;
    int count;
public:
    Deque() : header(new Node), tail(new Node), count(0) {
        header->next = tail;
        header->prev = nullptr;
        tail->next = nullptr;
        tail->prev = header;
    }
    ~Deque() {
        while(!empty()) {
            pop_back();
        }
    }
    void push_front(int d) {
        Node* n = new Node;
        Node* next = header->next;
        n->data = d;
        n->next = next;
        n->prev = header;
        next->prev = n;
        header->next = n;
        count++;
    }
    void push_back(int d) {
        Node* n = new Node;
        Node* prev = tail->prev;
        n->data = d;
        n->prev = prev;
        n->next = tail;
        prev->next = n;
        tail->prev = n;
        count++;
    }
    int pop_front() {
        if(empty())
            return -1;
        Node* front = header->next;
        int value = front->data;
        header->next = front->next;
        front->next->prev = header;
        count--;
        delete front;
        return value;
    }
    int pop_back() {
        if(empty())
            return -1;
        Node* back = tail->prev;
        int value = back->data;
        tail->prev = back->prev;
        back->prev->next = tail;
        count--;
        delete back;
        return value;
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
        return header->next->data;
    }
    int back() {
        if(empty())
            return -1;
        return tail->prev->data;
    }
};

void algorithm(istream& is)
{
    int n;
    is >> n;

    Deque q;

    for(int i=0;i<n;++i) {
        string command;
        is >> command;

        if(command.compare("push_front") == 0) {
            int d;
            is >> d;
            q.push_front(d);
        }
        else if (command.compare("push_back") == 0) {
            int d;
            is >> d;
            q.push_back(d);
        }
        else if (command.compare("pop_front") == 0) {
            cout << q.pop_front() << "\n";
        }
        else if (command.compare("pop_back") == 0) {
            cout << q.pop_back() << "\n";
        }
        else if (command.compare("size") == 0) {
            cout << q.size() << "\n";
        }
        else if (command.compare("empty") == 0) {
            cout << q.empty() << "\n";
        }
        else if (command.compare("front") == 0) {
            cout << q.front() << "\n";
        }
        else if (command.compare("back") == 0) {
            cout << q.back() << "\n";
        }
        else {
            cout << "None\n";
        }
    }
}

int main(int argc, char const *argv[])
{
    // ifstream ifs("input.txt");
    // algorithm(ifs);
    algorithm(cin);
    return 0;
}
