#include <iostream>
#include <map>

using namespace std;

void help()
{
    cout << "You must give some command to use this tool." << std::endl << std::endl;
    cout << "Usage: percent {command} {int arguments}" << std::endl << std::endl;
    cout << "Commands:" << std::endl;
    cout << "    pfn {value, percent} - percent from number, calculate percentage value from given number" << std::endl;
    cout << "    nfp {value, percent} - number from percent, " << std::endl;
}

double pfn(char* argv[])
{
    if (argv[2] == 0 && argv[3] == 0) {
        help();
        exit(0);
    }

    return (atof(argv[2]) / 100) * atof(argv[3]);
}

int main(int argc, char* argv[])
{
    int key;
    map<string, int> commandList = {
        {string("pfn"), 1},
        {string("nfp"), 2},
    };

    if (argv[1] == 0) {
        help();
        return 0;
    }

    key = commandList[string(argv[1])];

    switch (key) {
        case 1:
            cout << pfn(argv) << endl;
            break;
        case 2:
            cout << "bla" <<endl;
            break;

        default:
            help();
    }

    return 0;
}
