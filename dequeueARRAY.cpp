#include <iostream>
using namespace std;

class Dequeue {
    int *arr;
    int front, rear, size, capacity;

public:
    Dequeue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~Dequeue() {
        delete[] arr;
    }

    bool is_empty() {
        return size == 0;
    }

    bool is_full() {
        return size == capacity;
    }

    void push_front(int x) {
        if (is_full()) {
            cout << "Dequeue is full, cannot push at front.\n";
            return;
        }
        if (front == -1) {  // First element
            front = rear = 0;
        } else if (front == 0) {
            front = capacity - 1;  // Wrap around
        } else {
            front--;
        }
        arr[front] = x;
        size++;
    }

    void push_back(int x) {
        if (is_full()) {
            cout << "Dequeue is full, cannot push at back.\n";
            return;
        }
        if (rear == -1) {  // First element
            front = rear = 0;
        } else if (rear == capacity - 1) {
            rear = 0;  // Wrap around
        } else {
            rear++;
        }
        arr[rear] = x;
        size++;
    }

    void pop_front() {
        if (is_empty()) {
            cout << "Dequeue is empty, cannot pop from front.\n";
            return;
        }
        if (front == rear) {  // Only one element
            front = rear = -1;
        } else if (front == capacity - 1) {
            front = 0;  // Wrap around
        } else {
            front++;
        }
        size--;
    }

    void pop_back() {
        if (is_empty()) {
            cout << "Dequeue is empty, cannot pop from back.\n";
            return;
        }
        if (front == rear) {  // Only one element
            front = rear = -1;
        } else if (rear == 0) {
            rear = capacity - 1;  // Wrap around
        } else {
            rear--;
        }
        size--;
    }

    int get_front() {
        if (is_empty()) {
            cout << "Dequeue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    int get_back() {
        if (is_empty()) {
            cout << "Dequeue is empty.\n";
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    int capacity = 5;
    Dequeue dq(capacity);

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
