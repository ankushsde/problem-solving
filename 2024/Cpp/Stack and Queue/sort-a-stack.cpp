#include <iostream>
#include <stack>

void sortStack(std::stack<int>& inputStack) {
    std::stack<int> tempStack; // Create a temporary stack to hold sorted elements

    while (!inputStack.empty()) { // Loop until the input stack becomes empty
        int temp = inputStack.top(); // Store the top element of the input stack
        inputStack.pop(); // Remove the top element from the input stack

        // Move elements from tempStack to inputStack if they are greater than temp
        while (!tempStack.empty() && tempStack.top() < temp) {
            inputStack.push(tempStack.top()); // Move the top element of tempStack to inputStack
            tempStack.pop(); // Remove the top element from tempStack
        }

        tempStack.push(temp); // Push temp to tempStack
    }

    // Move elements from tempStack back to inputStack (in descending order)
    while (!tempStack.empty()) {
        inputStack.push(tempStack.top()); // Push the top element of tempStack to inputStack
        tempStack.pop(); // Remove the top element from tempStack
    }
}

int main() {
    std::stack<int> s;

    // Input elements into stack
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    // Sort the stack in descending order
    sortStack(s);

    // Output the sorted stack
    while (!s.empty()) {
        std::cout << s.top() << " "; // Print the top element of the stack
        s.pop(); // Remove the top element from the stack
    }
    std::cout << std::endl;

    return 0;
}
