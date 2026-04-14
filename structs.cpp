#ifndef STRUCTS_CPP
#define STRUCTS_CPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Edge;

struct Vertex {

  vector<Edge*> startEdges;
  vector<Edge*> endEdges;
  string label;
  int distance = NULL;

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

  bool unreachable(vertex<Vector*> i) {

    for (Vector* j : i) {

      if (j->distance != NULL) { return false; }
    }

    return true;
  }

  Vertex* getCurrent(vertex<Vector*> i) {

    Vertex* curr = i.at(0);
    for (Vertex* j : i) {

      if (j->distance < curr->distance) { curr = j; }
    }
    
    return curr;
  }

  int findPath(string label1, string label2) {

    Vertex* v1 = findVertex(label1);
    Vertex* v2 = findVertex(label2);
    if (v1 == nullptr or v2 == nullptr) { return; }

    //Make unvisited set
    vector<Vertex*> unvisited = this->vertices;
    
    for (Vertex* i : unvisited) {

      //Clear previous
      if (i == v1) { i->distance = 0; }
      else { i->distance = NULL; }
    }

    while (unvisted.size() != 0 and !unreachable(unvisited)) {

      Vertex* curr = getCurrent(unvisited);

      if (curr == v2) { return v2->distance; }
      
      //Edges starting at curr
      for (Edge* i : curr->startEdges) {

	if (curr->distance + i->weight < i->v2->distance) { i->v2->distance = curr->distance + i->weight; }
      }

      //Edges ending at curr
      for (Edge* i : curr->endEdges) {

	if (curr->distance + i->weight < i->v1->distance) { i->v1->distance = curr->distance + i->weight; }
      }

      unvisited.remove(curr);
    }

    return -1;
  }

  void printAdjacenyTable() {

    for (Vertex* i : this->vertices) {

      cout << "Vertex " << i->label << endl;

      for (Edge* j : i->startEdges) { cout << "Edge to " << j->vertex2->label << endl; }
      for (Edge* j : i->endEdges) { cout << "Edge from " << j->vertex1->label << endl; }

      cout << endl;
    }
  }
};

#endif
