#ifndef DUAL_STACK
#define DUAL_STACK

class DualStack
{
    private:
    int* dual_stack;
    int dual_stack_length;
    int stack_one_length;
    int stack_two_length;
    
    public:
    DualStack(int n);
    bool push1(int x);
    bool push2(int x);
    int peek1();
    int peek2();
    bool pop1();
    bool pop2();
    bool isFull1();
    bool isFull2();
    bool isEmpty1();
    bool isEmpty2();
};
#endif