#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

class LinkedList {
  public:
    LinkedList();
    bool insert(unsigned uiData);
    bool remove(unsigned &pData);
    void print();
    ~LinkedList();
    friend std::ostream &operator<<(std::ostream& out, const LinkedList &val);

  private:
    struct Link {
	    unsigned m_uiData;
	    Link *m_pNext;
      Link(unsigned uiData, Link *pNext);
    } *m_pHead;
};

#endif /* LINKED_LIST_H */ 
