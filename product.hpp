

#pragma once
#include "iostream"
using namespace std;
namespace itertools
{

template <typename T, typename E>
class product
{

private:
  T range1;
  E range2;

public:

  class iterator
  {

  private:
    typename T::iterator value1;
    // typename T::iterator value1end;
    typename E::iterator value2;
    typename E::iterator start2;
    bool end2;

  public:
    iterator(typename T::iterator value1_, typename E::iterator value2_)
        : value1(value1_), value2(value2_) , start2(value2_), end2(false){  }

    auto operator*()
    {
       return pair<decltype(*value1),decltype(*value2)> (*value1, *value2);
    }

 product::iterator &operator++()
    {
         if(end2){
                   value2=start2;
                   ++value1;
            }
            else
            {
                ++value1; ++value2;
            }
            
      return *this;
    }

    const iterator operator++(int)
    {
    /*
        ++value1;
        ++value2;
      return copy;*/
    }

    bool operator==(iterator &other)
    {/*
        if (value1 == other.value1 && iter1)
        iter1 = false;

      if (iter1)
      {
        return value1 == other.value1;
      }
   //   else
    //  {
        return value2 == other.value2;
    //  }*/
   }
       bool operator!=(iterator &other)
    {

    //  if((it1 != it.it1) && !(it2 != it.it2)
      if (value1!=other.value1 && value2==other.value2)
      end2=true;
      
        return value1 != other.value1 && value2 != other.value2;
   
    }
  };

  iterator begin()
  {
    return iterator(range1.begin(), range2.begin());
  }

 iterator end()
  {
    return iterator(range1.end(), range2.end());
  }

  product(T range1_, E range2_) : range1(range1_), range2(range2_) {}
};
/*
template <typename T,typename E>
ostream &operator<<(ostream &os, const pair<T,E> &p){
        os << p.first << ',' << p.second;
        return os;
}*/
} 