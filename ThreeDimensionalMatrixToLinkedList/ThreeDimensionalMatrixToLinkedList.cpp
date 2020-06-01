#include <bits/stdc++.h>
#include "Solution.cpp"

using namespace std;
// DON'T TOUCH THIS FILE. ASSESSMENT WILL REPLACE THIS FILE

void test_functionality(){
    vector<vector<vector<int> > > matrix = {
        {
            {1,2},
            {3,4}
        },
        {
            {5,6},
            {7,8}
        }
    };
    DirectionLinkedListNode* head= Solution().ThreeDimensionalMatrixToLinkedList(matrix,2,2,2);
    
    vector<int > output = {5, 5, 2, 2, 3, 3};
    vector<int > output1 = {6, 6, 1, 1, 4, 4};

    assert(head->val == 1);
    assert(head->extractNeighbors() == output);

    assert(head->right->val == 2);
    assert(head->right->extractNeighbors() == output1);

}

void print_2d_matrix(DirectionLinkedListNode * head, int rows, int cols)
{
    DirectionLinkedListNode * rest;
    for (int i = 0; i < rows; ++i) {
       rest = head->down;
       for (int j = 0; j < cols; ++j) {
	   vector<int > neighbors = head->extractNeighbors();
	   for(auto ne:neighbors)
	       cout<<ne<<" ";
	   cout<<"\n";
           head = head->right; 
       }
       head = rest;
    }
}

void printOutput(DirectionLinkedListNode* head,int layer,int row,int column)
{
    DirectionLinkedListNode * rest;

    for(int i=0;i<layer;i++)
    {
        rest = head->back;
        print_2d_matrix(head, row, column);
        head = rest;
    }
}

int main()
{
    test_functionality();
    int layer,row,column;
    cin>>layer>>row>>column;
    vector<vector<vector<int> > > a(layer,vector<vector<int > >(row,vector<int >(column)));
    for(int i=0;i<layer;i++)
    {
        for(int j=0;j<row;j++)
        {
            for(int k=0;k<column;k++)
            {
                cin>>a[i][j][k];
            }
        }
    }
    DirectionLinkedListNode* head = Solution().ThreeDimensionalMatrixToLinkedList(a,layer,row,column);
    printOutput(head,layer,row,column); 
    return 0;
}
