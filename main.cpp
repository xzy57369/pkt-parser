#include <iostream>
#include <fstream>
#include "Helper.hpp"
using namespace std;

int main() {
    cout<<"parser stated, please enter the pkt format line"<<endl;
    while(true){
        string line=Helper::convert(cin);
        if(line[line.size()-1]=='\n')
            cout<<line;
        else
            cout<<line<<endl;
        cin.clear();
        fflush(stdin);
    }
    return 0;
}

