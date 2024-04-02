#include <iostream>
#include "csc300222fall/assignment4/buffer.h"
#include "csc300222fall/assignment4/SimpleTextEditor.h"
using namespace std;

/*
 * Implementation notes: EditorBuffer constructor
 * ----------------------------------------------
 * This function initializes an empty editor buffer, represented
 * as a doubly linked list.  In this implementation, the ends of
 * the linked list are joined to form a ring, with the dummy cell
 * at both the beginning and the end.  This representation makes
 * it possible to implement the moveCursorToEnd method in constant
 * time, and reduces the number of special cases in the code.
 */

EditorBuffer::EditorBuffer() {
   start = cursor = new Cell;
   start->next = start;
   start->prev = start;
}

/* TODO PART:
 * Implementation notes: EditorBuffer destructor
 * ---------------------------------------------
 * The destructor must delete every cell in the buffer.  Note
 * that the loop structure is not exactly the standard idiom for
 * processing every cell within a linked list, because it is not
 * legal to delete a cell and later look at its next field.
 */

EditorBuffer::~EditorBuffer() {
   // TODO
   Cell *cp = start->next;
   while (cp != start) {
      Cell *next = cp->next;
      delete cp;
      cp = next;
   }
   delete cp;
}

/* TODO PART:
 * Implementation notes: cursor movement
 * -------------------------------------
 * In a doubly linked list, each of these operations runs in
 * constant time.
 */

void EditorBuffer::moveCursorForward() {
   if (cursor->next != start) {
      cursor = cursor->next;
   }
}

void EditorBuffer::moveCursorBackward() {
   // TODO
   if (cursor != start) {
      cursor = cursor->prev;
   }

}

void EditorBuffer::moveCursorToStart() {
   // TODO
   cursor = start;
}

void EditorBuffer::moveCursorToEnd() {
   // TODO
   while (cursor->next != start) {
      cursor = cursor->next;
   }
}

/* TODO PART:
 * Implementation notes: insertCharacter, deleteCharacter
 * ------------------------------------------------------
 * This code is much like that used for the traditional linked
 * list except that more pointers need to be updated.
 */

void EditorBuffer::insertCharacter(char ch) {
   // TODO
   Cell *cp = new Cell;
   cp->ch = ch;
   cursor->next->prev = cp;
   cp->next = cursor->next;
   cp->prev = cursor;
   cursor->next = cp;
   cursor = cp;


}

void EditorBuffer::deleteCharacter() {
   // TODO
   if (cursor != start) {
      cursor->next->prev = cursor->prev;
      cursor->prev->next = cursor->next;
      Cell *oldCell = cursor;
      cursor = cursor->prev;
      delete oldCell;
   }
}

/* TODO PART:
 * Implementation notes: getText and getCursor
 * -------------------------------------------
 * The getText method uses the standard linked-list pattern to loop
 * through the cells in the linked list.  The getCursor method counts
 * the characters in the list until it reaches the cursor.
 */

string EditorBuffer::getText() const {
   // TODO
   string str = "";
   for (Cell *cp = start->next; cp != start; cp = cp->next) {
      str += cp->ch;
   }
   return str;
}

int EditorBuffer::getCursor() const {
   // TODO
   int nChars = 0;
   for (Cell *cp = start; cp != cursor; cp = cp->next) {
      nChars ++;
   }
   return nChars;
}

/* DO NOT modify the main() part */
int main(){
    string cmd;
    EditorBuffer buffer;
    while(getline(cin,cmd)){
        executeCommand(buffer, cmd);
    }        
    return 0;
}