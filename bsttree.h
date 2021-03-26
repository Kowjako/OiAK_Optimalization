#ifndef BSTTREE_H
#define BSTTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <fstream>

/* Struktura opisujaca pojedynczy wezel drzewa */
struct nodeBST {
    int value;  //klucz wezla
    nodeBST* parentItem;    //wskaznik na rodzica
    nodeBST* leftItem;  //wskaznik na lewego potomka
    nodeBST* rightItem;     //wskaznik na prawego potomka
};

using namespace std;

class bstTree
{
    public:
        bstTree();
        virtual ~bstTree();

        nodeBST* root = NULL; //korzen drzewa
        void addValue(int value); //dodanie elementu do drzewa
        nodeBST* addNewNode(nodeBST* parent, int value); //funkcja tworzenia nowego wierzcholku
        void deletePtr(nodeBST* deletedNode); //usuniecie wierzcholka poprzez jego wskaznik
        void deleteVertex(int value); //usuniecie wierzcholku poprzez jego wartosc
        nodeBST* getMaxNode(nodeBST* parent); //funkcja do szukania poprzednika
        nodeBST* findElement(int value); //funkcja wyszukiwania elementu w drzewie
        void showTree(nodeBST* startNode, long n); //funkcja wypisujaca drzewo w konsoli
        void readFromFile(string filename);  //funkcja wczytujaca drzewo z pliku.

        void showInorder(nodeBST* root);    //przejscie drzewa metoda INORDER
        void showPreorder(nodeBST* root);   //przejscie drzewa metoda PREORDER
        void showPostorder(nodeBST* root);    //prejscie drzewa metoda PREORDER

    protected:

    private:
        void clearTree(nodeBST* node); //funkcja usuwajaca drzewo
};

#endif // BSTTREE_H
