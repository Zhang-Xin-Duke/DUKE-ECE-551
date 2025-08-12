#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;

void test0(){
    ifstream ifs("myserver.conf");

    if(!ifs)
    {
        cerr << "ifstream open file failed" << endl;
        return;
    }

    string line;
    string key;
    string value;
    while(std::getline(ifs,line))
    {
        istringstream iss(line);
        iss >> key >> value;
        cout << key << "------>" << value << endl;
    }

    ifs.close();

}

int main(void){
    test0();
    return 0;
}
