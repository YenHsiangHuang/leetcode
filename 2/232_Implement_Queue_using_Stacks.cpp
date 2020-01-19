#include <iostream>
#include <stack>

struct Queue {
    Queue() {}

    void push(int x) {
        input.push(x);
    }

    int pop() {
        int res = peek();
        output.pop();

        return res;
    }

    int peek() {
        if (output.empty())
            move_to_output();
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }

    void move_to_output() {
        while (!input.empty()) {
            output.push(input.top());
            input.pop();
        }
    }

    std::stack<int> input, output;
};



int main(int argc, const char *argv[]) {
    Queue q;
    q.push(1);
    q.push(2);

    std::cout << q.pop() << std::endl;
    std::cout << q.peek() << std::endl;
    std::cout << q.empty() << std::endl;

    return 0;
}

