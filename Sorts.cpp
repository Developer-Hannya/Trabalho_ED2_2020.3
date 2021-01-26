#include "Sorts.h"
#include "Node.h"

Sorts::Sorts(){}

Sorts::~Sorts(){}

void Sorts::auxMergeSortCovidDatabyDate(vector<CovidData> &data, int init,int mid, int end)
{
    int i = init;
    int j = mid;
    vector<CovidData> aux;

    while(i < mid && j < end)
    {
        if(data[i].getDate() > data[j].getDate())
        {
            aux.push_back(data[i]);
            i++;
        }
        else
        {
            aux.push_back(data[j]);
            j++;
        }
    }

    while (i < mid)
    {
        aux.push_back(data[i]);
        i++;
    }
    while (j < end)
    {
        aux.push_back(data[j]);
        j++;
    }
    
    for(int k = init; k < end;k++)
    {
        data[k] = aux[k - init];
    }
}

void Sorts::mergeSortCovidDatabyDate(vector<CovidData> &data,int init,int end)
{
    if(init < end - 1)
    {
        int mid = (init + end)/2;
        mergeSortCovidDatabyDate(data,init,mid);
        mergeSortCovidDatabyDate(data,mid,end);
        auxMergeSortCovidDatabyDate(data,init,mid,end);
    }
}

void Sorts::auxMergeSortCovidDatabyCityStatePair(vector<CovidData> &data,int init,int mid,int end)
{
    int i = init;
    int j = mid;
    vector<CovidData> aux;

    while(i < mid && j < end)
    {
        if(data[i].getStateInitials() + data[i].getCityName() < data[j].getStateInitials() + data[j].getCityName())
        {
            aux.push_back(data[i]);
            i++;
        }
        else
        {
            aux.push_back(data[j]);
            j++;
        }
    }

    while (i < mid)
    {
        aux.push_back(data[i]);
        i++;
    }
    while (j < end)
    {
        aux.push_back(data[j]);
        j++;
    }
    
    for(int k = init; k < end;k++)
    {
        data[k] = aux[k - init];
    }
}

void Sorts::mergeSortCovidDatabyCityStatePair(vector<CovidData> &data,int init,int end)
{
    if(init < end - 1)
    {
        int mid = (init + end)/2;
        mergeSortCovidDatabyCityStatePair(data,init,mid);
        mergeSortCovidDatabyCityStatePair(data,mid,end);
        auxMergeSortCovidDatabyCityStatePair(data,init,mid,end);
    }
}

void Sorts::convertCumulativeToDiary(vector<CovidData> &data)
{
    int previousCaseCount = data[0].getCaseCount();
    int previousDeathCount = data[0].getDeathCount();
    for(int i = 1;i < data.size();i++)
    {
        int auxCase = previousCaseCount;
        int auxDeath = previousDeathCount;
        previousCaseCount = data[i].getCaseCount();
        previousDeathCount = data[i].getDeathCount();

        if(data[i - 1].getCityCode() == data[i].getCityCode())
        {
            data[i].setCaseCount(data[i].getCaseCount() - auxCase);
            data[i].setDeathCount(data[i].getDeathCount() - auxDeath);
        }
        else
        {
            continue;
        }   
    }
}

void Sorts::preProcessCovidData(vector<CovidData> &data)
{
    mergeSortCovidDatabyDate(data,0,data.size() - 1);
    mergeSortCovidDatabyCityStatePair(data,0,data.size() - 1);
    convertCumulativeToDiary(data);
}

// aqui para baixo são as funções do Tree Sort

Node Sorts::newNode(vector<CovidData> &data){
    Node *n = new Node;
    n->chave = data;
    n->left = n->rght = NULL;
    return n;
}

/*
void storeSorted(Node *root, int arr[], int &i) 
{ 
    if (root != NULL) 
    { 
        storeSorted(root->left, arr, i); 
        arr[i++] = root->key; 
        storeSorted(root->right, arr, i); 
    } 
} 
*/

void Sorts::storeTreeSorted(Node *raiz, vector<CovidData> &data, int n) {
    if(raiz != NULL) {
        storeTreeSorted(raiz->left, data, n);
        vector<CovidData>[n++] = raiz->chave;
        storeTreeSorted(raiz->rght, data, n);
    }
}

/*
    Node* insert(Node* node, int key) 
    { 
        /If the tree is empty, return a new Node
        if (node == NULL) return newNode(key); 
  
        /Otherwise, recur down the tree 
        if (key < node->key) 
            node->left  = insert(node->left, key); 
        else if (key > node->key) 
            node->right = insert(node->right, key); 
  
        /return the (unchanged) Node pointer
        return node; 
    }    
    */

Node* Sorts::insertNode(Node* node, vector<CovidData> &data) {
    if(node == NULL) {
        return newNode(data);
    }
    else {
        if(data < node->data) {
            node->left = insertNode(node->left, data);
        }
        else if(data > node->data) {
            node->rght = insertNode(node->rght, data);
        }
    }
    return node;
}

/*
void treeSort(int arr[], int n) 
{ 
    struct Node *root = NULL; 
  
    // Construct the BST 
    root = insert(root, arr[0]); 
    for (int i=1; i<n; i++) 
        root = insert(root, arr[i]); 
  
    // Store inoder traversal of the BST 
    // in arr[] 
    int i = 0; 
    storeSorted(root, arr, i); 
} 
*/

void Sorts::treeSort(vector<CovidData> &data, int sizi) {
    Node *raiz = NULL;
    raiz = insertNode(raiz, data[0]);
    for (int i = 1; i < sizi; i++) {
        raiz = insertNode(raiz, data[i]);
    }
    int j = 0;
    storeTreeSorted(raiz, data, j);
}