// C++ program for implementation of 
// divide and conquer algorithm 
// to find a given key in a row-wise 
// and column-wise sorted 2D array 
#include<bits/stdc++.h>
#define ROW 4
#define COL 4
using namespace std;

// A divide and conquer method to 
// search a given key in mat[] 
// in rows from fromRow to toRow 
// and columns from fromCol to 
// toCol 
void search(int matrix[][], int fromRow, int toRow,
            int fromCol, int toCol, int x)
{
    // Find middle and compare with middle
    int i = fromRow + (toRow-fromRow )/2;
    int j = fromCol + (toCol-fromCol )/2;
    if (matrix[i][j] == x) // If x is present at middle
        cout << "Found " << x << " at " << i <<
             " " << j << endl;
    else
    {
        // right-up quarter of matrix is searched in all cases.
        // Provided it is different from current call
        if (i != toRow || j != fromCol)
            search(matrix, fromRow, i, j, toCol, x);

        // Special case for iteration with 1*2 matrix
        // matrix[i][j] and matrix[i][j+1] are only two elements.
        // So just check second element
        if (fromRow == toRow && fromCol + 1 == toCol)
            if (matrix[fromRow][toCol] == x)
                cout << "Found " << x << " at " <<
                     fromRow << " " << toCol << endl;

        // If middle x is lesser then search lower horizontal
        // matrix and right hand side matrix
        if (matrix[i][j] < x)
        {
            // search lower horizontal if such matrix exists
            if (i + 1 <= toRow)
                search(matrix, i + 1, toRow, fromCol, toCol, x);
        }

            // If middle x is greater then search left vertical
            // matrix and right hand side matrix
        else
        {
            // search left vertical if such matrix exists
            if (j - 1 >= fromCol)
                search(matrix, fromRow, toRow, fromCol, j - 1, x);
        }
    }
}

// Driver code

Stack Sort_Stack(Stack stack){
    Stack temp = new Stack();
    int prev = stack.pop();
    while(!stack.empty()){
        while(stack.top() < prev){
            stack.pop();
        }
        temp.push(prev);
        temp = stack.pop();
    }
    temp.push(prev);
    while(!temp.empty()){
        stack.push(temp.pop());
    }
    return stack;
}


void RemoveRow(node * L, int i){
    node * sumOfColumn = L;
    while(sumOfColumn.down != NULL){
        sumOfColumn = sumOfColumn.down;
    }
    node * temp = L;
    for(int j = 0; j<i ; j++){
        temp = temp.down;
    }
    while(temp != NULL){
        if(temp.up != NULL)
            temp.up.down = temp.down;

        if(temp.down != NULL)
            temp.down.up = temp.up;

        sumOfColumn.data -= temp.data;
        node * temp2 = temp;
        temp = temp.right;
        sumOfColumn = sumOfColumn.right;
        free(temp2);
    }
}
