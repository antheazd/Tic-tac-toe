// Tic tac toe game in C++ using terminal
#include <iostream>
using namespace std;

#define MaxPlaysNum 9
char field[3][3];  //game field

//initializing structure player
typedef struct{
    char name[10]; //players name string
    int points; //players current points
    int win; //player is a winner
    char sign; //x or o
    int index; 
}PlayerStructure;

//initializing player variables
void players_init(PlayerStructure *player1, PlayerStructure  *player2){
    player1->win = 0; //nobody is winner in the start
    player2->win = 0;
    player1->sign = 'X';
    player2->sign = 'O';
    player1->index = 1;
    player2->index = 2;
    cout << "How is player 1 called?\n";
    cin >> player1->name; 
    cout << "How is player 2 called?\n";
    cin >> player2->name; 
}

//function that draws game field
void field_draw(){
    cout << "\n     |     |     \n";
    cout << "  " << field[0][0] << "  |  " << field[0][1] << "  |  " << field[0][2] << "  \n"; 
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << field[1][0] << "  |  " << field[1][1] << "  |  " << field[1][2] << "  \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << field[2][0] << "  |  " << field[2][1] << "  |  " << field[2][2] << "  \n";
    cout << "     |     |     \n";
}

//draws x's and o's in their positions, if position isn't taken
int write_in_field(int x, int y, char player_sign){
    x--;
    y--;
   if((field[x][y] != 'X') && (field[x][y] != 'O')){
        field[x][y] = player_sign;
        field_draw();
        return 1;
   }
   else{
        cout << "Field already taken\n";
   }

   return 0;
}

//checks if the player has won
int is_winner(PlayerStructure *p){
    if(field[0][0] == p->sign && field[0][1] == p->sign && field[0][2] == p->sign){
        p->win = 1;
        return 1;
    }

    else if(field[1][0] == p->sign && field[1][1] == p->sign && field[1][2] == p->sign){
        p->win = 1;
        return 1;
    }

    else if(field[2][0] == p->sign && field[2][1] == p->sign && field[2][2] == p->sign){
        p->win = 1;
        return 1;
    }

    else if(field[0][0] == p->sign && field[1][0] == p->sign && field[2][0] == p->sign){
        p->win = 1;
        return 1;
    }

    else if(field[0][1] == p->sign && field[1][1] == p->sign && field[2][1] == p->sign){
        p->win = 1;
        return 1;
    }

    else if(field[0][2] == p->sign && field[1][2] == p->sign && field[2][2] == p->sign){
        p->win = 1;
        return 1;
    }

    else if(field[0][0] == p->sign && field[1][1] == p->sign && field[2][2] == p->sign){
        p->win = 1;
        return 1;
    }

    else if(field[0][2] == p->sign && field[1][1] == p->sign && field[2][0] == p->sign){
        p->win = 1;
        return 1;
    }

    return 0;
}

//print out who won
void winner_celebration(PlayerStructure *winner){
   cout << "\n----------------------\n";
   cout << "\n!!!PLAYER " << winner->name <<" HAS WON!!!!\n";
   cout << "\n----------------------\n";
   field_draw(); 
}

//close the game with no winner
void no_winner(){
    cout << "\n----------------------\n";
    cout << "\n!!!Tie!!!\n";
    cout << "Good luck next time\n";
    cout << "\n----------------------\n";
    field_draw();
}

//initilaizing empty char field
void field_init(){
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            field[i][j] = ' ';
        }
    }
}

//scan indexes of fields where player wants to put his sign input-> index + 1
//if an field is already used output text and scan until successful input
void scan_players_input(PlayerStructure *p){
    int x, y;
    int done = 0;
        do{
            done = 0;
            cout << "\n" << p->name << " chooses coordinates:\n";
            cin >> x >> y; //scan indexes
            if(!(x > 3 || x < 1 || y > 3 || y < 1)){     //check if an input is too big or small
                done = write_in_field(x, y, p->sign);    //if it isn't-write it in a field
            }
            else{
                printf("Incorrect input\n");
            }


        }while(done != 1);
}



int main()
{
    PlayerStructure player1structure, player2structure; // creating structure player
    PlayerStructure *player1, *player2;                 //initializing pointers on structures
    player1 = &player1structure;                        //initializing pointer to player 1
    player2 = &player2structure;
    players_init(player1, player2);                     //initializing pointer to player 2
    int plays_num = MaxPlaysNum;                        //max number of trials = 9

    while(plays_num > 0){

        scan_players_input(player1);                    
        plays_num--;
        if(is_winner(player1)){                         //exit the loop if there is already a winner
            winner_celebration(player1);                //print field and winner name
            break;
        }

        scan_players_input(player2);
        plays_num--;
        if(is_winner(player2)){
            winner_celebration(player2);
            break;
        }
    }
    if(plays_num == 9){                                 //print tie if there is no winner
            no_winner();
    }


    return 0;
}
