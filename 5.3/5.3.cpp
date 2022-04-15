#include "5.3.h"
bool Link::Add(int data) {
	if (!i) {
		i++; 
		head = new Node(data);
		curr = head;
		return true;
	}
	if (i!=256) {
		Node* node = new Node(data);
		i++; 
		curr->next = node;
		curr = node;
		return true;
	}

	return false;
}
void Link::GetAnswer() {
	curr = head;
	int i = 0;
	answer = new Answer();
	while (head!= nullptr) { 
		
	if (head->data > answer->max)answer->max = head->data;
	if (head->data < answer->min) {
		answer->min = head->data;
		if(i)answer->before_min = answer->prev;
	}
	answer->prev = head->data;
	if (i == 3)answer->fourth =head-> data;
	i++;
	answer->sum += head->data;
	head = head->next;
	}
}
string Link::GetN()
{
	return  string("Number of elements " + to_string(i)+"\n");
}

string Link::GetAVG()

{
	GetAnswer();//to get this answer struct 
	return i ? (string("Average " + to_string(answer->sum/(double)i) + "\n")): "Not enough elements\n";
}

string Link::GetMINIMAX()
{
	return i?(string("Minimum " + to_string(answer->min) + " Maximum " + to_string(answer->max) + "\n")):"Not enough elements for min and max elements";
}

string Link::GetFourth()
{

	return i>3?string("Fourth " + to_string(answer->fourth) + "\n"): "Not enough elements\n";
}

string Link::GetBeforeMIN()
{ 

	return 
		(answer->before_min==NULL) ? "Not enough elements, or the smallest element is first\n" : string("The element before the minimum element " + to_string(answer->before_min) + "\n");
}
 
void Fill(Link& link) {
	int i = 0;
	int value = INT_MIN;
	while (!cin.fail())
	{
		if (i && i < 256) {
			link.Add(value);
		}
		cout << "Enter a value, type a string to save ";
		cin >> value;
		i++;
	}
 }
int main()
{
	Link link;
	Fill(link);
	cout << link.GetAVG();
	cout << link.GetBeforeMIN();
	cout << link.GetMINIMAX();
	cout << link.GetFourth();
	cout << link.GetN();
	while (true);
}