#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
private:
    stack<int> stack1;  // 用于入队
    stack<int> stack2;  // 用于出队

public:
    MyQueue() {}

    // 入队操作
    void enqueue(int x) {
        stack1.push(x);
    }

    // 出队操作
    int dequeue() {
        if (stack2.empty()) {
            // 将 stack1 中的元素倒入 stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            throw out_of_range("Queue is empty");  // 如果 stack2 依然为空，抛出异常
        }
        int result = stack2.top();
        stack2.pop();
        return result;
    }

    // 获取队头元素
    int front() {
        if (stack2.empty()) {
            // 将 stack1 中的元素倒入 stack2
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            throw out_of_range("Queue is empty");  // 如果 stack2 依然为空，抛出异常
        }
        return stack2.top();
    }

    // 判断队列是否为空
    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    MyQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << "Front element: " << q.front() << endl;  // 输出队头元素 1
    cout << "Dequeue element: " << q.dequeue() << endl;  // 出队 1
    cout << "Front element: " << q.front() << endl;  // 输出队头元素 2
    cout << "Dequeue element: " << q.dequeue() << endl;  // 出队 2

    q.enqueue(4);
    cout << "Front element: " << q.front() << endl;  // 输出队头元素 3
    cout << "Dequeue element: " << q.dequeue() << endl;  // 出队 3
    cout << "Dequeue element: " << q.dequeue() << endl;  // 出队 4

    // 检查队列是否为空
    if (q.isEmpty()) {
        cout << "Queue is empty now." << endl;
    }

    return 0;
}
