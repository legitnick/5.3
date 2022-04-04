#include "5.3.h"
bool Link::Add(int data) {
	Node* node = new Node();
	if (!i) {
		before_min = max = min = data;

	}
	if (i!=256) {
		node->data = data;
		i++;
		curr->next = node;
		curr = node;
		if (data > max)max = data;
		if (data < min) {
			min = data;
			before_min = prev;
		}
		prev = data;
		if (i == 3)fourth = data;
		sum += data;
		return true;
	}

	return false;
}
 
 
int main()
{ 

}