/*
 * File: Traverse.cpp
 * ------------------
 * This program reimplements the breadth-first search using an
 * explicit queue, and depth-first search algorithm using an explicit stack
 */

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include "csc300222fall/assignment5/simplegraph.h"
using namespace std;

void bfs(Node *start) {
   // TODO, make sure that your implementation is based on queue
   set<Node*> visited;
   queue<Node*> queue;
   queue.push(start);
   Node* npt;
   while (!queue.empty()) {
      npt = queue.front();
      queue.pop();
      if (visited.count(npt) == 0) {
         cout << npt->name << endl;
         visited.insert(npt);
         for (Arc* arc : npt->arcs) {
            queue.push(arc->finish);
         }
      }
   }
   
}

void dfs(Node *start) {
   // TODO, make sure that your implementation is based on stack
   set<Node*> visited;
   stack<Node*> stack;
   stack.push(start);
   Node* npt;
   while (!stack.empty()) {
      npt = stack.top();
      stack.pop();
      if (visited.count(npt) == 0) {
         cout << npt->name << endl;
         visited.insert(npt);
         for (Arc* arc : npt->arcs) {
            stack.push(arc->finish);
         }
      }
   }
}


int main(){
   SimpleGraph airline;
   readGraph(airline, cin);
   cout << "DFS at Portland ...." << endl;
   dfs(airline.nodeMap.at("Portland"));
   cout << "BFS at Portland ...." << endl;
   bfs(airline.nodeMap.at("Portland"));
   return 0;
}
