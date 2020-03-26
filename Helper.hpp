#ifndef Helper_hpp
#define Helper_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>

#endif /* Helper_hpp */
using namespace std;
class Helper{
public:
    static string convert(istream& is);
    static int readlen(istream& is);
    static string readremain(istream& is,int len);
    static int hextoint(string s);
};
