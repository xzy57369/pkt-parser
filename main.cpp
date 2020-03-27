#include <iostream>
#include <fstream>
#include "Helper.hpp"
using namespace std;

int main() {
    cout<<"parser stated, please enter the pkt format line"<<endl;
    int state;
    do{
        string line;
        state=Helper::convert(cin,line);
        if(line[line.size()-1]=='\n')
            cout<<line;
        else
            cout<<line<<endl;
        cin.clear();
        fflush(stdin);
    }while(state == STATUS(VALID));
    return 0;
}

