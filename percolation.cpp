/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  09/19/2014 04:16:14 PM
 *
 *    Description:  Algorithm assignment 1
 *
 * ===========================================================================
 */

#include <iostream>
#include <cstdlib>
#include <new>

using namespace std;

class Percolation {
  private:
    bool * op;
    int * fu; //the element of full array is the root of the index 
    int len; //the length of one side

  public:
    Percolation(int n);
    ~Percolation();
    void open();
    int find(int i, int j);
    void connect(int i, int j);
    bool isOpen(int i, int j);
    bool isFull(int i, int j);
    bool percolates();
    void show();
};

Percolation::Percolation(int n) {
  len = n;

  op = new bool[len*len];
  fu = new int[len*len];

  for (int i = 0; i < len*len; i++) {
    op[i] = 0;
    fu[i] = i;
  }
}

Percolation::~Percolation() {
}

void Percolation::open() {
  int i, j;

  do {  
  i = rand () % len;
  j = rand () % len;
  } while (isOpen(i, j));
  cout << "Open " << i << ", " << j << endl;

  op[len*i + j] = true;
  connect(i, j);
  percolates();
}

bool Percolation::isOpen(int i, int j) {
  return op[len*i + j];
}

bool Percolation::isFull(int i, int j) {
  int root;

  root = find(i, j); 
  if (root/len)
    return false;
  else
    return true;
}

int Percolation::find(int i, int j) {
  int id = len*i + j;

  while (fu[id] != id)
    id = fu[id];
    
  return id;  
}

void Percolation::connect(const int i, const int j) {
  int oldRoot, newSite = len*i + j;

  if (i < len -1 && op[(i+1)*len + j]) { //case 1:connect the under site 
    cout << "connect the under site." << endl;
    if (((oldRoot = find(i+1, j)) / len) <= i)
      fu[newSite] = oldRoot;
    else
      fu[(i+1)*len + j] = newSite;
  }// end of case1

  if (i > 0 && op[(i-1)*len + j]) { // case 2: connect the above site
    cout << "connect the above site." << endl;
    if (((oldRoot = find(i-1, j)) / len) <= i)
      fu[newSite] = oldRoot;
    else
      fu[(i-1)*len + j] = newSite;
  } // end of case 2
    
  if (j < len - 1 && op[i*len + j + 1]) { //case 3: connect the right site 
    cout << "connect the right site." << endl;
    if (((oldRoot = find(i, j+1)) / len) <= i) {
      cout << "old root is  " << oldRoot << endl;
      fu[newSite] = oldRoot;
    }
    else
      fu[i*len + j + 1] = newSite;
  } // end of case 3

  if (j > 0 && op[i*len + j - 1]) { //case 4: connect the left site
    cout << "connect the left site." << endl;
    if (((oldRoot = find(i, j-1)) / len) <= i) {
      cout << "old root is  " << oldRoot << endl;
      fu[newSite] = oldRoot;
    }
    else
      fu[i*len + j - 1] = newSite;
  } // end of case 4
}
    
bool Percolation::percolates() {
  for (int i = 0; i < len; i++)
    if (isFull(len - 1, i)) {
      cout << "Percolate!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
      return true;
    }
  return false;
}

void Percolation::show() {

  //display coordinate
  
  cout << "=================================================================================" 
  << endl << "column:";
  for (int i = 0; i < len; i++) {
    cout << i << "\t";
  }
  cout << endl
  << "================================================================================="<< endl; 

  cout << "Open:" << endl;
  for (int i = 0; i < len; i++) {
    cout << "i = "<< i << ": ";
    for (int j = 0; j < len; j++) {
      cout << op[len*i + j] << "\t";
    }
    cout << endl;
    }

  cout << "Full: " << endl;
  for (int i = 0; i < len; i++) {
    cout << "i = "<< i << ": ";
    for (int j = 0; j < len; j++) {
      cout << fu[len*i + j] << "\t";
    }
    cout << endl;
    }
  // error and trial
}

//class PercolationStats {
  //public:
    //PercolationStats(int N, int T);
    //double mean();
    //double stddev();
    //double confidenceLo();
    //double condidenceHi();
    ////void test(
//}

int main () {
 Percolation ex1(10); 
 for (int i = 0; i < 60; i++)
   ex1.open();

 ex1.show();
 cout << "percolates() is " << ex1.percolates() << endl;

  return 0;
}
