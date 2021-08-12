#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <string>
#include <exception>

using namespace std;

class RuntimeException { // generic run-time exception private:
    string errorMsg; public:
    RuntimeException(const string& err) { errorMsg = err; }
    string getMessage() const { return errorMsg; } };

class StackEmpty : public RuntimeException {
public:
    StackEmpty(const string& err) : RuntimeException(err) {} };

class StackFull : public RuntimeException {
public:
    StackFull(const string& err) : RuntimeException(err) {} };

template <typename E>
class ArrayStack {
    enum { DEF_CAPACITY = 100 };
public:
    // default stack capacity
    ArrayStack(int cap = DEF_CAPACITY);
    ~ArrayStack();
    int size() const;
    bool empty() const;
    const E& top() const throw(StackEmpty); // get the top element
    void push(const E& e) throw(StackFull);
    void pop() throw(StackEmpty);
private:
    E* S;
    int capacity; int t;

};


#endif // ARRAYSTACK_H
