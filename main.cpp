#include "structs.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

  bool running = true;

  Graph* graph = new Graph();

  while (running) {

    cout << "What is your action? (ADD VERTEX, ADD EDGE, REMOVE VERTEX, REMOVE EDGE, SETUP, FIND PATH, PRINT, or QUIT) " << endl;
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
    else if (action == "SETUP" or action == "s") {

      cout << "Setting up..." << endl;

      //Setup vertices
      graph->addVertex("v1");
      graph->addVertex("v2");
      graph->addVertex("v3");
      graph->addVertex("v4");
      graph->addVertex("v5");
      graph->addVertex("v6");
      graph->addVertex("v7");

      //Setup edges
      graph->addEdge("v1", "v2", 3);
      graph->addEdge("v1", "v3", 3);
      graph->addEdge("v1", "v4", 2);
      graph->addEdge("v1", "v6", 5);
      graph->addEdge("v2", "v5", 2);
      graph->addEdge("v3", "v5", 6);
      graph->addEdge("v4", "v6", 4);
      graph->addEdge("v5", "v7", 8);
      graph->addEdge("v6", "v7", 9);
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
