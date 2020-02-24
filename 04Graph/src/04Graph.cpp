//============================================================================
// Name        : 04Graph.cpp
// Author      : Sanchit Raina
// Version     :
// Copyright   : https://github.com/Sanchitraina1999/ADSL/blob/master/04Graph/src/04Graph.cpp
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
#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std;

class node{
	string city;
	node * next;
	int traveltime;

	public:
		node(){
			city = "";
			next = NULL;
			traveltime = -1;
		}

		node(string name,int weight){
			next = NULL;
			traveltime = weight;
			city = name;
		}
		friend class graph;
};

class graph{
	vector<node*> head;
	int noofnodes;
	int noofedges;

public:
	graph(int num){
		noofnodes = num;
	}

	void getcities();
	void addedgeundir();
	void addedgedir();
	void addvertice();
    	void deletevertice();
    	int outdegree();
    	int indegree();
    	void bfs();
};

void graph::getcities(){
	string cityname;
	for(int i=0;i<noofnodes;i++){
		cout<<"\n Enter name of city "<<i+1<<"\t";
		cin>>cityname;
		node * newnode = new node(cityname,-1);
		head.push_back(newnode);
	}
}

void graph::addedgedir(){                       //directed graph
	string source,destination;
	node * temp1=NULL , * temp2=NULL;
	int weight;

	cout<<"\n Enter Source";				    //get source
	cin>>source;

	int i;

	for(i=0;i<head.size();i++){
		temp1=head[i];
		if(temp1->city==source){
			break;
		}
	}
		if(i==head.size()){				        //validate source
			cout<<"\n INVALID SOURCE";
			return;
		}

	cout<<"\n Enter Destination";				//get destination
	cin>>destination;

	for(i=0;i!=head.size();i++){
		temp2=head[i];
		if(temp2->city==destination){
			break;
		}
	}
		if(i==head.size()){				        //validate destination
			cout<<"\n INVALID DESTINATION";
			return;
		}


	while(temp1->next!=NULL||temp1->city==destination){	//SOURCE----->DESTINATION
		if(temp1->city==destination){
			cout<<"\n FLIGHT BETWEEN "<<source<<" and "<<destination<<" ALREADY EXITS";
			return;
		}
		temp1=temp1->next;
	}
	cout<<"\n Enter travel time";
	cin>>weight;
	temp1->next = new node(destination,weight);
}

void graph::addedgeundir(){                     //undirected graph
	string source,destination;
	node * temp1=NULL , * temp2=NULL;
	int weight;

	cout<<"\n Enter Source";				    //get source
	cin>>source;

	int i;

	for(i=0;i<head.size();i++){
		temp1=head[i];
		if(temp1->city==source){
			break;
		}
	}
		if(i==head.size()){				        //validate source
			cout<<"\n INVALID SOURCE";
			return;
		}

	cout<<"\n Enter Destination";				//get destination
	cin>>destination;

	for(i=0;i!=head.size();i++){
		temp2=head[i];
		if(temp2->city==destination){
			break;
		}
	}
		if(i==head.size()){				        //validate destination
			cout<<"\n INVALID DESTINATION";
			return;
		}


	while(temp1->next!=NULL||temp1->city==destination){	//SOURCE----->DESTINATION
		if(temp1->city==destination){
			cout<<"\n FLIGHT BETWEEN "<<source<<" and "<<destination<<" ALREADY EXITS";
			return;
		}
		temp1=temp1->next;
	}
	cout<<"\n Enter travel time";
	cin>>weight;
	temp1->next = new node(destination,weight);

	while(temp2->next!=NULL)				    //DESTINATION----->SOURCE
		temp2=temp2->next;

	temp2->next = new node(source,weight);
	cout<<"\n FLIGHT ROUTE ENTERED SUCCESSFULLY";
	return;
}

void graph::addvertice(){                       //add vertex
	string newcity;
	cout<<"\n Enter city name";
	cin>>newcity;

	for(int i=0;i<head.size();i++){
		if(head[i]->city==newcity){
			cout<<"\n DUPLICATE ENTRY";
			return;
		}
	}

	node * newnode = new node(newcity,-1);
	head.push_back(newnode);
}

void graph::deletevertice(){                    //delete vertex
	string deletecity;
	cout<<"\n Enter city to be deleted";
	cin>>deletecity;
	int flag=0;

	vector<node*>::iterator i;
	node *temp;
	for(i=head.begin();i!=head.end();i++){
		temp=*i;
		if(temp->city==deletecity){
			head.erase(i);
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"\n INVALID CITY";
		return;
	}
	for(int i=0;i<head.size();i++){
		node *temp=head[i];

		while(temp->next!=NULL){
			if(temp->next->city==deletecity){
				node*temp1=temp->next;
				temp->next=temp->next->next;
				delete temp1;
				break;
			}
			temp=temp->next;
		}

	}
	noofnodes--;
	cout<<"\n DELETED SUCCESSFULLY";
}

int graph::outdegree(){                     //outdegree for directed and degree for undirected
	string source;
	node * temp1=NULL;
	int outdeg=0;

	cout<<"\n Enter city";				    //get city
	cin>>source;

	int i;

	for(i=0;i<head.size();i++){
		temp1=head[i];
		if(temp1->city==source){
			break;
		}
	}

	if(i==head.size()){				        //validate city
		cout<<"\n INVALID CITY";
		return -1;
	}

	temp1=temp1->next;
	while(temp1!=NULL){
		outdeg++;
		temp1=temp1->next;
	}
	return outdeg;

}

int graph::indegree(){                     //indegree for directed
	string source;
	node * temp1=NULL;
	int indeg=0;

	cout<<"\n Enter city";				    //get city
	cin>>source;

	int i;

	for(i=0;i<head.size();i++){
		if(head[i]->city==source)
			break;
	}

	if(i==head.size()){				        //validate city
		cout<<"\n INVALID CITY";
		return 1;
	}

	for(int i=0;i<head.size();i++){
		node *temp=head[i];

		while(temp->next!=NULL){
			if(temp->next->city==source){
				indeg++;
			}
			temp=temp->next;
		}

	}
	return -indeg;
}

void graph::bfs(){
	node * temp;
vector<string> v ;
bool present ;
vector<string>::iterator it ;
for(int i = 0 ; i<head.size() ; i++)
{
	for(temp = head[i] ; NULL != temp ; temp = temp->next )
	{
		present = false;
		for(it = v.begin();it != v.end() ;it++)
		{
			if(*it == temp->city)
			{
				present = true ;
				break ;
			}
		}
		if(!present)
			v.push_back(temp->city) ;

	}
}
for(it = v.begin() ; it != v.end() ; it++)
	cout<<*it<<"	";
}



int main(){
	graph g1(5);
	g1.getcities();
	g1.addedgedir();
	g1.addedgedir();
	g1.addedgedir();
	g1.addedgedir();
	g1.bfs();
	return 0;
}