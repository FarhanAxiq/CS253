//
//  Lab 05
//  ll.cc
//  Farhan Haziq
//  fargah1@cs.colostate.edu
//  TBD
//


#include "ll.h" 
#include <cstdlib>

LinkedList::Link::Link(unsigned uiData, Link *pNext)
    : m_uiData(uiData), m_pNext(pNext) {}

LinkedList::LinkedList()
    : m_pHead(nullptr){}

bool LinkedList::insert(unsigned uiData) {
    Link* new_link = new Link(uiData, m_pHead);	// Get a new node.
    m_pHead = new_link;			                // Put it at the head.
    return true;				                // Indicate success.
}

bool LinkedList::remove(unsigned &pData) {
    if (!m_pHead)				    // Empty list?
	    return false;				// Indicate failure.

    Link *temp = m_pHead;			// Point to the first node.
    m_pHead = m_pHead->m_pNext;	    // Remove the first node.
    pData = temp->m_uiData;         // Obtain first node’s data.
    delete temp;                    // delete heap object
    return true;                    // Indicate success.
}

void LinkedList::print()
{
    Link *temp;
	for (temp = m_pHead; temp != nullptr; temp = temp->m_pNext){ std::cout << temp->m_uiData << " "; } 
    std::cout << "\n";
}

std::ostream &operator<<(std::ostream& out, const LinkedList &val)
{
	LinkedList::Link *temp = val.m_pHead;
	if 	(temp == nullptr) { out << "Empty\n"; }
	for (temp = val.m_pHead; temp != nullptr; temp = temp->m_pNext) { out << temp->m_uiData << " "; }
	return out;
}

LinkedList::~LinkedList()
{  
    Link *temp;
    for (temp = m_pHead; temp != nullptr; temp = temp->m_pNext){ 
        remove(temp->m_uiData); 
    } 
}