

#pragma once

namespace itertools
{

template <typename T, typename E>
class chain
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
    bool iter1;

  public:
    iterator(typename T::iterator item1, typename E::iterator item2)
        : value1(item1), value2(item2) , iter1(true){  }

    auto operator*()
    {
      if (iter1)
        return *value1;
      return *value2;
    }

 chain::iterator &operator++()
    {
      if (iter1)
        ++value1;
      else
        ++value2;
      return *this;
    }

    const iterator operator++(int)
    {
      iterator copy(*this);
      if (iter1)
        ++value1;
      else
        ++value2;
      return copy;
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
      if ((value1 != other.value1 )&& iter1)
        iter1 = false;

      if (iter1)
      {
        return value1 != other.value1;
      }
   //   else
    //  {
        return value2 != other.value2;
    //  }
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

  chain(T range1_, E range2_) : range1(range1_), range2(range2_) {}
};
} // namespace itertools
