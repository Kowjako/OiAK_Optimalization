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

nodeBST* bstTree::findElement(int element) {
    if(root==NULL) {
        return NULL;
    }
    else
    {
        nodeBST* tmpNode = root;
        while(tmpNode!=NULL) {
            if(element > tmpNode->value) {
                tmpNode = tmpNode->rightItem;
            }
            else
            {
                if(element<tmpNode->value) tmpNode = tmpNode->leftItem;
                    else
                    {
                        return tmpNode;
                    }
            }
        }
        return NULL;
    }
}

nodeBST* bstTree::getMaxNode(nodeBST* parent) {
    while(parent->rightItem!=NULL) {
        parent = parent->rightItem;
    }
    return parent;
}

void bstTree::deleteVertex(int value) {
    if(root == NULL) {
        cout<<"Drzewo BST nie ma wierzcholku"<<endl;
        return;
    }
    nodeBST* deletedNode = findElement(value);
    if(deletedNode!=NULL) {
        deletePtr(deletedNode);
    }
    else return;
}

void bstTree::deletePtr(nodeBST* deletedNode) {
    if(deletedNode->leftItem!=NULL && deletedNode->rightItem!=NULL) { /* kasowany wezel ma dwoch potomkow */
        nodeBST* maxLeftTreeNode = getMaxNode(deletedNode->leftItem); /* szukamy najwiekszy element w lewym potomnym drzewie */
        deletedNode->value = maxLeftTreeNode->value; /*zamieniamy wartosc usuwanego wezla na najwiekszy element w lewym potomnym */
        deletePtr(maxLeftTreeNode); /*kasujemy nawiekszy element w lewym potomnym drzewie rekursywnie */
        return; /* wychodzimy z funkcji zeby nie byl usuniety poczatkowy element za pomoca ostatniej linijki  free(deletedNode)*/
    }
    else
    {
        if(deletedNode->leftItem!=NULL) { /* ma tylko potomka po lewej */
            if(deletedNode==root) {
                nodeBST* newRoot = deletedNode->leftItem;
                free(root);
                root = newRoot;
                return;
            }
            else
            {
                if(deletedNode == deletedNode->parentItem->leftItem) { /* kasowany wezel jest dla rodzica lewym? */
                    deletedNode->parentItem->leftItem = deletedNode->leftItem;
                }
                else deletedNode->parentItem->rightItem = deletedNode->leftItem;
            }
        }
        else
        {
            if(deletedNode->rightItem!=NULL) { /* ma tylko potomka po prawej */
                if(deletedNode==root) {
                    nodeBST* newRoot = deletedNode->rightItem;
                    free(root);
                    root = newRoot;
                    return;
                }
                else
                {
                    if(deletedNode == deletedNode->parentItem->rightItem) { /* kasowany wezel jest dla rodzica prawym? */
                        deletedNode->parentItem->rightItem = deletedNode->rightItem;
                    }
                    else deletedNode->parentItem->leftItem = deletedNode->rightItem;
                }
            }
            else /*przypadek gdy nie ma potomkow czyli jest wiszacym */
            {
                if(deletedNode==root) {
                    free(root);
                    root = NULL;
                    return;
                }
                else {
                    if(deletedNode == deletedNode->parentItem->leftItem) { /*wiszacy wezel jest lewym odnosnie rodzica ? */
                        deletedNode->parentItem->leftItem = NULL;
                    }
                    else
                    {
                        deletedNode->parentItem->rightItem = NULL;
                    }
                }
            }
        }
    }
    free(deletedNode);
}

void

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
