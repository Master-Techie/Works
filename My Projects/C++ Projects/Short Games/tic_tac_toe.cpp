#include <iostream>
using namespace std;

char arr[3][3];

int moves = 9;

void display(char a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j];
            if (j != 2) {cout << " | ";}
        }

        if (i != 2) {cout << "\n- - - - -";}

        cout << "\n";
    }

    cout << "\n";
}

bool if_x_is_winner(char a[3][3]) {
    if ((a[0][0] == 'x' && a[1][1] == 'x' && a[2][2] == 'x') || (a[2][0] == 'x' && a[1][1] == 'x' && a[0][2] == 'x')) {
        cout << "Player 1 wins.\n";
        return true;
    }

    for (int i = 0; i < 3; i++) {
        if ((a[0][i] == 'x' && a[1][i] == 'x' && a[2][i] == 'x') || (a[i][0] == 'x' && a[i][1] == 'x' && a[i][2] == 'x')) {
            cout << "Player 1 wins.\n";
            return true;
        }
    }

    return false;
}

bool if_o_is_winner(char a[3][3]) {
    if ((a[0][0] == 'o' && a[1][1] == 'o' && a[2][2] == 'o') || (a[2][0] == 'o' && a[1][1] == 'o' && a[0][2] == 'o')) {
        cout << "Player 2 wins.\n";
        return true;
    }

    for (int i = 0; i < 3; i++) {
        if ((a[0][i] == 'o' && a[1][i] == 'o' && a[2][i] == 'o') || (a[i][0] == 'o' && a[i][1] == 'o' && a[i][2] == 'o')) {
            cout << "Player 2 wins.\n";
            return true;
        }
    }

    return false;
}

int main(){
    cout << "Welcome to tic-tac-toe game!\n\n";
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = ' ';
        }
    }

    while (moves--) {
        int x;
        int y;

        cout << "Put x-coordinate of your position : ";
        cin >> x;
        
        cout << "Put y-coordinate of your position : ";
        cin >> y;

        cout << "\n";

        if (moves % 2 == 0) {
            arr[x][y]='x';

            display(arr);

            bool if_x_win = if_x_is_winner(arr);
            if (if_x_win == true) {return 0;}
        }

        else if (moves % 2 == 1) {
            arr[x][y]='o';

            display(arr);

            bool if_o_win = if_o_is_winner(arr);
            if (if_o_win == true) {return 0;}
        }
    }

    cout << "Draw";
}