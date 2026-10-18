#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 3
#define X 'x'
#define O 'o'

typedef struct{
    int player;
    int computer; 
    int draw;
    int no_playing;
} Score;

int difficulty;
Score score = {.player = 0, .computer = 0, .draw = 0, .no_playing = 0};

void input_difficulty(){
    while(1){
        printf("\n======= Tic-Tac-Toe Game =======");
        printf("\nSelect difficulty level:\n");
        printf("\n1. HUMAN (standard). \n2. GOD (Impossible to Win). \n3. Exit.\n");
        printf("\nEnter your Choice: ");
        scanf("%d", &difficulty);
        if (difficulty !=1 && difficulty !=2 && difficulty != 3){
            printf("\nIncorrect choice enter (1/2/3) !!\n");
        }else if(difficulty == 3){
            printf("\n.....Goodby.....\n");
            exit(0);
        }else {
            break;
        }
    };
}

void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void print_board(char board[max][max]){
    clear_screen();
    printf("\nScore Board \n1. Player X: %d \n2. Computer: %d \n3. Draws: %d\n4. No of Playing: %d\n",score.player,score.computer,score.draw,score.no_playing);
    printf("\n---- Tic-Tac-Toe Game ----\n");
    for(int i = 0; i < max; i++){
        printf("\n");
        for(int j = 0; j < max; j++){
            printf(" %c ",board[i][j]);
            if(j < max - 1){
                printf("|");
            }
        } 
        if(i < max - 1){
            printf("\n---+---+---");
        }
    }
    printf("\n\n");
}

int check_win(char board[max][max], char player){
    for(int i = 0; i < max; i++){
        if(board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return 1;
        } if(board[0][i] == player && board[1][i] == player && board[2][i] == player ){
            return 1;
        }
    }
    if((board[0][0]== player && board[1][1]== player &&board[2][2]== player)){
        return 1;
    } if(board[2][0]== player && board[1][1]== player &&board[0][2]== player){
        return 1;
    }
    return 0;
}

int check_draw(char board[max][max]){
    for(int i = 0; i < max; i++){
        for(int j = 0;j < max; j++){
            if(board[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
}

int is_valid_move(char board[max][max],int row, int col) {
    return !(row < 0 || col < 0 || 
            row > 2 || col > 2  || 
            board[row][col]!= ' ');
}

void player_move(char board[max][max]){
    int row, col;
    do {
        printf("\nPlayer X's turn.");
        printf("\nEnter row and column (1-3) for X: ");
        scanf("%d %d", &row, &col);
        row--;
        col--;
    } while (!is_valid_move(board, row, col));
    board[row][col] =X;
}

void computer_move(char board[max][max]){

    // 1. Play for immediate win
    for(int i = 0; i < max; i++){
        for(int j = 0; j < max; j++){
            if(board[i][j] == ' '){
                board[i][j] = O;
                if(check_win(board, O)){
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // 2. Block player's immediate win
    for(int i = 0; i < max; i++){
        for(int j = 0; j < max; j++){
            if(board[i][j] == ' '){
                board[i][j] = X;
                if(check_win(board, X)){
                    board[i][j] = O;
                    return;
                }
                board[i][j] = ' ';
            }
        }
    }

    // 3. GOD Mode Strategy
    if(difficulty == 2){

        // Play center
        if(board[1][1] == ' '){
            board[1][1] = O;
            return;
        }

        // Play opposite corner
        if(board[0][0] == X && board[2][2] == ' '){
            board[2][2] = O;
            return;
        }

        if(board[2][2] == X && board[0][0] == ' '){
            board[0][0] = O;
            return;
        }

        if(board[0][2] == X && board[2][0] == ' '){
            board[2][0] = O;
            return;
        }

        if(board[2][0] == X && board[0][2] == ' '){
            board[0][2] = O;
            return;
        }

        // Play any empty corner
        int corner[4][2] = {
            {0,0},
            {0,2},
            {2,0},
            {2,2}
        };

        for(int i = 0; i < 4; i++){
            int r = corner[i][0];
            int c = corner[i][1];

            if(board[r][c] == ' '){
                board[r][c] = O;
                return;
            }
        }
    }

    // 4. Play first available move
    for(int i = 0; i < max; i++){
        for(int j = 0; j < max; j++){
            if(board[i][j] == ' '){
                board[i][j] = O;
                return;
            }
        }
    }
}

void play_game(){
    score.no_playing++;
    char board[max][max]={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '},
    };
    print_board(board);
    char current_player =  rand() % 2 == 0 ? X : O;
    while (1){
        if (current_player == X){
            print_board(board);
            player_move(board);
            if (check_win(board, X)){
                score.player++;
                print_board(board);
                printf("Congratulation You have won the match.");
                break;
            }
            current_player =O;
        } else {
            computer_move(board);
            print_board(board);
            if (check_win(board, O)){
                score.computer++;
                print_board(board);
                printf("I won...!!!\nBut you played well....");
                break;
            }
            current_player = X;
        }
        if (check_draw(board)){
            score.draw++;
            print_board(board);
            printf("\nIts a draw.....");
            break;
        }
    }
    
}

int main() {
    srand(time(NULL));
    int choice;
    input_difficulty();
    do {
        play_game();
        printf("\nDo You want to play again ? (1 for yes and 0 for no): ");
        scanf("%d", &choice);
    } while(choice == 1);
    printf("Bye Bye, Thanks for Playing......");
    return 0;
}