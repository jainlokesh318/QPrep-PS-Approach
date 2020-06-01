#include<bits/stdc++.h>
using namespace std;

class DirectionLinkedListNode {
public:
    int val;
    DirectionLinkedListNode *front;
    DirectionLinkedListNode *back;
    DirectionLinkedListNode *up;
    DirectionLinkedListNode *right;
    DirectionLinkedListNode *down;
    DirectionLinkedListNode *left;


    DirectionLinkedListNode(int x, DirectionLinkedListNode* f=NULL, DirectionLinkedListNode* b=NULL,
             DirectionLinkedListNode* u=NULL, DirectionLinkedListNode* r=NULL, DirectionLinkedListNode* d=NULL, DirectionLinkedListNode* l=NULL) {
        val = x;
        front = f;
        back = b;
        up = u;
        right = r;
        down = d;
        left = l;
    }
    vector<int> extractNeighbors()
    {
        vector<int > neighbour;
        // front back left right up down 
        neighbour.push_back(front->val);
        neighbour.push_back(back->val);
        neighbour.push_back(left->val);
        neighbour.push_back(right->val);
        neighbour.push_back(up->val);
        neighbour.push_back(down->val);
        return neighbour;
    }
};

class Solution{ 
    public:
        DirectionLinkedListNode* ThreeDimensionalMatrixToLinkedList(vector<vector<vector<int> > > mat,int layer,int row,int column)
        {
            vector<vector<vector<DirectionLinkedListNode*>>> a = 
                vector<vector<vector<DirectionLinkedListNode*>>>(layer, 
                    vector<vector<DirectionLinkedListNode*>>(row, vector<DirectionLinkedListNode*>(column)));

            for(int i = 0; i < layer; i++)
            {
                for(int j = 0; j < row; j++)
                {
                    for(int k = 0; k < column; k++)
                    {
                        DirectionLinkedListNode* newNode = new DirectionLinkedListNode(mat[i][j][k]);
                        a[i][j].push_back(newNode);
                    }
                }
            }
            //layers
            for(int i = 0; i < a.size(); i++)
            {
                //row
                for(int j = 0; j < a[i].size(); j++)
                {
                    //column
                    for(int k = 0; k < a[i][j].size(); k++)
                    {
                        //populate front
                        if(i-1 < 0)
                            a[i][j][k]->front = a[layer-1][j][k];
                        else
                            a[i][j][k]->front = a[i-1][j][k];
                        
                        //populate back
                        if(i+1 >= layer)
                            a[i][j][k]->back = a[0][j][k];
                        else
                            a[i][j][k]->back = a[i+1][j][k];
                        
                        //populate left
                        if(k-1 < 0)
                            a[i][j][k]->left = a[i][j][column-1];
                        else
                            a[i][j][k]->left = a[i][j][k-1];

                        //populate right
                        if(k+1 >= column)
                            a[i][j][k]->right = a[i][j][0];
                        else
                            a[i][j][k]->right = a[i][j][k+1];
                        
                        //populate up
                        if(j-1 < 0)
                            a[i][j][k]->up = a[i][row-1][k];
                        else
                            a[i][j][k]->up = a[i][j-1][k];

                        //populate down
                        if(j+1 >= row)
                            a[i][j][k]->down = a[i][0][k];
                        else
                            a[i][j][k]->down = a[i][j+1][k];
                            
                    }
                }
            }
            return a[0][0][0];
        }  
};
