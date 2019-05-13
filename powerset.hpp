

//#pragma once
#include "iostream"
#include <queue>
using namespace std;
namespace itertools
{

template <typename T>
class powerset
{

private:
  T range1;

public:

  class iterator
  {

  private:
    typename T::iterator value1;
    // typename T::iterator value1end;
    typename T::iterator value2;
   // bool iter1;

  public:
    iterator(typename T::iterator value1_ ,typename T::iterator value2_)
        : value1(value1_), value2(value2_) {  }

    auto operator*()
    {
      queue<decltype(*value1)> q;
      return q;
         //pair ans(*value1,value2) ;
       //   return ans;
      //return std::pair(*value1, *value2);
     // return pair<decltype(*value1),decltype(*value2)> (*value1, *value2);
        // return pair(*value1, *value2);
    }

 powerset::iterator &operator++()
    {
      
        ++value1;
      
        ++value2;
      return *this;
    }

    const iterator operator++(int)
    {/*
      iterator copy(*this);
      if (iter1)
        ++value1;
      else
        ++value2;
      return copy;*/
    }

    bool operator==(iterator &other)
    {
    }
    bool operator!=(iterator &other)
    {
      
        return value1 != other.value1 &&value2 != other.value2;
   
    }
  };

  iterator begin()
  {
    return iterator(range1.begin(), range1.end());
  }

  iterator end()
  {
    return iterator(range1.begin(), range1.end());
  }

  powerset(T range1_) : range1(range1_) {}
};

template <typename T>
ostream &operator<<(ostream &os,  queue<T> &q)
{
    os << "{";
    while (!(q.empty()))
    {
      os<<q.front();
      q.pop();
      if (!(q.empty()))
      os<<",";
    }
    os << "}";
    return os;
}

} // namespace itertools
