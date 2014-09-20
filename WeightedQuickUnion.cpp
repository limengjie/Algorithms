/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  09/19/2014 08:49:52 AM
 *
 *    Description:  weighted quick-union UF implementaion
 *
 * ===========================================================================
 */

#include <iostream>
#include <new>
using namespace std;

class WQU {
  private:
    int * id;
    int * sz;
    int num;
  public:
    WQU(int n);
    ~WQU();
    int count();
    bool isConnected(int p, int q);
    int find(int p);
    void un(int p, int q);
    void show();
};

WQU::WQU(int n) {
  num = n;
  cout << "Constructor: " << endl;
  id = new int[10];
  sz = new int[10];

  for (int i = 0; i < n; i++) {
    id[i] = i;
    sz[i] = 1;
    cout << id[i] << endl;
  }
}

WQU::~WQU() {
}

int WQU::count() {
  return num;
}

bool WQU::isConnected(int p, int q) {
  return find(p) == find(q);
}

int WQU::find(int p) {
  while (p != id[p])
    p = id[p];

  return p;
}

void WQU::un(int p, int q) {
  int i = find(p);
  int j = find(q);
  if (i == j)
    return;

  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  }
  else {
    id[j] = i;
    sz[i] += sz[j];
  }
}

void WQU::show() {
  //using namespace std;

  cout << num << endl;
  for (int i = 0; i < num; i++)
    cout << "id" << i << " is " << id[i] << endl;
}


int main () {
  WQU uf(10);
  uf.show();
  uf.un(4, 3);
  cout << "after 1st union: "<< endl;
  uf.show();
  uf.un(3, 8);
  uf.un(6, 5);
  uf.un(9, 4);
  uf.un(2, 1);
  uf.un(8, 9);
  uf.un(5, 0);
  uf.un(7, 2);
  uf.un(6, 1);
  uf.un(1, 0);

  cout << "root of 3 is " << uf.find(3) << endl;
  cout << "root of 1 is " << uf.find(1) << endl;
  cout << "8 and 9 are connected." << uf.isConnected(8, 9) << endl;
  cout << "4 and 1 are connected." << uf.isConnected(1, 4) << endl;
}
