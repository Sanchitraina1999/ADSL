//============================================================================
// Name        : 04Graph.cpp
// Author      : Sanchit Raina
// Version     :
// Copyright   : https://www.github.com/Sanchitraina1999/ADSL
// Description : Hello World in C++, Ansi-style
//============================================================================

/*

 	There are flight paths between cities. If there is a flight between city
	A and city B then there is an edge between the cities. The cost of the
	edge can be the time that flight takes to reach city B from A, or the
	amount of fuel used for the journey. Represent this as a graph. The
	node can be represented by airport name or name of the city. Use
	adjacency list representation of the graph. (Operation to be
	performed adding and deleting edge, adding and deleting vertices,
	calculated in-degree and out-degree for directed graph. Use any
	traversal to traverse graph)

 */

#include <iostream>
#include <vector>
#define total 10
using namespace std;

class node{
public:
	string cityname;
	friend class graph;
};

class graph:public node{
	int cities;
	vector<string> city;
	int money;
	cost[10][10];
public:
	graph(){
		cost[10][10]={0};
	}
	void accept();
	void costForRoutes();
};

void graph::accept(){
	cout<<"Enter the number of cities in the country\n";
	cin>>cities;
	while(cities--){
		cout<<"Enter the name of city "<<total-cities+1<<endl;
		cin>>cityname;
		city.push_back(cityname);
	}
}

void graph::costForRoutes(){
	for(int i=0;i<total;i++){
		for(int j=i;j<total;j++){
			cout<<"Enter the cost of the ticket from city "<<city[i]<<" to "<<city[j]<<"\n";
			cin>>money;
			cost[i][j]=money;
			cost[j][i]=money;
		}
	}
}

int main() {
	cout<<"Country FLIGHT MECHANISM\n";



	return 0;
}
