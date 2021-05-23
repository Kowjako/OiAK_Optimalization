
#include <iostream>

#include <windows.h>
#include "bsttree.h"
using namespace std;

long long int read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

long long int frequency, start, elapsed;

int main()
{
    QueryPerformanceFrequency((LARGE_INTEGER*)&frequency);

    bstTree tree;
    tree.addValue(12);
    tree.addValue(6);
    tree.addValue(17);
    tree.addValue(3);
    tree.addValue(7);
    tree.addValue(1);
    tree.addValue(4);
    tree.addValue(9);
    tree.addValue(11);
    tree.addValue(15);
    tree.addValue(22);
    tree.addValue(13);
    tree.addValue(16);
    tree.addValue(20);
    tree.addValue(30);
    cout<<endl;
    tree.algorithmDSW();
    cout<<endl;
    tree.showTree(tree.root,0);
    if(tree.findElement(15));
    cout<<endl;
    cout<<endl;
    cout<<"Element 15 znaleziony"<<endl;
    return 0;
}
