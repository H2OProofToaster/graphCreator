#ifndef STRUCTS_CPP
#define STRUCTS_CPP

#include <iostream>
#include <ostream>
#include <vector>
#include <string>

using namespace std;

struct Edge;

struct Vertex {

  vector<Edge*> startEdges;
  vector<Edge*> endEdges;
  string label;

  Vertex(string l) : label(l) {}

  ~Vertex() {

    for (Edge* i : startEdges) { delete i; }
    for (Edge* i : endEdges) { delete i; }
  }

};

struct Edge {

  Vertex* vertex1;
  Vertex* vertex2;
  int weight;

  Edge(Vertex* v1, Vertex* v2, int w) : vertex1(v1), vertex2(v2), weight(w) {}
};

struct Graph {

  vector<Vertex*> vertices;

  ~Graph() { for (Vertex* i : vertices) { delete i; } }

  Vertex* findVertex(string label) {

    for (Vertex* i : vertices) {
      if (i->label == label) { return i; }
    }

    return nullptr;
  }

  void addVertex(string label) { vertices.push_back(new Vertex(label)); }

  void addEdge(string label1, string label2, int weight) {

    Vertex* v1 = findVertex(label1);
    Vertex* v2 = findVertex(label2);

    if (v1 == nullptr or v2 == nullptr) { return; }

    v1->startEdges.push_back(new Edge(v1, v2, weight));
    v2->endEdges.push_back(v1->startEdges.back());
  }

  void removeVertex(string label) {

    for (Vertex* i : vertices) {

      if (i->label == label) { delete i; }
    }
  }

  void removeEdge(string label1, string label2) {

    Vertex* v1 = findVertex(label1);
    Vertex* v2 = findVertex(label2);

    for (Edge* i : v1->startEdges) {

      if (i->vertex2 == v2) { delete i; }
    }
  }

  void findPath(string label1, string label2) {

    Vertex* v1 = findVertex(label1);
    Vertex* v2 = findVertex(label2);

    //TODO: Dijkstra's Algorithm
  }

  void printAdjacenyTable() {

    for (Vertex* i : vertices) {

      cout << "Vertex " << i->label << endl;

      for (Edge* j : i->startEdges) { cout << "Edge to " << j->vertex2->label << endl; }
      for (Edge* j : i->endEdges) { cout << "Edge from " << j->vertex1->label << endl; }

      cout << endl;
    }
  }
};

#endif