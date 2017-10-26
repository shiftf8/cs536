#include "DualStack.h"
#include <iostream>

DualStack::DualStack(int n)
{
    dual_stack = new int[n];
    dual_stack_length = n;
    stack_one_length = 0;
    stack_two_length = 0;
}
bool DualStack::push1(int x)
{
    if (!isFull1()) //For consistency sake, we'll use isFullx() of the stack we're trying to push to.
    {
        dual_stack[stack_one_length++] = x;
        return true;
    }
    return false;
}
bool DualStack::push2(int x)
{
    if (!isFull2()) //For consistency sake, we'll use isFullx() of the stack we're trying to push to.
    {
        dual_stack[(dual_stack_length - 1) - stack_two_length] = x;
        stack_two_length++;
        return true;
    }
    return false;
}
int DualStack::peek1()
{
    if (isEmpty1()) throw("Cannot peek, stack is empty");
    return dual_stack[stack_one_length - 1];
}
int DualStack::peek2()
{
    if (isEmpty2()) throw("Cannot peek, stack is empty");
    return dual_stack[dual_stack_length - stack_two_length];
}
bool DualStack::pop1()
{
    if (!isEmpty1()) stack_one_length--;
}
bool DualStack::pop2()
{
    if (!isEmpty2()) stack_two_length--;
}
bool DualStack::isFull1()
{
    if (stack_one_length + stack_two_length == dual_stack_length) return true;
    return false;
}
bool DualStack::isFull2()
{
    if (stack_one_length + stack_two_length == dual_stack_length) return true;
    return false;
}
bool DualStack::isEmpty1()
{
    if (stack_one_length == 0) return true;
    return false;
}
bool DualStack::isEmpty2()
{
    if (stack_two_length == 0) return true;
    return false;
}