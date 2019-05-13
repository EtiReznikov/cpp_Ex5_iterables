

//#pragma once
#include "iostream"
using namespace std;
namespace itertools
{

template <typename T, typename E>
class zip
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
   // bool iter1;

  public:
    iterator(typename T::iterator value1_ ,typename E::iterator value2_)
        : value1(value1_), value2(value2_) {  }

    auto operator*()
    {
         //pair ans(*value1,value2) ;
       //   return ans;
      //return std::pair(*value1, *value2);
      return pair<decltype(*value1),decltype(*value2)> (*value1, *value2);
        // return pair(*value1, *value2);
    }

 zip::iterator &operator++()
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
      
        return value1 != other.value1 && value2 != other.value2;
   
    }
  };

  auto begin()
  {
    return zip::iterator(range1.begin(), range2.begin());
  }

  auto end()
  {
    return zip::iterator(range1.end(), range2.end());
  }

  zip(T range1_, E range2_) : range1(range1_), range2(range2_) {}
};
template <typename T,typename E>
ostream &operator<<(ostream &os, const pair<T,E> &p){
        os << p.first << ',' << p.second;
        return os;
}
} // namespace itertools
