#include <iostream>
#include <string>

using namespace std;

class Grid{
    public:
        int Array[9];
        
        void Initialize(){
            for(int i = 0; i < 9; i++){
                Array[i] = 0;
            }
        }
        
        bool SetValue(int x, int y, bool XorY){
            int i = (x % 3) + (y * 3);
            int original = Array[i];
            Array[i] = (Array[i] == 0) ? XorY ? 1 : 2 : Array[i];
            return original != Array[i];
        }
        
        void Display(){
            for(int i = 0; i < 9; i++){
                cout << (NumToChar(Array[i]));
                if(i % 3 < 2) cout << "|";
                if(i % 3 == 2 && i < 6) cout << endl << "------" << endl;
            }
        }
        
        int CheckWin(){ //This function will return the player number who won, 0 if nobody has won, or -1 if its a catgame
            //Check Rows
            for(int i = 0; i < 3; i++){
                if(Array[0 + i] == Array[1 + i] && Array[1 + i] == Array[2 + i] && Array[0 + i] != 0) return Array[0 + i];
            }
            //Check Collumns
            for(int i = 0; i < 3; i++){
                if(Array[0 + i] == Array[3 + i] && Array[3 + i] == Array[6 + i] && Array[0 + i] != 0) return Array[0 + i];
            }
            //Check Diagonals
            if(Array[0] == Array[4] && Array[4] == Array[8] && Array[0] != 0) return Array[0];
            
            if(Array[2] == Array[4] && Array[4] == Array[6] && Array[2] != 0) return Array[2];
            
            //Check if full
            for(int i = 0; i < 9; i++) if(Array[i] == 0) return 0;
            
            //If we get to this point, its a catgame
            return -1;
        }
        
    private:
        char NumToChar(int num){
            switch(num){
                case 0: return ' ';
                case 1: return 'X';
                case 2: return 'Y';
            }
            
            return '?';
        }
};

int main()
{
    Grid MyGrid;
    MyGrid.Initialize();
    
    int turn = 0;
    bool active = true;
    
    do{
        MyGrid.Display();
        cout << endl; //Spacing after we display the grid
        cout << "It's player " << (turn % 2) + 1 << "'s turn" << endl;
        bool XorY = (turn % 2 == 0);
        
        int x,y;
        cout << "Where would you like to place? (type horizontal position then vertical seperated by a space, where 0,0 is top left)" << endl;
        cin >> x >> y;
        bool success = true; //Determines if the turn will pass based off if input is within range and not already taken
        if(x < 3 && y < 3 && x >= 0 && y >= 0){
            if(!MyGrid.SetValue(x,y,XorY)) success = false;
        } else success = false;
        if(!success){
            cout << "Please try again!" << endl;
        } else {
            
            int winner = MyGrid.CheckWin();
            
            if(winner > 0){
                MyGrid.Display();
                cout << "Player " << winner << " wins!" << endl;
                cout << "Would you like to play again? (Y or N)" << endl;
                char input;
                cin >> input;
                active = (input == 'Y');
            } else if(winner < 0) {
                MyGrid.Display();
                cout << "Catgame! Nobody wins" << endl;
                cout << "Would you like to play again? (Y or N)" << endl;
                char input;
                cin >> input;
                active = (input == 'Y');
            }
            
            turn++;
        }
        
    }while(active);

    return 0;
}
