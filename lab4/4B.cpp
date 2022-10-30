#include <iostream>
#include <cstdio>
 
using namespace std;
 
struct MyStack {
    int *my_stack = NULL;
    int length = 0;
 
public:
    void push(int element) {
        int *temp_stack = new int[++length];
        memcpy(temp_stack, my_stack, (length - 1) * sizeof(int));
        temp_stack[length - 1] = element;
        delete[] my_stack;
        my_stack = temp_stack;
    }
 
    int pop() {
        int popped = my_stack[length - 1];
        int *temp_stack = new int[--length];
        memcpy(temp_stack, my_stack, length * sizeof(int));
        delete[] my_stack;
        my_stack = temp_stack;
        return popped;
    }
 
    bool empty() {
        return length == 0;
    }
};
 
struct Queue {
    MyStack left_stack;
    MyStack right_stack;
 
public:
    void push(int element) {
        left_stack.push(element);
    }
 
    int pop() {
        if (!right_stack.empty()) {
            return right_stack.pop();
        } else {
            while (!left_stack.empty()) {
                right_stack.push(left_stack.pop());
            }
            return right_stack.pop();
        }
    }
};
 
 
int main() {
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    Queue my_queue;
    int n, elem;
    char ch;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        if (ch == '+') {
            cin >> elem;
            my_queue.push(elem);
        } else if (ch == '-'){
            elem = my_queue.pop();
            cout << elem << '\n';
        }
    }
 
    return 0;
}