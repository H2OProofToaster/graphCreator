#ifndef STRUCTS_CPP
#define STRUCTS_CPP

#include <limits>
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

  string label;
  int distance = -1;
  Vertex* from = nullptr;

  Vertex(string l) : label(l) {}
};

struct Graph {

  vector<Vertex*> vertices;
  vector<Edge*> edges;

  ~Graph() { for (Vertex* i : vertices) { delete i; } }

  template <typename T>
  T* findVertexFromLabel(vector<T*> vertices, string label) {

    for (T* i : vertices) {
      if (i->label == label) { return i; }
    }

    return nullptr;
  }

  template <typename T>
  T* removeFromVector(vector<T*> &v, T* r) {

    for (int i = 0; i < v.size(); i++) {

      if (v.at(i) == r) {

	T* toReturn = v.at(i);
	v.erase(v.begin() + i);
	return toReturn;
      }
    }

    return nullptr;
  }

  void addVertex(string label) { vertices.push_back(new Vertex(label)); }

  void addEdge(string label1, string label2, int weight) {

    Vertex* v1 = this->findVertexFromLabel(this->vertices, label1);
    Vertex* v2 = this->findVertexFromLabel(this->vertices, label2);

    if (v1 == nullptr or v2 == nullptr) { return; }

    this->edges.push_back(new Edge(v1, v2, weight));
  }

  void removeVertex(string label) {

    Vertex* v = this->removeFromVector(this->vertices, findVertexFromLabel(this->vertices, label));

    for (Edge* i : this->getEdges(v)) {

      if (i->vertex1 == v or i->vertex2 == v) {

	this->removeFromVector(edges, i);
	delete i;
      }
    }
  }
  
  void removeEdge(string label1, string label2) {

    Vertex* v1 = this->findVertexFromLabel(this->vertices, label1);
    Vertex* v2 = this->findVertexFromLabel(this->vertices, label2);

    for (Edge* i : this->edges) {

      if (i->vertex1 == v1 and i->vertex2 == v2) {

	this->removeFromVector(edges, i);
	delete i;
      }
    }
  }

  vector<Edge*> getEdges(Vertex* v) {

    vector<Edge*> returnEdges;

    for (Edge* i : this->edges) {

      if (i->vertex1 == v or i->vertex2 == v) { returnEdges.push_back(i); }
    }

    return returnEdges;
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

  void findPath(string label1, string label2) {

    Vertex* v1 = this->findVertexFromLabel(this->vertices, label1);
    Vertex* v2 = this->findVertexFromLabel(this->vertices, label2);
    if (v1 == nullptr or v2 == nullptr) { cout << "That vertex doesn't exist"; return; }
    if (v1 == v2) { cout << "Those vertices are the same"; return; }

    //Make unvisited set
    vector<Vertex*> unvisited = this->vertices;
    
    for (Vertex* i : unvisited) {

      //Clear previous
      if (i == v1) { i->distance = 0; }
      else { i->distance = numeric_limits<int>::max() / 2; }
    }

    while (unvisited.size() != 0 and !unreachable(unvisited)) {

      //Returns smallest distance unvisited vertex
      Vertex* curr = this->getCurrent(unvisited);

      if (curr == v2) {

	cout << v2->distance << " with path: ";
	
	while (curr->from != nullptr) {

	  cout << curr->from->label << " ";
	  curr = curr->from;
	}

	cout << endl;
	return;
      }

      for (Edge* i : this->getEdges(curr)) {

	Vertex* other = i->vertex1 == curr ? i->vertex2 : i->vertex1;
	
	if (other != v1 and
	    curr->distance + i->weight < other->distance) {

	  other->distance = curr->distance + i->weight;
	  other->from = curr;
	}
      }

      //Delete curr
      for (int i = 0; i < unvisited.size(); i++) {

	if (unvisited.at(i) == curr) { unvisited.erase(unvisited.begin() + i); }
      }
    }

    cout << "There is no path";
  }

  void printAdjacencyTable() {

    for (Vertex* i : this->vertices) {

      cout << "Vertex " << i->label << endl;

      for (Edge* j : this->getEdges(i)) {

	Vertex* other = j->vertex1 == i ? j->vertex2 : j->vertex1;
	
	cout << "Edge to " << other->label;
	cout << " with weight " << j->weight << endl;
      }

      cout << endl;
    }
  }
};

#endif
