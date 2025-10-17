#include <iostream>
#include "LinkedListStack.hpp"
#include "ArrayStack.hpp"
using namespace std;

int main() {
    cout << "=== Testing LinkedList ===\n";
    LinkedListStack<int> ls;
    ls.push(1);
    ls.push(2);
    ls.push(3); 
    cout << "peek: " << ls.peek() << " size: " << ls.getLength() << "\n";

    ls.rotate(Stack<int>::RIGHT); // 3 goes to bottom: top becomes 2
    cout << "after RIGHT rotate, peek: " << ls.peek() << "\n";

    ls.rotate(Stack<int>::LEFT);  // bottom to top: back to 3
    cout << "after LEFT rotate, peek: " << ls.peek() << "\n";

    ls.pop(); // remove 3
    cout << "after pop, peek: " << ls.peek() << " size: " << ls.getLength() << "\n";

    cout << "\n=== Testing ArrayStack ===\n";
    ArrayStack<int> as(5);
    as.push(10);
    as.push(20); 
    as.push(30);
    cout << "peek: " << as.peek() << " size: " << as.getLength() << "\n";

    as.rotate(Stack<int>::RIGHT);
    cout << "after RIGHT rotate, peek: " << as.peek() << "\n";
    
    as.print();
    cout << "\n";
}