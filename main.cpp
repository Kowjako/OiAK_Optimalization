#include <iostream>
#include <windows.h>
#include "bsttree.h"

using namespace std;

long long int frequency, start, elapsed;
bstTree tree;

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

int main()
{
    int operationNumber;
    double sum = 0;
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);
    do {
        cout<<"1. Wypelnij drzewo"<<endl;
        cout<<"2. Pomiar czasu dodania"<<endl;
        cout<<"3. Pomiar czasu usuwania"<<endl;
        cout<<"4. Pomiar czasu wyszukiwania"<<endl;
        cout<<"5. Rownowazenie drzewa"<<endl;
        cout<<"6. Zakoncz program"<<endl;
        cin>>operationNumber;
        switch(operationNumber) {
            case 1:
                    int n;
                    cout<<"Wprowadz liczbe wierzcholkow"<<endl;
                    cin>>n;
                    for(int i=0;i<n;i++) {
                        tree.addValue(rand()%32000);
                    }
                    break;
            case 2:
                    sum = 0;
                    for(int i=0;i<100;i++) {
                        start = read_QPC();
                        tree.addValue(rand()%32000);
                        elapsed = read_QPC() - start;
                        sum+=elapsed;
                    }
                    cout << "Time [us] = "<< (1000000.0 * sum)/(frequency*100)<<endl;
                    break;
            case 3:
                    sum = 0;
                    for(int i=0;i<100;i++) {
                        start = read_QPC();
                        tree.deleteVertex(rand()%32000);
                        elapsed = read_QPC() - start;
                        sum+=elapsed;
                    }
                    cout << "Time [us] = "<< (1000000.0 * sum)/(frequency*100)<<endl;
                    break;
            case 4:
                    sum = 0;
                    for(int i=0;i<100;i++) {
                        start = read_QPC();
                        tree.findElement(rand()%32000);
                        elapsed = read_QPC() - start;
                        sum+=elapsed;
                    }
                    cout << "Time [us] = "<< (1000000.0 * sum)/(frequency*100)<<endl;
                    break;
            case 5:
                    tree.algorithmDSW();
                    break;
            default:
                    break;
        }
    }
    while(operationNumber!=6);

	return(0);
}
