#pragma once
#include<iostream>
#include <fstream>
#include <math.h> 
using namespace std;

class Node {

	double data = NULL;
	Node* next = nullptr;
public:
	friend class Link;
};
class Link {
	Node* curr;
	friend class Node;

	int prev,sum = 0,i = 0;

public:
	bool Add(int data);
	int min,max,fourth,before_min;
	double avg;
};