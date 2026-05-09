// Graph.h — CSC 249 Graph Class
// Edge weights are strings for maximum flexibility:
//   "6743 miles"  for distances
//   "north"       for directions
//   "married to"  for relationships
//
// Usage:
//   #include "Graph.h"
//   Graph g;
//   Vertex* a = g.AddVertex("Kitchen");
//   Vertex* b = g.AddVertex("Hallway");
//   g.AddDirectedEdge(a, b, "north");
//   g.AddDirectedEdge(b, a, "south");

#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>

class Vertex {
public:
    std::string label;

    Vertex(const std::string& vertexLabel) {
        label = vertexLabel;
    }
};

class Edge {
public:
    Vertex* fromVertex;
    Vertex* toVertex;
    std::string weight;

    Edge(Vertex* from, Vertex* to, std::string edgeWeight) {
        fromVertex = from;
        toVertex = to;
        weight = edgeWeight;
    }
};

class Graph {
private:
    // Maps a vertex to a list of all edges that START from that vertex
    std::unordered_map<Vertex*, std::vector<Edge*>*> fromEdges;

    // Maps a vertex to a list of all edges that GO TO that vertex
    std::unordered_map<Vertex*, std::vector<Edge*>*> toEdges;

public:
    virtual ~Graph() {
        std::unordered_set<Vertex*> distinctVertices;
        std::unordered_set<Edge*> distinctEdges;
        for (auto& kv : fromEdges) {
            distinctVertices.insert(kv.first);
            for (Edge* edge : *kv.second) {
                distinctEdges.insert(edge);
            }
        }
        for (auto& kv : toEdges) {
            distinctVertices.insert(kv.first);
            for (Edge* edge : *kv.second) {
                distinctEdges.insert(edge);
            }
        }
        fromEdges.clear();
        toEdges.clear();
        for (Edge* edge : distinctEdges) delete edge;
        for (Vertex* vertex : distinctVertices) delete vertex;
    }

    // Add a new vertex with the given label. Returns a pointer to it.
    Vertex* AddVertex(const std::string& newVertexLabel) {
        Vertex* newVertex = new Vertex(newVertexLabel);
        fromEdges[newVertex] = new std::vector<Edge*>();
        toEdges[newVertex] = new std::vector<Edge*>();
        return newVertex;
    }

    // Add a one-way edge from fromVertex to toVertex with the given label.
    Edge* AddDirectedEdge(Vertex* fromVertex, Vertex* toVertex,
                          std::string weight = "->") {
        if (HasEdge(fromVertex, toVertex)) return nullptr;
        Edge* newEdge = new Edge(fromVertex, toVertex, weight);
        fromEdges[fromVertex]->push_back(newEdge);
        toEdges[toVertex]->push_back(newEdge);
        return newEdge;
    }

    // Add a two-way edge (creates two directed edges).
    std::pair<Edge*, Edge*> AddUndirectedEdge(
        Vertex* vertexA, Vertex* vertexB, std::string weight = "->") {
        return std::pair<Edge*, Edge*>(
            AddDirectedEdge(vertexA, vertexB, weight),
            AddDirectedEdge(vertexB, vertexA, weight));
    }

    // Get all edges in the graph.
    std::unordered_set<Edge*> GetEdges() const {
        std::unordered_set<Edge*> edgesSet;
        for (auto& kv : fromEdges) {
            for (Edge* edge : *kv.second) {
                edgesSet.insert(edge);
            }
        }
        return edgesSet;
    }

    // Get all edges leaving from a vertex.
    const std::vector<Edge*>* GetEdgesFrom(Vertex* fromVertex) const {
        return fromEdges.at(fromVertex);
    }

    // Get all edges arriving at a vertex.
    const std::vector<Edge*>* GetEdgesTo(Vertex* toVertex) const {
        return toEdges.at(toVertex);
    }

    // Find a vertex by its label string. Returns nullptr if not found.
    Vertex* GetVertex(const std::string& vertexLabel) {
        for (auto& kv : fromEdges) {
            if (kv.first->label == vertexLabel) {
                return kv.first;
            }
        }
        return nullptr;
    }

    // Get all vertices in the graph.
    std::vector<Vertex*> GetVertices() const {
        std::vector<Vertex*> vertices;
        for (auto& kv : fromEdges) {
            vertices.push_back(kv.first);
        }
        return vertices;
    }

    // Check if a directed edge exists from fromVertex to toVertex.
    bool HasEdge(Vertex* fromVertex, Vertex* toVertex) const {
        if (0 == fromEdges.count(fromVertex)) return false;
        for (Edge* edge : *fromEdges.at(fromVertex)) {
            if (edge->toVertex == toVertex) return true;
        }
        return false;
    }
};

#endif // GRAPH_H
