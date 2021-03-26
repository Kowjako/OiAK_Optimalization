#include "bsttree.h"

bstTree::bstTree()
{
    //ctor
}

bstTree::~bstTree()
{
    clearTree(root);
}

void bstTree::clearTree(nodeBST* root) {
    if(root!=NULL) {
        nodeBST* rightItem = root->rightItem;
        nodeBST* leftItem = root->leftItem;
        clearTree(rightItem);
        clearTree(leftItem);
        free(root);
        root = NULL;
    }
}

void bstTree::readFromFile(string filename) {
    int tmpSize = 0, tmpInput = 0;
    ifstream in(filename);
    if(in.is_open()) {
        in>>tmpSize;
        if(in.fail()) cout<<"Blad podczas odczytywania rozmiaru"<<endl;
        else {
            for(int i=0;i<tmpSize;i++) {
                in>>tmpInput;
                if(in.fail()) {
                    cout<<"Blad podczas odczytywania wartosci"<<endl;
                }
                else addValue(tmpInput);
            }
            in.close();
        }
    }
    else cout<<"Blad podczas otwierania pliku"<<endl;
}

nodeBST* bstTree::addNewNode(nodeBST* parent, int value) {
    nodeBST* tmpNode = (nodeBST*)malloc(sizeof(nodeBST));   //wydzielenie pamieci pod nowy wezel
    tmpNode->leftItem = NULL;   //nowy element nie ma potomkow
    tmpNode->rightItem = NULL;   //nowy element nie ma potomkow
    tmpNode->value = value;
    tmpNode->parentItem = parent;
    return tmpNode;
}

void bstTree::addValue(int value) {
    bool notInserted = true;
    if(root==NULL) {
        root = addNewNode(NULL, value); //tworzenie korzenia
        return;
    }
    nodeBST* tmpRoot = root;
    while(notInserted) {
        if(value >= tmpRoot->value) { //jest wiekszy od rodzica
            if(tmpRoot->rightItem!=NULL) {  //jezeli rodzic ma prawego potomka
                tmpRoot = tmpRoot->rightItem;     //ustawiamy nowego rodzica dla wstawianego wezla
            }
            else
            {
                tmpRoot->rightItem = addNewNode(tmpRoot,value);   //jezeli nie ma potomka wstawiamy nasz wezel
                notInserted = false;
            }
        }
        else  //przypadek gdy jest mniejszy od rodzica
        {
            if(tmpRoot->leftItem!=NULL) {
                tmpRoot = tmpRoot->leftItem;
            }
            else
            {
                tmpRoot->leftItem = addNewNode(tmpRoot, value);
                notInserted = false;
            }
        }
    }
}

void bstTree::showTree(nodeBST* root, long n) {
    if(root!=NULL)
    {
      showTree(root->rightItem, n+5);
      for (long i=0;i<n;i++) printf(" ");
      printf("%d\n", root->value);
      showTree(root->leftItem, n+5);
    }
}

void bstTree::showInorder(nodeBST* root) {
    if(root==NULL) return;
    showInorder(root->leftItem);
    cout<<root->value<<" ";
    showInorder(root->rightItem);
}

void bstTree::showPreorder(nodeBST* root) {
    if(root==NULL) return;
    cout<<root->value<<" ";
    showPreorder(root->leftItem);
    showPreorder(root->rightItem);
}

void bstTree::showPostorder(nodeBST* root) {
    if(root==NULL) return;
    showPostorder(root->leftItem);
    showPostorder(root->rightItem);
    cout<<root->value<<" ";
}
