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
 
int main() {
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    MyStack postfix;
    char ch;
 
    while (cin >> ch) {
        if (isdigit(ch)) {
            postfix.push(ch - '0');
        } else {
            int y = postfix.pop();
            int x = postfix.pop();
 
            if (ch == '+') {
                postfix.push(x + y);
            } else if (ch == '-') {
                postfix.push(x - y);
            } else if (ch == '*') {
                postfix.push(x * y);
            }
        }
    }
    cout << postfix.pop();
 
    return 0;
}