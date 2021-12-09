#include <bits/stdc++.h>
#include <conio.h> 
#include <iomanip> 

using namespace std;

bool isMoveAllowed(int i, int j, int mkey) {
    if (mkey == 77) // right arrow
    {
        if ( j - 1 >= 0) {
            return true;
        } else {
            return false;
        }
    }
    else if (mkey == 80) // down arrow
    {
        if ( i - 1 >= 0 ) {
            return true;
        }
        else 
        {
            return false;
        }
    }
    else if (mkey == 75) // left arrow
    {
        if ( j + 1 <= 3 ) {
            return true;
        }
        else 
        {
            return false;
        }
    }
    else if (mkey == 72) // up arrow
    {
        if ( i + 1 <= 3 ) {
            return true;
        }
        else 
        {
            return false;
        }
    } else {
        return false;
    }
}

int main()
{

    int arr[4][4] ={
        {1, 2, 3, 4},
        {9, 10, 11, 12},
        {5, 6, 7, 8},
        {13, 14, 15, 0}};

    int pi=3,pj=3;

    int mkey;

    
    do
    {
        system("cls");

        //table printing
        for (int i = 0; i <= 3; i++)
        {
            cout << setw(3);
            for (int j = 0; j <= 3; j++)
            {
                if ( arr[i][j] != 0) {
                    cout << arr[i][j] << setw(5);
                } else {
                    cout << (char)254 << setw(5);
                }
            }
            cout << endl<< endl;
        }

        cout << "--------------------\n" << "Esc - Exit the game."<<endl;
        cout<<"Arrange all numbers in a sequence"<<endl;

        mkey = getch();
        // cout << mkey << endl;

        if (mkey == 75 || mkey == 72 || mkey == 77 || mkey == 80)
        {
            // cout << "allowed\n";
            bool isAllowed = isMoveAllowed( pi, pj, mkey);
            if ( isAllowed == false ) {
                continue;
            }

            if ( mkey == 77 ) // right arrow 
            {
                arr[pi][pj] = arr[pi][pj-1];
                arr[pi][pj-1] = 0;
                pj--;
            } else if ( mkey == 80 ) // down arrow
            {
                arr[pi][pj] = arr[pi-1][pj];
                arr[pi-1][pj] = 0;
                pi--;
            } else if ( mkey == 75 ) // left arrow
            {
                arr[pi][pj] = arr[pi][pj+1];
                arr[pi][pj+1] = 0;
                pj++;
            } else if ( mkey == 72 ) // up arrow
            {
                arr[pi][pj] = arr[pi+1][pj];
                arr[pi+1][pj] = 0;
                pi++;
            }
        }
    } while(mkey != 27);

    return 0;


}

