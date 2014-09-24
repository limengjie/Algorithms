/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  09/22/2014 04:09:53 PM
 *
 *    Description:  implement a double-ended queue
 *
 * ===========================================================================
 */

#include <iostream>
#include <new>

using namespace std;

struct Dnode {
  int num;
  struct Dnode * prev;
  struct Dnode * next;
};

class Deque {
  private:
    int count;
    Dnode * first;
    Dnode * last;
  public:
    Deque();
    ~Deque();
    bool isEmpty();
    int size();
    void addFirst(int num);
    void addLast(int num);
    int removeFirst();
    int removeLast();
    void show();
};

Deque::Deque() {
  count = 0;
  first = NULL;
  last  = NULL;
}

Deque::~Deque() {

}

bool Deque::isEmpty() {
  //cout << "run isEmpty().\n";
  return (!first);
}

int Deque::size() {
  return count;
}

void Deque::addFirst(int n) {
  Dnode * oldfirst = first;

  first = new Dnode;
  first->num = n;
  first->prev = NULL;
  first->next = oldfirst;
  if (oldfirst != NULL) {
    oldfirst->prev = first;
    last = oldfirst;
  }
  count++;
}

void Deque::addLast(int n) {
  Dnode * oldlast = last;

  last = new Dnode;
  last->num = n;
  last->prev = oldlast;
  last->next = NULL;

  if (isEmpty())
    first = last;
  else
    oldlast->next = last;
  count++;
}

int Deque::removeFirst() {
  int number = first->num;
  Dnode * oldfirst = first;

  first = first->next;
  first->prev = NULL;
  count--;
  if (isEmpty())
    first->next = NULL;
  delete oldfirst;

  return number;
}

int Deque::removeLast() {
  int number;

  number = first->num;
  
  cout <<"print \n";
  Dnode * oldlast = last;
  last = last->prev;
  last->next = NULL;
  count--;
  delete oldlast;
  
  return number;
}

void Deque::show() {
  int i = 0;

  if (isEmpty()) {
    cout << "Empty deque. \n";
    return;
  }
  else
    cout << "There are " << count <<" nodes in this linked list.\n";

  Dnode * ptr = first;
  while (ptr != NULL) {
    cout << i++ << ": " << ptr->num << "\t"; 
    ptr = ptr->next;
  }
  cout << endl;
}

int main () {
  Deque ex0;
  ex0.addFirst(1024);
  ex0.addFirst(2);
  ex0.show();
  cout << "Remove node " << ex0.removeLast() << endl;
  ex0.show();
  ex0.addLast(3);
  ex0.addFirst(1);
  ex0.addFirst(100);
  cout << "Remove node " << ex0.removeFirst() << endl;
  ex0.addFirst(0);
  ex0.show();

  return 0;
}
