#include <iostream>
#include "arraystack.h"
#include "arraystack.cpp"
using namespace std;

// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
    printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
    else { \
    printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
    passedAssertions++; \
    }
#define assertionReport() { \
    printf("==========================================\n"); \
    printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
    printf("\n"); \
    }
//*******************************************************


int main() {
    ArrayStack<int> S;

    S.push(10);
    S.push(20);

    expect( S.top() == 20 );
    S.pop();
    expect( S.top() == 10 );
    S.pop();
    expect( S.empty() );

    return 0;
}
