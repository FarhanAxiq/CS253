//
//  Lab 05
//  main.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  TBD
//

#include <iostream>
#include "ll.h" 

using namespace std;

inline ostream &operator<<(ostream& out, const LinkedList &val)
{
	LinkedList::Link *temp = val.m_pHead;
	if 	(temp == nullptr) { out << "Empty\n"; }
	for (temp = val.m_pHead; temp != nullptr; temp = temp->m_pNext) { out << temp->m_uiData << " "; }
	return out;
}

int main() {

    LinkedList list;
    bool done = false;
    while (!done) {
	unsigned int i;
	int option;

	cout << "Choose your operation:\n"
	     << "1. insert\t2. remove\t3. exit\t4. print\n";

	cin >> option;

	switch (option) {
	    case 1:
			cout << "Enter the number to insert\n";
			cin >> i;
			list.insert(i);
			break;
	    case 2:
			if (list.remove(i))
				cout << "removed " << i << '\n';
			else
				cout << "No numbers in the list\n";
			break;
	    case 3:
			done = true;
			break;
		case 4:
			// list.print();
			cout << list << '\n';
			break;
		default:
			cerr << option << " is an invalid input\n";
			break;
		}
    }
    return 0;
} 
// destructor is called when scope end, cleaned up all the leaks
