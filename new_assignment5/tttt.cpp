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

void bfs(Node *start)
{
   // TODO, make sure that your implementation is based on queue
   set<Node *> visited;
   queue<Node *> queue;
   queue.push(start);
   visited.insert(start);
   while (!queue.empty()) {
      Node *N = queue.front();
      queue.pop();
      cout << N->name << endl;
      for (auto iter = N->arcs.begin(); iter != N->arcs.end(); ++iter)
      {
         Node *next = (*iter)->finish;
         if (visited.find(next) == visited.end()) {
            queue.push(next);
            visited.insert(next);
         }
      }
   }
}

void dfs(Node *start) {
   // TODO, make sure that your implementation is based on stack
   set<Node *> visited;
   stack<Node *> stack;
   stack.push(start);
   visited.insert(start);
   while (!stack.empty()) {
      Node *N = stack.top();
      stack.pop();
      cout << N->name << endl;
      for (auto iter = N->arcs.begin(); iter != N->arcs.end(); ++iter) {
         Node *next = (*iter)->finish;
         if (visited.find(next) == visited.end()) {
            stack.push(next);
            visited.insert(next);
         }
      }
   }
}

int main()
{
   SimpleGraph airline;
   readGraph(airline, cin);
   cout << "DFS at Portland ...." << endl;
   dfs(airline.nodeMap.at("Portland"));
   cout << "BFS at Portland ...." << endl;
   bfs(airline.nodeMap.at("Portland"));
   return 0;
}
