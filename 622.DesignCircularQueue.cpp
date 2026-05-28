class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int tail;
    int current_size;
    int capacity;

public:
    MyCircularQueue(int k) {
        data.resize(k);
        capacity = k;
        head = 0;
        tail = -1;
        current_size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        tail = (tail + 1) % capacity;
        data[tail] = value;
        current_size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % capacity;
        current_size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[tail];
    }

    bool isEmpty() {
        return current_size == 0;
    }

    bool isFull() {
        return current_size == capacity;
    }
};