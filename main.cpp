#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

char places [9]= {'1','2','3','4','5','6','7','8','9'};

void board(){
    cout << "\tTIC-TAC-TOE Game\n";
    cout << "Player 1 - X\tPlayer 2 - O\n";
    cout << " " << places[0] << " | " << places[1] << " | "<< places[2];
    cout << "\n-----------\n";
    cout << " " << places[3] << " | " << places[4] << " | "<< places[5];
    cout << "\n-----------\n";
    cout << " " << places[6] << " | " << places[7] << " | "<< places[8];
    
}

bool winner(){
    //return true if 3 in a row
    //false if no winner

    if(places[0] == places[1] && places[1] == places[2]){
        return true;
    }else if(places[3] == places[4] && places[4] == places[5]){
        return true;
    }else if(places[6] == places[7] && places[7] == places[8]){
        return true;
    }else if(places[0] == places[3] && places[3] == places[6]){
        return true;
    }else if(places[1] == places[4] && places[4] == places[7]){
        return true;
    }else if(places[2] == places[5] && places[5] == places[8]){
        return true;
    }else if(places[0] == places[4] && places[4] == places[8]){
        return true;
    }else if(places[6] == places[4] && places[4] == places[2]){
        return true;
    }else{
        return false;
    }

}

bool testchoice(int pick){
    if (pick > 10 || pick < 0){
        //INVALID Choice
        cout << "\nInvalid choice!";
        return false;
    }else if(places[pick-1] == 'X' || places[pick-1] == 'O'){
        cout << "\nPlacement already picked.";
        return false;
    }else{
        return true;
    }
}

int main(){
    board();
    int player = 1;
    int choice;
    int count = 1;
    while (winner() == false && count < 10){
        if (player == 1){
            cout << "\nPlayer 1, choose location: ";
            cin >> choice;
            while (!testchoice(choice)){
                cout << "\nTry again: ";
                cin >> choice;
            }
            places[choice-1] = 'X';
        }else{
            cout << "\nPlayer 2, choose location: ";
            cin >> choice;
            while (!testchoice(choice)){
                cout << "\nTry again: ";
                cin >> choice;
            }
            places[choice-1] = 'O';
        }
        
        //switch to next player
        player = player % 2 + 1;
        board();
        count++;
    }

    if (winner()){
        cout << "\nPlayer " << player % 2 + 1 << " is the winner!!";
        
    }else{
        cout << "\nTIE GAME!";

    }

   
    

    return 0;
}