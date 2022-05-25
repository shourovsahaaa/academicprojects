/**
 * @graph.h
 * @Shourov Saha (shourov.saha85@myhunter.cuny.edu)
 * @Header file for the Graph class that implements Adjaceny list and implements Dijkstra’s Algorithm.
 * @version 0.1
 * @05-24-2022
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;

class Graph {
  public:
    // Default constructor
    Graph() {
    }
    // Insert using the vertex number and the vector of pairs of node nuber and weight
    void insert(int vertexNum, vector<pair<int,double>> vectorAdjNum_Weights) {
      graph_.insert(make_pair(vertexNum,vectorAdjNum_Weights));
    }
    // formatted print of the graph.
    void printGraph() {
      cout << graph_.size() << endl;
      for (auto &element:graph_) {
        cout << element.first;
        for (auto &pair:element.second) {
          cout << " " << pair.first << " " << pair.second;
        }
        cout << endl;
      }
    }
    // Returns the weight if the parameterized verticies are connected else returns -1;
    double isConnected(int vertex1, int vertex2) {
      // for all elements in the map
      for (auto &element:graph_) {
        //if the element is the vertex1
        if (element.first == vertex1) {
          //check its adjacent verticies for vertex2
          for (auto &pair:element.second) {
            if (pair.first == vertex2) {
              return pair.second;
            }
          }
        }
      }
      return -1;
    }
    // Recursively looks for the best path, vector<int>, and costs
    // BROKEN
    pair<vector<int>,double> generatePath(int startVertex, int endVertex) {
      vector<vector<int>> vectInt;
      vector<int> Ints;
      double costs = 0.0;
      map<int,vector<pair<int,double>>> graph = graph_;
      pair<vector<int>,double> path;
      vector<pair<vector<int>,double>> Answer;
      if (startVertex == endVertex) {
        Ints.push_back(startVertex); 
        path = make_pair(Ints,costs);
        Answer.push_back(path);
      }
      else if (this->isConnected(startVertex,endVertex) > 0) {
        Ints.push_back(startVertex);
        Ints.push_back(endVertex);
        costs += this->isConnected(startVertex,endVertex);
        path = make_pair(Ints,costs);
        Answer.push_back(path);
        Ints.clear();
        costs = 0.0;
      }
      for (auto &element:graph) {
        if (this->isConnected(startVertex, element.first) > 0 && this->isConnected(element.first, endVertex) > 0) {
          pair<vector<int>,double> path1 = this->generatePath(startVertex, element.first);
          pair<vector<int>,double> path2 = this->generatePath(element.first, endVertex);
          for (int i = 0; i < path1.first.size(); i++) {
            Ints.push_back(path1.first[i]);
          }
          for (int i = 0; i < path2.first.size(); i++) {
            Ints.push_back(path2.first[i]);
          }
          costs += path1.second + path2.second;
          path = make_pair(Ints,costs);
          Answer.push_back(path);
          Ints.clear();
          costs = 0.0;
        }
      }
      double lowestCost = 999;
      int index;
      for (int i = Answer.size()-1; i > 0; i--) {
        if (lowestCost > Answer[i-1].second) {
          lowestCost = Answer[i-1].second;
          index = i-1;
        }
      }
      
      return Answer[index];
    }
  private:
    // map holding all the vertex numbers as integers and the adjacent verticies and weights as a pair<int,double>
    map<int,vector<pair<int,double>>> graph_;
    
};

#endif