#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class Dequeue {
public:
    Node *front, *rear;

    Dequeue() {
        front = NULL;
        rear = NULL;
    }

    void push_front(int x) {
        if (front == NULL) {
            front = rear = new Node(x);
        } else {
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }

    void push_back(int x) {
        if (front == NULL) {
            front = rear = new Node(x);
        } else {
            Node *temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }

    void pop_front() {
        if (front == NULL) {
            cout << "Dequeue is empty, cannot pop from front.\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front != NULL) {
            front->prev = NULL;
        } else {
            rear = NULL;
        }
        delete temp;
    }

    void pop_back() {
        if (rear == NULL) {
            cout << "Dequeue is empty, cannot pop from back.\n";
            return;
        }
        Node *temp = rear;
        rear = rear->prev;
        if (rear != NULL) {
            rear->next = NULL;
        } else {
            front = NULL;
        }
        delete temp;
    }

    int get_front() {
        if (front == NULL) {
            cout << "Dequeue is empty.\n";
            return -1;
        }
        return front->data;
    }

    int get_back() {
        if (rear == NULL) {
            cout << "Dequeue is empty.\n";
            return -1;
        }
        return rear->data;
    }

    bool is_empty() {
        return front == NULL;
    }
};

int main() {
    Dequeue dq;

    dq.push_front(10);
    dq.push_back(20);
    dq.push_front(5);

    cout << "Front element: " << dq.get_front() << endl;
    cout << "Rear element: " << dq.get_back() << endl;

    dq.pop_front();
    cout << "After popping front, new front element: " << dq.get_front() << endl;

    dq.pop_back();
    cout << "After popping back, new rear element: " << dq.get_back() << endl;

    if (dq.is_empty()) {
        cout << "Dequeue is empty." << endl;
    } else {
        cout << "Dequeue is not empty." << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class Dequeue {
public:
    Node *front, *rear;

    Dequeue() {
        front = NULL;
        rear = NULL;
    }

    void push_front(int x) {
        if (front == NULL) {
            front = rear = new Node(x);
        } else {
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
        }
    }

    void push_back(int x) {
        if (front == NULL) {
            front = rear = new Node(x);
        } else {
            Node *temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
        }
    }

    void pop_front() {
        if (front == NULL) {
            cout << "Dequeue is empty, cannot pop from front.\n";
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front != NULL) {
            front->prev = NULL;
        } else {
            rear = NULL;
        }
        delete temp;
    }

    void pop_back() {
        if (rear == NULL) {
            cout << "Dequeue is empty, cannot pop from back.\n";
            return;
        }
        Node *temp = rear;
        rear = rear->prev;
        if (rear != NULL) {
            rear->next = NULL;
        } else {
            front = NULL;
        }
        delete temp;
    }

    int get_front() {
        if (front == NULL) {
            cout << "Dequeue is empty.\n";
            return -1;
        }
        return front->data;
    }

    int get_back() {
        if (rear == NULL) {
            cout << "Dequeue is empty.\n";
            return -1;
        }
        return rear->data;
    }

    bool is_empty() {
        return front == NULL;
    }
};

int main() {
    Dequeue dq;

    dq.push_front(10);
    dq.push_back(20);
    dq.push_front(5);

    cout << "Front element: " << dq.get_front() << endl;
    cout << "Rear element: " << dq.get_back() << endl;

    dq.pop_front();
    cout << "After popping front, new front element: " << dq.get_front() << endl;

    dq.pop_back();
    cout << "After popping back, new rear element: " << dq.get_back() << endl;

    if (dq.is_empty()) {
        cout << "Dequeue is empty." << endl;
    } else {
        cout << "Dequeue is not empty." << endl;
    }

    return 0;
}
