#pragma once
#include<iostream>
#include <fstream>
#include <math.h> 
#include <vector>
#include <string>
using namespace std;

struct Answer {
	friend class Link;
protected:
	int min=INT_MAX, max=INT_MIN, fourth, before_min=NULL;
	int prev, sum = 0, i = 0;
	bool changed = true;
};
class Node {
	Node* next ;
	double data = NULL;
public:
	friend class Link;
};
class Link {
	Node* head,*curr;
	int i = 0;
public:
	Answer* answer;
	string GetN();
	string GetAVG();
	string GetMINIMAX();
	string GetFourth();
	string GetBeforeMIN();
	void GetAnswer(); 
	bool Add(int data);
};