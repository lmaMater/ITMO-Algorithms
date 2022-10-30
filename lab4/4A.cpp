#include <iostream>
#include <cstdio>
 
using namespace std;
 
struct MyStack {
    int *my_stack = NULL;
    size_t length = 0;
public:
 
    void push(int element) {
        int* temp_stack = new int[++length];
        memcpy(temp_stack, my_stack, (length - 1) * sizeof(int));
        temp_stack[length - 1] = element;
        delete[] my_stack;
        my_stack = temp_stack;
    }
 
    void pop() {
        cout << my_stack[length - 1];
        int* temp_stack = new int[--length];
        memcpy(temp_stack, my_stack, length * sizeof(int));
        delete[] my_stack;
        my_stack = temp_stack;
    }
};
 
int main() {
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    MyStack stack;
    int n, num, out_counter = 0;
    char sign;
    cin >> n;
 
    for (int i = 0; i < n; i++) {
        cin >> sign;
        if (sign == '+') {
            cin >> num;
            stack.push(num);
        } else if (sign == '-') {
            if (out_counter != 0) {
                cout << '\n';
            }
            stack.pop();
            out_counter++;
        }
    }
 
    return 0;
}