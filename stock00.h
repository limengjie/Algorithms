/*
 * ===========================================================================
 *
 *         Author:  Ming Chen, v.mingchen@gmail.com
 *        Created:  09/14/2014 03:14:13 PM
 *
 *    Description:  stock class interface
 *
 *
 * ===========================================================================
 */

#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock {
  private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_tot() { total_val = shares * share_val; } //inline method
  public:
    void acquire(const std::string & co, long n, double pr);
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show();
}; //note semicolon at the end

#endif
