#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::cerr;
using std::unordered_map;
using std::string;
using std::ifstream;
using std::istringstream;

class WordTrans
{
public:
    void buildMap(const string &filename)
    {
        ifstream ifs(filename);
        if(!ifs)
        {
            cerr << "open file " << filename << endl;
            return;
        }

        string key;
        string line;
        while(ifs >> key, getline(ifs, line))
        {
            if(line.size() > 1)
            {
                _um[key] = line.substr(1);//取子串
                /* _um.insert({key, line.substr(1)}); */
            }
        }

        ifs.close();
    }

    void trans(const string &filename)
    {
        ifstream ifs(filename);
        if(!ifs)
        {
            cerr << "open file " << filename << endl;
            return;
        }

        string line;
        while(getline(ifs, line))
        {
            istringstream iss(line);

            string word;
            while(iss >> word)
            {
                auto it = _um.find(word);
                if(it == _um.end())
                {
                    cout << word;
                }
                else
                {
                    cout << it->second;
                }

                cout << " ";
            }
            cout << endl;
        }

        ifs.close();
    }

private:
    unordered_map<string, string> _um;
};

int main(int argc, char *argv[])
{
    WordTrans wt;
    wt.buildMap("map.txt");
    wt.trans("file.txt");
    return 0;
}

