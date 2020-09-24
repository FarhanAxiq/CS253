#include <iostream>
#include "ll.h" 

using namespace std;

inline ostream &operator<<(ostream& out, const LinkedList &val)
{
	LinkedList::Link *p;
	for (p = val.m_pHead; p != nullptr; p = p->m_pNext){
		out << p->m_uiData << "\n";
	}
	return out;
}

int main() {

    LinkedList list;
    bool done = false;
    while (!done) {
	unsigned int i;
	int option;

	cout << "Choose your operation:\n"
	     << "1. insert\t2. remove\t3. exit\n";

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
		default:
			cerr << option << " is an invalid input\n";
			break;
		}
    }
	cout << "using class print function\n";
	list.print();
	cout << "using std::ostream<< operator overload\n" << list;
    return 0;
} 
