#include <string>

using namespace std;

int main() {

  bool running = true;

  graph* graph = new graph();

  while (running) {

    cout << "What is your action? (ADD VERTEX, ADD EDGE, REMOVE VERTEX, REMOVE EDGE, FIND PATH, PRINT, or QUIT) ";
    string action;
    cin >> action;

    if (action == "ADD VERTEX" or action == "av") {

      cout << "What is the label? ";
      string label;
      cin >> label;

      cout << "Adding... ";
      graph->addVertex(label);
      cout << "Done";
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

      cout << "Adding... ";
      graph->addEdge(vertex1, vertex2, weight);
      cout << "Done";
    }
    else if (action == "REMOVE VERTEX" or action == "rv") {

      cout << "What is the label? ";
      string label;
      cin >> label;

      cout << "Removing... ";
      graph->removeVertex(label);
      cout << "Done";
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
      cout << "Done";
    }
    else if (action == "FIND PATH" or action == "fp") {

      cout << cout << "What is the first vertex? ";
      string vertex1;
      cin >> vertex1;

      cout << "What is the second vertex? ";
      string vertex2;
      cin >> vertex2;

      cout << "Finding path... ";
      graph->findPath(vertex1, vertex2);
      cout << "Done";
    }
    else if (action == "PRINT" or action == "p") {

      cout << "Printing... " << endl;
      graph->printAdjacencyTable();
      cout << "Done";
    }
    else { cout << endl << "Not an action" << endl; }

    action.clear();
  }

  return 0;
}
