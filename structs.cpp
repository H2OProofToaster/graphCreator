#ifndef STRUCTS_CPP
#define STRUCTS_CPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Vertex;

struct Edge {

  Vertex* vertex1;
  Vertex* vertex2;
  int weight;

  Edge(Vertex* v1, Vertex* v2, int w) : vertex1(v1), vertex2(v2), weight(w) {}
};

struct Vertex {

  vector<Edge*> startEdges;
  vector<Edge*> endEdges;
  string label;
  int distance = -1;

  Vertex(string l) : label(l) {}

  ~Vertex() {

    for (Edge* i : startEdges) { delete i; }
    for (Edge* i : endEdges) { delete i; }
  }
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

  void removeEdgeFromVertices(vector<Edge*> input, Edge* remove) {

    for (int i = 0; i < input.size(); i++) {

      if (input.at(i) == remove) { input.erase(input.begin() + i); }
    }
  }
  
  void removeEdge(string label1, string label2) {

    Vertex* v1 = findVertex(label1);
    Vertex* v2 = findVertex(label2);

    //Starting at v1
    for (Edge* i : v1->startEdges) {

      if (i->vertex2 == v2) {

	removeEdgeFromVertices(v1->startEdges, i);
	removeEdgeFromVertices(v2->endEdges, i);
      }

      delete i;
    }

    //Starting at v2
    for (Edge* i : v2->startEdges) {

      if (i->vertex2 == v1) {

	removeEdgeFromVertices(v2->startEdges, i);
	removeEdgeFromVertices(v1->endEdges, i);
      }

      delete i;
    }
  }

  bool unreachable(vector<Vertex*> input) {

    for (Vertex* j : input) {

      if (j->distance != -1) { return false; }
    }

    return true;
  }

  Vertex* getCurrent(vector<Vertex*> input) {

    Vertex* curr = input.at(0);
    for (Vertex* j : input) {

      if (j->distance < curr->distance) { curr = j; }
    }
    
    return curr;
  }

  int findPath(string label1, string label2) {

    Vertex* v1 = findVertex(label1);
    Vertex* v2 = findVertex(label2);
    if (v1 == nullptr or v2 == nullptr) { return -1; }

    //Make unvisited set
    vector<Vertex*> unvisited = this->vertices;
    
    for (Vertex* i : unvisited) {

      //Clear previous
      if (i == v1) { i->distance = 0; }
      else { i->distance = -1; }
    }

    while (unvisited.size() != 0 and !unreachable(unvisited)) {

      Vertex* curr = getCurrent(unvisited);

      if (curr == v2) { return v2->distance; }
      
      //Edges starting at curr
      for (Edge* i : curr->startEdges) {

	if (curr->distance + i->weight < i->vertex2->distance) { i->vertex2->distance = curr->distance + i->weight; }
      }

      //Edges ending at curr
      for (Edge* i : curr->endEdges) {

	if (curr->distance + i->weight < i->vertex1->distance) { i->vertex1->distance = curr->distance + i->weight; }
      }

      //Delete curr
      for (int i = 0; i < unvisited.size(); i++) {

	if (unvisited.at(i) == curr) { unvisited.erase(unvisited.begin() + i); }
      }
    }

    return -1;
  }

  void printAdjacencyTable() {

    for (Vertex* i : this->vertices) {

      cout << "Vertex " << i->label << endl;

      for (Edge* j : i->startEdges) { cout << "Edge to " << j->vertex2->label << " with weight " << j->weight << endl; }
      for (Edge* j : i->endEdges) { cout << "Edge from " << j->vertex1->label << " with weight " << j->weight << endl; }

      cout << endl;
    }
  }
};

#endif
