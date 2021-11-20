#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cout << "ENTER NO. OF ROWS AND COLUMNS" << endl
         << endl;
    cin >> m >> n;
     int i, j, size = 0;
    int a[m][n];
    for (i = 0; i < m; i++) //Printing the Sparse Matrix
    {
        for (j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
   
    cout << "THE EARLIER REPRESENTATION OF YOUR SPARSE MATRIX IS -->" << endl;
    cout << "********************" << endl;
    for (i = 0; i < m; i++) //Printing the Sparse Matrix
    {
        for (j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    for (i = 0; i < m; i++) //Counting The Non Zero enteries in the Sparse Matrix
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
                size++;
        }
    }
    cout << endl;
    int k = 0;
    int b[3][size];         //Decalaring a matrix for new representation of sparse matrix
    for (i = 0; i < m; i++) //Printing the Sparse Matrix
    {
        for (j = 0; j < n; j++)
        {

            if (a[i][j] != 0)
            {

                b[0][k] = i;
                b[1][k] = j;
                b[2][k] = a[i][j];
                k++;
            }
        }
    }
    cout << "THE EFFICIENT REPRESENTATION OF YOUR SPARSE MATRIX IS -->" << endl;
    cout << "********************" << endl;
    int nn = 0;

    for (i = 0; i < 3; i++) //Printing The Non Zero enteries in the Sparse Matrix
    {
        for (j = 0; j < size; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;

    }
    return 0;
}