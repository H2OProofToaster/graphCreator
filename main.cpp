#include "structs.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

  bool running = true;

  Graph* graph = new Graph();

  while (running) {

    cout << "What is your action? (addVertex, addEdge, removeVertex, removeEdge, setup, findPath, print, or quit) " << endl;
    string action;
    cin >> action;

    if (action == "addVertex" or action == "av") {

      cout << "What is the label? ";
      string label;
      cin >> label;

      cout << "Adding... ";
      graph->addVertex(label);
      cout << "Done" << endl;
    }
    else if (action == "addEdge" or action == "ae") {

      cout << "What is the first vertex? ";
      string vertex1;
      cin >> vertex1;

      cout << "What is the second vertex? ";
      string vertex2;
      cin >> vertex2;

      cout << "What is the weight? ";
      int weight;
      cin >> weight;

      cout << "Adding... ";
      graph->addEdge(vertex1, vertex2, weight);
      cout << "Done" << endl;
    }
    else if (action == "removeVertex" or action == "rv") {

      cout << "What is the label? ";
      string label;
      cin >> label;

      cout << "Removing... ";
      graph->removeVertex(label);
      cout << "Done" << endl;
    }
    else if (action == "removeEdge" or action == "re") {

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
    else if (action == "setup" or action == "s") {

      cout << "Setting up... ";

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

      cout << "Done" << endl;
      graph->printAdjacencyTable();
    }
    else if (action == "findPath" or action == "fp") {

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
    else if (action == "print" or action == "p") {

      cout << "Printing... " << endl;
      graph->printAdjacencyTable();
      cout << "Done" << endl;
    }
    else if (action == "quit" or action == "q") {

      delete graph;
      running = false;
    }
    else { cout << endl << "Not an action" << endl; }

    action.clear();
  }

  return 0;
}
