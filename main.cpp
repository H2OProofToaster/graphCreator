#include "structs.cpp"
#include <string>
#include <iostream>

using namespace std;

int main() {

  bool running = true;

  Graph* graph = new Graph();

  while (running) {

    cout << "What is your action? (ADD VERTEX, ADD EDGE, REMOVE VERTEX, REMOVE EDGE, FIND PATH, PRINT, or QUIT) " << endl;
    string action;
    cin >> action;

    if (action == "ADD VERTEX" or action == "av") {

      cout << "What is the label? ";
      string label;
      cin >> label;

      cout << "Adding... " << endl;
      graph->addVertex(label);
      cout << "Done" << endl;
    }
    else if (action == "ADD EDGE" or action == "ae") {

      cout << "What is the first vertex? ";
      string vertex1;
      cin >> vertex1;

      cout << "What is the second vertex? ";
      string vertex2;
      cin >> vertex2;

      cout << "What is the weight? ";
      int weight;
      cin >> weight;

      cout << "Adding... " << endl;
      graph->addEdge(vertex1, vertex2, weight);
      cout << "Done" << endl;
    }
    else if (action == "REMOVE VERTEX" or action == "rv") {

      cout << "What is the label? ";
      string label;
      cin >> label;

      cout << "Removing... " << endl;
      graph->removeVertex(label);
      cout << "Done" << endl;
    }
    else if (action == "REMOVE EDGE" or action == "re") {

      cout << "What is the first vertex? ";
      string vertex1;
      cin >> vertex1;

      cout << "What is the second vertex? ";
      string vertex2;
      cin >> vertex2;

      cout << "Removing... ";
      graph->removeEdge(vertex1, vertex2);
      cout << "Done" << endl;
    }
    else if (action == "FIND PATH" or action == "fp") {

      cout << "What is the first vertex? ";
      string vertex1;
      cin >> vertex1;

      cout << "What is the second vertex? ";
      string vertex2;
      cin >> vertex2;

      cout << "Finding path... " << endl;
      graph->findPath(vertex1, vertex2);
      cout << "Done" << endl;
    }
    else if (action == "PRINT" or action == "p") {

      cout << "Printing... " << endl;
      graph->printAdjacencyTable();
      cout << "Done" << endl;
    }
    else if (action == "QUIT" or action == "q") {

      delete graph;
      running = false;
    }
    else { cout << endl << "Not an action" << endl; }

    action.clear();
  }

  return 0;
}
