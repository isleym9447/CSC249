#include <iostream>
#include "Graph.h"

using namespace std;

void PrintGraph(Graph& graph, string graphName) {
    cout << endl;
    cout << "=== " << graphName << " ===" << endl << endl;

    for (Vertex* location : graph.GetVertices()) {
        cout << "Location: " << location->label << endl;

        cout << "  Outgoing Routes:" << endl;
        for (Edge* route : *graph.GetEdgesFrom(location)) {
            cout << "    -> " << route->toVertex->label
                 << " (" << route->weight << ")" << endl;
        }

        cout << "  Incoming Routes:" << endl;
        for (Edge* route : *graph.GetEdgesTo(location)) {
            cout << "    <- " << route->fromVertex->label
                 << " (" << route->weight << ")" << endl;
        }

        cout << endl;
    }
}

void RunQueries(Graph& graph, Vertex* vertexA, Vertex* vertexB, string searchLabel) {
    cout << "=== QUERY 1: NEIGHBOR COUNT ===" << endl;
    for (Vertex* location : graph.GetVertices()) {
        cout << location->label << " has "
             << graph.GetEdgesFrom(location)->size()
             << " outgoing connection(s)" << endl;
    }

    cout << endl;

    cout << "=== QUERY 2: CONNECTION CHECK ===" << endl;
    cout << "Direct route from " << vertexA->label
         << " to " << vertexB->label << "? "
         << (graph.HasEdge(vertexA, vertexB) ? "Yes" : "No")
         << endl;

    cout << endl;

    cout << "=== QUERY 3: FIND BY LABEL ===" << endl;
    Vertex* found = graph.GetVertex(searchLabel);

    if (found) {
        cout << "Found location: " << found->label << endl;
    } else {
        cout << "Location not found!" << endl;
    }

    cout << endl;

    cout << "=== QUERY 4: EDGE SUMMARY ===" << endl;
    cout << "Total locations: " << graph.GetVertices().size() << endl;
    cout << "Total routes: " << graph.GetEdges().size() << endl;
}

void CyberpunkGraph() {
    Graph nightCity;

    Vertex* afterlife = nightCity.AddVertex("Afterlife");
    Vertex* lizzies = nightCity.AddVertex("Lizzie's Bar");
    Vertex* viktor = nightCity.AddVertex("Viktor's Clinic");
    Vertex* h10 = nightCity.AddVertex("Megabuilding H10");
    Vertex* arasaka = nightCity.AddVertex("Arasaka Tower");
    Vertex* kabuki = nightCity.AddVertex("Kabuki Market");

    nightCity.AddDirectedEdge(afterlife, lizzies, "fast travel");
    nightCity.AddDirectedEdge(lizzies, viktor, "drive through Watson");
    nightCity.AddDirectedEdge(viktor, h10, "walk home");
    nightCity.AddDirectedEdge(h10, arasaka, "main mission route");
    nightCity.AddDirectedEdge(arasaka, afterlife, "escape route");
    nightCity.AddDirectedEdge(kabuki, viktor, "shopping run");
    nightCity.AddDirectedEdge(afterlife, kabuki, "night market trip");

    PrintGraph(nightCity, "CYBERPUNK 2077: NIGHT CITY GRAPH");
    RunQueries(nightCity, afterlife, lizzies, "Viktor's Clinic");
}

void BaldursGateGraph() {
    Graph bg3;

    Vertex* emeraldGrove = bg3.AddVertex("Emerald Grove");
    Vertex* camp = bg3.AddVertex("Camp");
    Vertex* goblinCamp = bg3.AddVertex("Goblin Camp");
    Vertex* underdark = bg3.AddVertex("The Underdark");
    Vertex* mountainPass = bg3.AddVertex("Mountain Pass");
    Vertex* baldursGate = bg3.AddVertex("Baldur's Gate City");

    bg3.AddDirectedEdge(emeraldGrove, camp, "return to camp");
    bg3.AddDirectedEdge(camp, goblinCamp, "dangerous approach");
    bg3.AddDirectedEdge(goblinCamp, underdark, "hidden passage");
    bg3.AddDirectedEdge(underdark, mountainPass, "dark route");
    bg3.AddDirectedEdge(mountainPass, baldursGate, "road to the city");
    bg3.AddDirectedEdge(baldursGate, camp, "long rest return");
    bg3.AddDirectedEdge(camp, emeraldGrove, "help the tieflings");

    PrintGraph(bg3, "BALDUR'S GATE 3: LOCATION GRAPH");
    RunQueries(bg3, camp, goblinCamp, "The Underdark");
}

int main() {
    int choice;

    cout << "Choose a graph to view:" << endl;
    cout << "1. Cyberpunk 2077: Night City Graph" << endl;
    cout << "2. Baldur's Gate 3: Location Graph" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        CyberpunkGraph();
    } else if (choice == 2) {
        BaldursGateGraph();
    } else {
        cout << "Invalid choice. Please run the program again and enter 1 or 2." << endl;
    }

    return 0;
}