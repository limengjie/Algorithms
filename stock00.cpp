/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  09/14/2014 03:22:04 PM
 *
 *    Description:  implementing the stock class
 *
 * ===========================================================================
 */

#include <iostream>
#include "stock00.h"

void Stock::acquire(const std::string & co, long n, double pr) {
  company = co;
  if (n < 0) {
    std::cout << "Number of shares can't be negative; "
      << company << " shares set to 0.\n";
  }
  else
    shares = n;
  share_val = pr;
  set_tot();
}

void Stock::buy(long num, double price) {
  if (num < 0) {
    std::cout << "Number of shares can't be negative; "
      << " Transaction is aborted.\n";
  }
  else {
     shares += num;
     share_val = price;
     set_tot();
   }

}

void Stock::sell(long num, double price) {
  if (num < 0) {
    std::cout << "Number of shares can't be negative; "
      << " Transaction is aborted.\n";
  }
  else if (num > shares) {
    std::cout << "You can't sell more than you have!"
      << " Transaction is aborted.\n";
  }
  else {
    shares -= num;
    share_val = price;
    set_tot();
  }
}

void Stock::update(double price) {
  share_val = price;
  set_tot();
}

void Stock::show() {
  std::cout << "Company: "<< company
    << " Shares: " << shares << '\n'
    << " Share Price: $" << share_val
    << " Total Worth: $" << total_val << '\n';
}



   

