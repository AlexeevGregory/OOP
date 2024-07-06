#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <QFileDialog>


using namespace std;

struct Node {
    char name;
    vector<Node*> neighbors;
};

class Graph {
    vector<Node*> nodes;
public:
    Graph();
    vector<Node*> getNodes() const;
    int size() const;
    bool empty();

    void addNode(char);
    void addEdge(Node*, Node*);
    string selectFile();
    short InputFileValues(string);
};


#endif // GRAPH_H
