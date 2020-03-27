#include "Helper.hpp"
#include <iostream>
#include <fstream>
using namespace std;


//convert a pkt-line to actual value
int Helper::convert(istream& is, string& line){
    int len=Helper::readlen(is);
    if(len==0){
        cout<<"flush-pkt"<<endl;
        return STATUS(FLUSH_PKT);
    }
    if(len<4){
        cout<<"length to short，try again"<<endl;
        return STATUS(TOOSHORT);
    }
    if(len>65516){
        cout<<"length to long，try again"<<endl;
        return STATUS(TOOLONG);
    }
    line=Helper::readremain(is,len-4);
    is.get();
    return STATUS(VALID);
}

//read 4 bytes in hexadecimal from is and return corresponding decimal number
int Helper::readlen(istream& is){
    string s="";
    char c;
    for(int i=0;i<4;i++){
        is.get(c);
        if(c==EOF)
            exit(0);
        s+=c;
    }
    return hextoint(s);
}

//read len bytes from is, return byte array as string
string Helper::readremain(istream& is,int len){
    string s="";
    char c;
    for(int i=0;i<len;i++){
        is.get(c);
        s+=c;
    }
    return  s;
}

//convert 4bytes string to a decimal number
int Helper::hextoint(string s){
    int res=0;
    for(int i=0;i<4;i++){
        int temp=0;
        if(s[i]<='9'&&s[i]>='0')
            temp=s[i]-'0';
        else if(s[i]<='f'&&s[i]>='a')
            temp=s[i]-'a'+10;
        res=res*16+temp;
    }
    return res;
}

