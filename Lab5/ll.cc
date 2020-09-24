#include "ll.h" 
#include <cstdlib>

LinkedList::Link::Link(unsigned uiData, Link *pNext)
    : m_uiData(uiData), m_pNext(pNext) {}

LinkedList::LinkedList()
    : m_pHead(nullptr){}

bool LinkedList::insert(unsigned uiData) {
    Link* new_link = new Link(uiData, this->m_pHead);			// Get a new node.
    this->m_pHead = new_link;			                        // Put it at the head.
    return true;				                                // Indicate success.
}

bool LinkedList::remove(unsigned &pData) {
    if (!this->m_pHead)				// Empty list?
	    return false;				// Indicate failure.

    Link *temp = this->m_pHead;			    // Point to the first node.
    this->m_pHead = this->m_pHead->m_pNext;	// Remove the first node.
    pData = temp->m_uiData;			    // Obtain first node’s data.
    delete temp;
    return true;				            //Indicate success.
}

void LinkedList::print()
{
    Link *p;
	for (p = this->m_pHead; p != nullptr; p = p->m_pNext){
		std::cout << p->m_uiData << "\n";
	} 

}

LinkedList::~LinkedList()
{  
    Link *p;
    for (p = this->m_pHead; p != nullptr; p = p->m_pNext){
		remove(p->m_uiData);
	} 
}
