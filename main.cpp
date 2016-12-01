#include <iostream>
#include <map>

using namespace std;

void help() {
    cout << "You must give some command to use this tool." << std::endl;
}

int main(int argc, char* argv[])
{
    int key;
    map<string, int> commandList = {
        {string("help"), 1},
        {string("procent"), 2},
    };

    if (argv[1] == 0) {
        help();
        return 0;
    }

    key = commandList[string(argv[1])];

    switch (key) {
        case 1:
            cout << "new help" <<endl;
            break;
        case 2:
            cout << "bla" <<endl;
            break;

        default:
            help();
    }

    return 0;
}
