
/**
 * @FindPaths.cc
 * @Shourov Saha (shourov.saha85@myhunter.cuny.edu)
 * @Uses the Graph class to look for the shortest path from two verticies in an Adjacency List.
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


int pathfindDriver(int argc, char **argv) {

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
  /* OUTPUT
  1: 1 cost: 0.0
  2: 1 2 cost: 2.0
  3: 1 4 3 cost: 3.0
  4: 1 cost: 1.0
  5: 1 4 5 cost: 3.0
  6: 1 4 7 6 cost: 6.0
  7: 1 4 7 cost: 5.0
  */
  // String to int for from the main parameter
  int startVertex = stoi(argv[2]);
  // For the number of verticies
  for (int i = 1; i <= numVerticies; i++) {
    // Create a path and set its value using generatePath(startVertex, i)
    pair<vector<int>,double> path = graph.generatePath(startVertex, i);
    cout << i << ": ";
    // If path is empty and has no inputs in the vector<int> then cout as instructed by pdf
    if (path.first.size() == 0){
      cout << "not_connected" << endl;
    }
    else {
      // cout the contents of the vector<int> and the cost in the pair.
      for (int j = 0; j < path.first.size(); j++) {
        cout << path.first[j] << " ";
      }
      cout << "cost: " << path.second;
      // Stops an extra endl if at end of the output 
      if (i!= numVerticies) {
        cout << endl;
      }
    }
    
  }
  return 0;
}
int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<STARTING_VERTEX>" << endl;
		return 0;
    }
    cout << "HELLO!";
    pathfindDriver(argc, argv);

    return 0;
}
