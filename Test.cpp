#include <iostream>
#include <fstream>
#include "Helper.hpp"
using namespace std;

class Test{
public:
    void test(){
        ifstream input("./testcase.txt");
        string line="";
        cout<<"------------------------"<<endl;
        cout<<"test case 1: short without LF"<<endl;
        cout<<"input '0006ab', expecting 'ab'"<<endl;
        Helper::convert(input,line);
        printActual(line);
        if(line=="ab")
            cout<<"passed"<<endl;
        else
            cout<<"failed"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"test case 2: short with LF"<<endl;
        cout<<"input '0006a\\n', expecting 'a\\n'"<<endl;
        Helper::convert(input,line);
        printActual(line);
        if(line=="a\n")
            cout<<"passed"<<endl;
        else
            cout<<"failed"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"test case 3: mid length"<<endl;
        cout<<"input '000bfoobar\\n', expecting 'foobar\\n'"<<endl;
        Helper::convert(input,line);
        printActual(line);
        if(line=="foobar\n")
            cout<<"passed"<<endl;
        else
            cout<<"failed"<<endl;
        
        cout<<"------------------------"<<endl;
        cout<<"test case 4: empty line"<<endl;
        cout<<" input '0004', expecting ''"<<endl;
        Helper::convert(input,line);
        printActual(line);
        if(line=="")
            cout<<"passed"<<endl;
        else
            cout<<"failed"<<endl;
        cout<<"------------------------"<<endl;

        cout<<"test case 5: long line"<<endl;
        cout<<"input '0104abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh'"<<endl<<"expecting 'abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh'"<<endl;
        Helper::convert(input,line);
        printActual(line);
        if(line=="abcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefghabcdefgh")
            cout<<"passed"<<endl;
        else
            cout<<"failed"<<endl;
        cout<<"------------------------"<<endl;

        //0000, should exit
        Helper::convert(input,line);
    }

    void printActual(string line){
        int len=line.size();
        cout<<"parser output: '";
        if(line[len-1]=='\n'){
            cout<<line.substr(0,len-1)<<"\\n";
        }else{
            cout<<line;
        }
        cout<<"'"<<endl;
    }
};

int main(){
    Test t;
    t.test();
}
