
/* Q2:
 * File: ReverseQueue.cpp
 * ----------------------
 * This file tests the ReverseQueue function.
 */

#include <iostream>
#include "csc300222fall/assignment2/reversequeue.h"
#include <stack>
using namespace std;

/* TODO PART:
 * Function: reverseQueue
 * Usage: reverseQueue(queue);
 * ---------------------------
 * Reverses the order of the elements in a queue.  This
 * implementation does so by using a stack to hold the
 * values as they are being reversed.
 */

void reverseQueue(queue<string> & queue) {
    // TODO
    stack<string> stack_rev;
    int i;
    int size = queue.size();
    for (i = 0; i < size; i++) {
        stack_rev.push(queue.front());
        queue.pop();
    }
    for (i = 0; i < size; i++) {
        queue.push(stack_rev.top());
        stack_rev.pop();
    }

}

/* TODO PART:
 * Function: listQueue
 * Usage: listQueue(queue);
 * ------------------------
 * Lists the contents of the queue on the standard output stream.
 */

void listQueue(queue<string> & queue) {
   // TODO
   int size = queue.size();
    cout << "The queue contains:";
    for (int i=0; i < size; i++) {
        string item = queue.front();
        queue.pop();
        cout << " " << item;
        queue.push(item);
    }
    cout << endl;
}

/* DO NOT modify this main() part*/

int main() {
    string str;
    queue<string> line;

    while(cin>>str){
        line.push(str);
    }
    listQueue(line);
    reverseQueue(line);
    listQueue(line);
    return 0;
}
