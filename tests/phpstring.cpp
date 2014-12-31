#include <stdio.h>
#include <iostream>
#include "../phpstring.hpp"
using namespace std;

int main(int argc, char** argv)
{
    string str = "I am a pen.";
    vector<string> splits = phpstring::explode( str, " " );
    string back = phpstring::implode( splits, "_" );
    cout << back << endl;
    return 0;
}
