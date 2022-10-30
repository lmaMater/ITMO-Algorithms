#include <iostream>
#include <cstdio>
 
using namespace std;
 
struct MyStack {
    char *my_stack = NULL;
    int length = 0;
 
public:
    void push(char element) {
        char *temp_stack = new char[++length];
        memcpy(temp_stack, my_stack, (length - 1) * sizeof(char));
        temp_stack[length - 1] = element;
        delete[] my_stack;
        my_stack = temp_stack;
    }
 
    char pop() {
        char popped = my_stack[length - 1];
        char *temp_stack = new char[--length];
        memcpy(temp_stack, my_stack, length * sizeof(char));
        delete[] my_stack;
        my_stack = temp_stack;
        return popped;
    }
 
    bool empty() {
        return length == 0;
    }
 
    char getElem(int index) {
        if (index < length) {
            return my_stack[index];
        }
        return ' ';
    }
};
 
bool isPair(char ch1, char ch2) {
    return ch1 == '(' && ch2 == ')' || ch1 == '[' && ch2 == ']';
}
 
bool isCorrectBrackets(string s) {
    MyStack brackets;
    char current;
    for (int i = 0; i < s.size(); i++) {
        current = s[i];
 
        if (brackets.length == 0) {
            brackets.push(current);
        } else {
            char last = brackets.getElem(brackets.length - 1);
 
            if (isPair(last, current)) {
                brackets.pop();
            } else {
                brackets.push(current);
            }
        }
    }
 
    return brackets.empty();
}
 
int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    MyStack stack;
    string brackets;
 
    while (cin >> brackets) {
        if (isCorrectBrackets(brackets)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
 
    return 0;
}