#include <iostream>
using namespace std;

struct Vector2 {
    int X;
    int Y;
} ;

void PrintGrid(int arr[9]);
bool Place(int arr[9], Vector2 vec, int t);
int VecToInd(Vector2 vec);
int CheckWin(int arr[9]);
Vector2 IndToVec(int index);

int main()
{
    bool Playing = true;
    int XorO = 0;
    int arr[9];
    int winner = -1;
    do{
        PrintGrid(arr); // Print the grid
        
        bool Valid = false;
        
        do {
            int row;
            int col;
            char c = XorO == 0 ? 'X' : 'O';
            //Get Coords
            cout << "Where would you like to place an " << c << "? Row (Horizontal) ?:" << endl;
            cin >> row;
            cout << "Where would you like to place an " << c << "? Collumn (Vertical) ?:" << endl;
            cin >> col;
        
            Vector2 vec = {row, col};
        
            Valid = Place(arr, vec,  XorO + 1);
        
        } while(Valid == false);
        
        XorO = (XorO + 1) % 2;
        
        int num1 = CheckWin(arr);
        cout << num1 << endl;
        if(num1 != 0 || num1 == -1){
            winner = num1;
            Playing = false;
        }
        
    } while(Playing);
    
    PrintGrid(arr);
    
    if(winner == 0){
        cout << "X wins!";
    } else if (winner == 1){
        cout << "O wins!";
    } else if (winner == -1){
        cout << "Tie!";
    }
    cout << endl <<"Thanks for playing!";

    return 0;
}

int VecToInd(Vector2 vec){
    return (vec.X - 1) + ((vec.Y - 1) * 3);
}

Vector2 IndToVec(int index){
    return {(index % 3) + 1, (index / 3) + 1};
}

bool Place(int arr[9], Vector2 vec, int t){
    int index = VecToInd(vec);
    if(index < 0 || index > 8){
        cout  << "Try again! Out of bounds" << endl;
        return false;
    }
    if(arr[index] != 0) {
        cout  << "Try again! Spot is taken" << endl;
        return false;
    }
    arr[index] = t;
    return true;
}

void PrintGrid(int arr[9]){
    for(int i = 0; i < 3; i++) { // Prints the first line
        cout << (arr[i] != 0 ? arr[i] == 1 ? 'X' : 'O' : ' ');
        if(i < 2) cout << "|";
        else if (i == 2) cout << endl;
    }
    cout << "------" << endl; // Spacer line
    for(int i = 3; i < 6; i++) { // Prints the second line
        cout << (arr[i] != 0 ? arr[i] == 1 ? 'X' : 'O' : ' ');
        if(i < 5) cout << "|";
        else if (i == 5) cout << endl;
    }
    cout << "------" << endl; // Spacer line
    for(int i = 6; i < 9; i++) { // Prints the third line
        cout << (arr[i] != 0 ? arr[i] == 1 ? 'X' : 'O' : ' ');
        if(i < 8) cout << "|";
        else if (i == 8) cout << endl;
    }
    cout << endl;
}

int CheckWin(int arr[9]){
    bool full = true;
    for(int i = 0; i < 9; i++){
        
        if(arr[i] != 0){
           
            Vector2 vec = IndToVec(i);
            if(vec.X == 1){ // Check Horizontals
               if(arr[i] == arr[i + 1] && arr[i] == arr[i + 2]) { 
                    /*cout << arr[i] << endl;
                    cout << arr[i + 1] << endl;
                    cout << arr[i + 2] << endl;*/
                    cout << "Win!" << endl;
                    return arr[i];
               }
            }
            
            if(vec.Y == 1){ // Check Verticals
               if(arr[i] == arr[i + 3] && arr[i] == arr[i + 6]) { 
                   /* cout << arr[i] << endl;
                    cout << arr[i + 3] << endl;
                    cout << arr[i + 6] << endl;*/
                    cout << "Win!" << endl;
                    return arr[i];
               }
            }   
            
             // Check \ Diag
               if(arr[0] == arr[4] && arr[4] == arr[8] && arr[4] != 0) { 
                   /* cout << arr[i] << endl;
                    cout << arr[i + 3] << endl;
                    cout << arr[i + 6] << endl;*/
                    cout << "Win!" << endl;
                    return arr[i];
               }
               
             // Check / Diag
               if(arr[2] == arr[4] && arr[4] == arr[6] && arr[4] != 0) { 
                   /* cout << arr[i] << endl;
                    cout << arr[i + 3] << endl;
                    cout << arr[i + 6] << endl;*/
                    cout << "Win!" << endl;
                    return arr[i];
               }
            
            
        } else {
            full = false;
        }
        
    }
    
    return 0;
}




