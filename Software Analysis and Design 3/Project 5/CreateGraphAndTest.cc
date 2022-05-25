/**
 * @CreateGraphAndTest.cc
 * @Shourov Saha (shourov.saha85@myhunter.cuny.edu)
 * @Uses formatted text files to read into Graph class and checks adjacency queries.
 * @version 0.1
 * @05-24-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "graph.h"

using namespace std;

int graphTestDriver(int argc, char **argv) {
  ifstream GRAPH_FILE;
  string line;
  int numVerticies;
  int vertexNum;
  int adjVertex;
  Graph graph;
  vector<pair<int,double>> vectorAdjNum_Weights;
  double weight;
  // Opens file
  GRAPH_FILE.open(argv[1], ifstream::in);
  // If not open, return 0
  if (!GRAPH_FILE.is_open()){
    cout << "<GRAPH_FILE> could not be found.";
    return 0;
  }
  else { 
    // If open,
    // Get line from the file
    getline(GRAPH_FILE, line);
    // create a stringstream
    stringstream lineStream(line);
    // input the number of verticies
    lineStream >> numVerticies;
    // read adjacent node numbers and weights 
    for (int i = 1; i <= numVerticies; i++) {
      getline(GRAPH_FILE, line);
      stringstream lineStream(line);
      lineStream >> vertexNum;
      // while it gets input, keep pushing back into the vector vectorAdjNum_Weights
      while (lineStream >> adjVertex >> weight) {
        vectorAdjNum_Weights.push_back(make_pair(adjVertex, weight));
      }
      graph.insert(vertexNum, vectorAdjNum_Weights);
      vectorAdjNum_Weights.clear();
    }
  }
  
  ifstream ADJACENCY_QUERYFILE;
  int vertex1, vertex2;
  double connectionWeight;
  // Opens Adjacency queryfile
  ADJACENCY_QUERYFILE.open(argv[2], ifstream::in);
  // If not open cout message and return 0
  if (!ADJACENCY_QUERYFILE.is_open()){
    cout << "<ADJACENCY_QUERYFILE> could not be found.";
    return 0;
  }
  else {
    // if open,
    // getline from file
    while (getline(ADJACENCY_QUERYFILE, line)) {
      stringstream lineStream(line);
      // use a string stream to read inputs
      lineStream >> vertex1 >> vertex2;
      // Format the file according to the instructions
      cout << vertex1 << " " << vertex2 << ": ";
      // use the isConnected function to find weight
      connectionWeight = graph.isConnected(vertex1, vertex2);
      // if weight is not -1, cout << connected
      if (connectionWeight != -1) {
        cout << "connected " << connectionWeight << endl;
      }
      else {
        cout << "not_connected" << endl;
      }
    }
  }
  return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<ADJACENCY_QUERYFILE>" << endl;
		return 0;
    }

    graphTestDriver(argc, argv);

    return 0;
}