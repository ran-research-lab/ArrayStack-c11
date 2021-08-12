#include "arraystack.h"

template <typename E>
ArrayStack<E>::ArrayStack(int cap)
    : S(new E[cap]), capacity(cap), t(-1) { }

template <typename E>
ArrayStack<E>::~ArrayStack() {
    delete [] S;
}

template <typename E>
int ArrayStack<E>::size() const
{ return (t + 1); }

template <typename E>
bool ArrayStack<E>::empty() const
{ return (t < 0); }

template <typename E> // return top of stack
const E& ArrayStack<E>::top() const throw(StackEmpty) {
    if (empty()) throw StackEmpty("Topofemptystack");
    return S[t]; }


template <typename E> // push element onto the stack
void ArrayStack<E>::push(const E& e) throw(StackFull) {
if (size() == capacity) throw StackFull("Pushtofullstack");
S[++t] = e;
}


template <typename E> // pop the stack
void ArrayStack<E>::pop() throw(StackEmpty) {
if (empty()) throw StackEmpty("Popfromemptystack");
--t;
}
