#include <iostream>
using namespace std;

#include "chain.hpp"
#include "range.hpp"
#include "product.hpp"
#include "zip.hpp"
#include "powerset.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace itertools;
template<typename Iterable>
string iterable_to_string(const Iterable& iterable) {
    ostringstream ostr;
    for (decltype(*iterable.begin()) i: iterable)
        ostr << i << " ";
    return ostr.str();
}
int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

	testcase.setname("range")
    .CHECK_EQUAL("1 2 3 4" , iterable_to_string(range(1,5)))
    .CHECK_EQUAL("1.1 2.1 3.1 4.1", iterable_to_string(range(1.1,5.1)))
    .CHECK_EQUAL("a b c d e f",  iterable_to_string(range('a','g')))
    .CHECK_EQUAL("1001 1002 1003 1004", iterable_to_string( range(1000,1105)))
    .CHECK_EQUAL("A B C D E F", iterable_to_string( range('A','G')))
    .CHECK_EQUAL("A B C D E", iterable_to_string( "ABCDE"))  
     ;
	testcase.setname("cahin")
    .CHECK_EQUAL("1 2 3 4 1.1 2.1 3.1 4.1", iterable_to_string(chain(range(1,5), range(1.1,5.1))))
    .CHECK_EQUAL("1.1 2.1 3.1 4.1 1 2 3 4",  iterable_to_string(chain(range(1.1,5.1), range(1,5))))
    .CHECK_EQUAL("a b c d e f g f e d c b", iterable_to_string(chain(range('a','g'), range('g','a'))))
    .CHECK_EQUAL("g f e d c b a b c d e", iterable_to_string(chain(range('g','a'), range('a','g'))))
    .CHECK_EQUAL("a b c d e f 1 2 3 4 5", iterable_to_string(chain(range('a','g'), range(1,6))))
    .CHECK_EQUAL("1 2 3 4 5 a b c d e f", iterable_to_string(chain(range(1,6), range('a','g'))))
    .CHECK_EQUAL("h e l l o 1.1 2.1 3.1 4.1", iterable_to_string(chain("hello", range(1.1,5.1)))) 
    .CHECK_EQUAL("h e l l o w o r l d"  ,iterable_to_string(chain("hello", "world")))
    ;

    testcase.setname("zip")
    .CHECK_EQUAL("1,1.1 2,2.1 3,3.1 4,4.1", iterable_to_string(zip(range(1,5), range(1.1,5.1))))
    .CHECK_EQUAL("1.1,1 2.1,2 3.1,3 4.1,4", iterable_to_string( zip(range(1.1,5.1), range(1,5))))
    .CHECK_EQUAL("a,g b,f c,e d,d e,c f,b", iterable_to_string(zip(range('a','g'), range('g','a'))))
    .CHECK_EQUAL("g,a f,b e,c d,d c,e b,f", iterable_to_string(zip(range('g','a'), range('a','g'))))
    .CHECK_EQUAL("a,1 b,2 c,3 d,4 e,5 f,6", iterable_to_string(zip(range('a','g'), range(1,7))))
    .CHECK_EQUAL("1,a 2,b 3,c 4,d 5,e 6,f", iterable_to_string(zip(range(1,7), range('a','g'))))
    .CHECK_EQUAL("h,1.1 e,2.1 l,3.1 l,4.1 o,5.1", iterable_to_string(zip("hello", range(1.1,6.1)))) 
    .CHECK_EQUAL("h,w e,o l,r l,l o,d", iterable_to_string(zip("hello", "world")))
    .CHECK_EQUAL("1,x,a,6  2,y,b,7 3,z,c,8", iterable_to_string(zip(zip(range(1,4), string("xyz")),zip(string("abc"),range(6,9)))))
    ;

    testcase.setname("product")
    .CHECK_EQUAL("1,1.1 1,2.1 2,1.1 2,3.1", iterable_to_string(product(range(1,3), range(1.1,3.1))))
   .CHECK_EQUAL("1.1,1 1.1,2 2.1,1 2,2.1", iterable_to_string (product(range(1.1,3.1), range(1,3))))
    .CHECK_EQUAL("a,c a,b b,c b,b", iterable_to_string(product(range('a','c'), range('c','a'))))
    .CHECK_EQUAL("c,a c,b b,a b,b", iterable_to_string(product(range('c','a'), range('a','c'))))
    .CHECK_EQUAL("a,1 a,2 b,1 b,2", iterable_to_string(product(range('a','c'), range(1,3))))
    .CHECK_EQUAL("1,a 1,b 2,a 2,b", iterable_to_string(product(range(1,3), range('a','c'))))
    .CHECK_EQUAL("a,1 a,2 b,1 b,2", iterable_to_string(product("ab", range(1,3)))) 
    ;

      testcase.setname("powerset")
    .CHECK_EQUAL("{} {1} {2} {1,2} {3} {1,3} {2,3} {1,2,3}" , iterable_to_string(powerset(1,4)))
    .CHECK_EQUAL("{} {1.1} {2.1} {1.1,2.1} {3.1} {1.1,3.1} {2.1,3.1} {1.1,2.1,3.1}", iterable_to_string(powerset(1.1,4.1)))
    .CHECK_EQUAL("{} {a} {b} {a,b}",  iterable_to_string(powerset('a','c')))
    .CHECK_EQUAL("{} {a} {b} {a,b} {c} {a,c} {b,c} {a,b,c}", iterable_to_string( "abc"))  
    .CHECK_EQUAL("{}", iterable_to_string( ""))  
    ;
    
    




		
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
