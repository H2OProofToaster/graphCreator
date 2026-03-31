#ifndef STRUCTS_CPP
#define STRUCTS_CPP

#include <iostream>
#include <vector>

using namespace std;

struct Vertex {

  vector<Edge*> edges;
  string label;

  Vertex(string l) : label(l) {}

  ~Vertex() { for (Edge* i : edges) { delete i; } }

};

struct Edge {

  Vertex* vertex1;
  Vertex* vertex2;
  int weight;

  Edge(Vertex* v1, Verte* v2, int w) : vertex1(v1), vertex2(v2), weight(w) {}
};

struct Graph {

  vector<Vertex*> vertices;

  ~Graph() { for (Vertex* i : vertices) { delete i; } }

  Vertex* findVertex(string label) {

    for (Vertex* i : vertices) {
      if (i->label == label) { return i; }
    }
  }

  void addVertex(string label) {

    
  }
};
