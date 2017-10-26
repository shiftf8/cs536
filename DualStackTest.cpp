#include <iostream>
#include "DualStack.cpp"

int main()
{
    DualStack test(10);
    
    std::cout <<"isEmpty1():\t" <<test.isEmpty1() <<std::endl
        <<"isEmpty2():\t" <<test.isEmpty2() <<std::endl;
        
    test.push1(10);
    // std::cout <<"peek1():\t" <<test.peek1() <<std::endl;
    test.push1(20);
    // std::cout <<"peek1():\t" <<test.peek1() <<std::endl;
    test.push1(30);
    // std::cout <<"peek1():\t" <<test.peek1() <<std::endl;
    test.push1(40);
    test.push2(100), test.push2(200), test.push2(300), test.push2(400), test.push2(500), test.push2(600);

    std::cout <<"isFull1():\t" <<test.isFull1() <<std::endl
        <<"isFull2():\t" <<test.isFull2() <<std::endl;
    
    std::cout <<"peek1():\t" <<test.peek1() <<std::endl
        <<"peek2():\t" <<test.peek2() <<std::endl;
        
    test.pop1(), test.pop1();
    test.pop2(), test.pop2(), test.pop2();
    
    std::cout <<"peek1():\t" <<test.peek1() <<std::endl
        <<"peek2():\t" <<test.peek2() <<std::endl;
        
    test.pop1(), test.pop1();
    
    std::cout <<"isEmpty1():\t" <<test.isEmpty1() <<std::endl
        <<"isEmpty2():\t" <<test.isEmpty2() <<std::endl;
    
    return 0;
}