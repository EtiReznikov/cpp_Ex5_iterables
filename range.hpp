namespace itertools{
#pragma once
//#include <iostream>
//using namespace std;
//#include <iostream>
//#include <sstream>
template<typename T>
class range {
 public:
   class iterator {
    //  friend class range;
    public:
      auto operator *() const { return value; }
      const iterator &operator ++() { ++value; return *this; }
      iterator operator ++(int) { iterator copy(*this); ++value; return copy; }

      bool operator ==(const iterator &other) const { return value == other.value; }
      bool operator !=(const iterator &other) const { return value != other.value; }

    //protected:
      iterator(T start) : value (start) { }

    private:
      T value;
   };

   iterator begin() const { return begin_; }
   iterator end() const { return end_; }
   range(T  begin, T end) : begin_(begin), end_(end) {}
private:
   iterator begin_;
   iterator end_;
};
}
