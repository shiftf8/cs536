#include <iostream>
#include <string>

int count(int arr[], int target, int first, int last);
bool isPal(std::string s, int first, int last);

int main()
{
    int arr1[] = {3, 9, 2, 7, 9, 4, 4, 3, 9};
    int arr2[] = {6};
    int arr3[] = {4, 6, 2, 3};
    int arr4[] = {12};
    
    std::cout <<count(arr1, 9, 0, 9) <<std::endl;
    std::cout <<count(arr1, 4, 0, 9) <<std::endl;
    std::cout <<count(arr2, 6, 0, 1) <<std::endl;
    std::cout <<count(arr3, 9, 0, 4) <<std::endl;
    std::cout <<count(arr4, 5, 0, 1) <<std::endl
        <<std::endl;
    
    std::cout <<isPal("radar", 0, 4) <<std::endl;
    std::cout <<isPal("x", 0, 0) <<std::endl;
    std::cout <<isPal("aba", 0, 2) <<std::endl;
    std::cout <<isPal("xx", 0, 1) <<std::endl;
    std::cout <<isPal("ab", 0, 1) <<std::endl;
    std::cout <<isPal("abc", 0, 2) <<std::endl;
    std::cout <<isPal("123321", 0, 5) <<std::endl;
    std::cout <<isPal("xxlx", 0, 3) <<std::endl;

    return 0;
}


int count(int arr[], int target, int first, int last) //Technically I used int last as arr length.
{
    if (first == last) return 0;
    if (arr[first] == target) return count(arr, target, ++first, last) + 1;
    return count(arr, target, ++first, last);
}
bool isPal(std::string s, int first, int last)
{
    if (first == last || (first == last - 1 && s[first] == s[last])) return true;
    if (s[first] == s[last]) return isPal(s, ++first, --last);
    return false;
}