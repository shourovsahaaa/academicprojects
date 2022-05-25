[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7856698&assignment_repo_type=AssignmentRepo)
# Assignment 5

Adjacency Lists
Creates an Adjacency List using a formatted text file.
The first line is the number of vertices. Each vertex is represented by an integer from 1 to N. Each line is of the form:
<vertex> <connected vertex 1> <weight 1> <connected vertex 2> <weight 2> ...

The Graph class has the following functions:
  Default constructor: Graph();
  Insert: void insert(int vertexNum, vector<pair<int,double>> vectorAdjNum_Weights);
  Checks Adjacency: double isConnected(int vertex1, int vertex2);
  Implementation of Dijkstra’s Algorithm function: pair<vector<int>,double> generatePath(int startVertex, int endVertex);

The Graph class uses a map<int,vector<pair<int,double>>> graph_ to store its data.
  

Instructions on how to compile the code are listed below.

## To Compile

The command:

```bash
make
```

will produce the executable files `CreateGraphAndTest` and `FindPaths`.
