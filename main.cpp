#include <iostream>
#include <map>

using namespace std;

void help()
{
    cout << "You must give some command to use this tool." << endl << endl;
    cout << "Usage: percent {command} {int arguments}" << endl << endl;
    cout << "Commands:" << std::endl;
    cout << "    pfn {value, percent} - percent from number, calculate percentage value from given number" << endl;
    cout << "    nfp {value, percent value} - number from percent, calculate number value from given percent" << endl;
    cout << "    fuel {fuel consumed, distance} - calculate middle fuel consumption for unit of distance" << endl;
    cout << "    pi {bigger value, lower value} - percentage increase form given values" << endl;
    cout << "    pd {lower value, bigger value} - percentage decrease form given values" << endl;
}

double pfn(char* argv[])
{
    if (argv[2] == 0 && argv[3] == 0) {
        help();
        exit(0);
    }

    return (atof(argv[2]) / 100) * atof(argv[3]);
}

double nfp(char* argv[])
{
    if (argv[2] == 0 && argv[3] == 0) {
        help();
        exit(0);
    }

    return (atof(argv[3]) / atof(argv[2])) * 100;
}

double pi(char* argv[])
{
    if (argv[2] == 0 && argv[3] == 0) {
        help();
        exit(0);
    }

    return ((atof(argv[2]) - atof(argv[3])) / atof(argv[3])) * 100;
}

double pd(char* argv[])
{
    if (argv[2] == 0 && argv[3] == 0) {
        help();
        exit(0);
    }

    return ((atof(argv[3]) - atof(argv[2])) / atof(argv[3])) * 100;
}

int main(int argc, char* argv[])
{
    int key;
    map<string, int> commandList = {
        {string("pfn"), 1},
        {string("nfp"), 2},
        {string("fuel"), 3},
        {string("pi"), 4},
        {string("pd"), 5},
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
            cout << nfp(argv) << "%" << endl;
            break;
        case 3:
            cout << nfp(argv) << "l" << endl;
            break;
        case 4:
            cout << pi(argv) << "%" << endl;
            break;
        case 5:
            cout << pd(argv) << "%" << endl;
            break;

        default:
            help();
    }

    return 0;
}
