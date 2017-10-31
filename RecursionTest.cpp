#include <iostream>
#include <string>

int count(int arr[], int target, int first, int last);
bool isPal(std::string s, int first, int last);
void reverseWords(std::string &s);

int main()
{
    int arr1[] = {3, 9, 2, 7, 9, 4, 4, 3, 9};
    int arr2[] = {6};
    int arr3[] = {4, 6, 2, 3};
    int arr4[] = {12};
    
    std::cout <<"3, 9, 2, 7, 9, 4, 4, 3, 9\tT: 9\tE: 3\tR: " <<count(arr1, 9, 0, 9) <<'\n';
    std::cout <<"3, 9, 2, 7, 9, 4, 4, 3, 9\tT: 4\tE: 2\tR: " <<count(arr1, 4, 0, 9) <<'\n';
    std::cout <<"6\t\t\t\tT: 6\tE: 1\tR: " <<count(arr2, 6, 0, 1) <<'\n';
    std::cout <<"4, 6, 2, 3\t\t\tT: 9\tE: 0\tR: " <<count(arr3, 9, 0, 4) <<'\n';
    std::cout <<"12\t\t\t\tT: 5\tE: 0\tR: " <<count(arr4, 5, 0, 1) <<'\n'
        <<'\n';
    
    std::cout <<"radar\t";
    if (isPal("radar", 0, 4)) std::cout <<"true";
    else std::cout <<"false";
    std::cout <<'\n';
    std::cout <<"x\t";
    if (isPal("x", 0, 0)) std::cout <<"true";
    else std::cout <<"false";
    std::cout <<'\n';
    std::cout <<"aba\t";
    if (isPal("aba", 0, 2)) std::cout <<"true";
    else std::cout <<"false";
    std::cout <<'\n';
    std::cout <<"xx\t";
    if (isPal("xx", 0, 1)) std::cout <<"true";
    else std::cout <<"false";
    std::cout <<'\n';
    std::cout <<"ab\t";
    if (isPal("ab", 0, 1)) std::cout <<"true";
    else std::cout <<"false";
    std::cout <<'\n';
    std::cout <<"abc\t";
    if (isPal("abc", 0, 2)) std::cout <<"true";
    else std::cout <<"false";
    std::cout <<'\n';
    std::cout <<"123321\t";
    if (isPal("123321", 0, 5)) std::cout <<"true";
    else std::cout <<"false";
    std::cout <<'\n';
    std::cout <<"xxlx\t";
    if (isPal("xxlx", 0, 3)) std::cout <<"true";
    else std::cout <<"false";
    std::cout <<'\n'
        <<'\n';
    
    std::string s1 = "Hello world";
    std::string s2 = "Goodbye";
    std::string s3 = "When in the course of human events";
    
    std::cout <<s1 <<"\t\t\t\t";
    reverseWords(s1);
    std::cout <<s2 <<"\t\t\t\t\t";
    reverseWords(s2);
    std::cout <<s3 <<"\t";
    reverseWords(s3);

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
void reverseWords(std::string &s)
{
    if (s.rfind(' ') != std::string::npos)
    {
        std::cout <<s.substr(s.rfind(' ') + 1, s.back()) << ' '; //The + 1 and adding space is a hack.
        return reverseWords(s.erase(s.rfind(' '), s.back()));
    }
    std::cout <<s <<'\n';
}