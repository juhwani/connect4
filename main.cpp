#include <iostream>
#include <random>

using namespace std;
int player = 1;
const int rows = 6;
const int cols = 7;
bool done = true;
int board[6][7];
int visited[6][7];
int input;

int init(){
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            board[r][c] = 0;
            visited[r][c] = false;
        }
    }
    return -1;
}

int ldfs(int r, int c, int p){
    if (board[r][c-1] == p && r < rows && c < cols && !visited[r][c]){
        visited[r][c] = true;
        return 1 + ldfs(r,c-1,p);
}
    return 0;
}
int rdfs(int r, int c, int p){
    if (board[r][c+1] == p && r < rows && c < cols && !visited[r][c]){
        visited[r][c] = true;
        return 1 + rdfs(r,c+1,p);
    }
    return 0;
}
int udfs(int r, int c, int p){
    if (board[r+1][c] == p && r < rows && c < cols && !visited[r][c]){
        visited[r][c] = true;
        return 1 + udfs(r+1,c,p);
    }
    return 0;
}
int ddfs(int r, int c, int p){
    if (board[r-1][c] == p && r < rows && c < cols && !visited[r][c]){
        visited[r][c] = true;
        return 1 + ddfs(r-1,c,p);
    }
    return 0;
}
int dudfs(int r, int c, int p){
    if (board[r+1][c+1] == p && r < rows && c < cols && !visited[r][c]){
        visited[r][c] = true;
        return 1 + dudfs(r+1,c+1,p);
    }
    return 0;
}
int dddfs(int r, int c, int p){
    if (board[r-1][c-1] == p && r < rows && c < cols && !visited[r][c]){
        visited[r][c] = true;
        return 1 + dddfs(r-1,c-1,p);
    }
    return 0;
}
int drdfs(int r, int c, int p){
    if (board[r-1][c+1] == p && r < rows && c < cols && !visited[r][c]){
        visited[r][c] = true;
        return 1 + drdfs(r-1,c+1,p);
    }
    return 0;
}
int dldfs(int r, int c, int p){
    if (board[r+1][c-1] == p && r < rows && c < cols && !visited[r][c]){
        visited[r][c] = true;
        return 1 + dldfs(r+1,c-1,p);
    }
    return 0;
}

int AI(){
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1.0, 7.0);

    return dist(mt);
}

void draw(){
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            cout<<board[r][c]<<" ";
            visited[r][c] = false;
        }
        cout<<'\n';
    }

}

int choose(){
    int pmode = 0;
    cout << "Please Enter Your Choice:\n"<<"1. PvP\n2. Dummy Bot\n";
    cin >> pmode;
    switch(pmode){
        case 1:
            while (done) {
                cout << "Player: " << player << " Enter from 1 - 7:\n";
                cin >> input;

                input--;
                cout << "\nThis is the input: " << input <<"\n";
                if (board[0][input] != 0){
                    cout << "Full Column please select another number\n";
                    draw();
                    continue;
                }

                int count = 0;

                while (count < 6) {
                    if (board[count][input] != 0){
                        break;
                    }
                    count++;
                }

                board[count-1][input] = player;

                if (ldfs(count-1,input,player) > 2 ||
                    rdfs(count-1,input,player) > 2 ||
                    udfs(count-1,input,player) > 2 ||
                    ddfs(count-1,input,player) > 2 ||
                    dudfs(count-1,input,player) > 2 ||
                    dddfs(count-1,input,player) > 2 ||
                    drdfs(count-1,input,player) > 2 ||
                    dldfs(count-1,input,player) > 2 ){
                    draw();
                    cout << "Game Over! Player: " << player << " wins";
                    return -1;
                }
                draw();
                if (player == 1){
                    player = 2;
                }
                else{
                    player = 1;
                }
            }
        case 2:
            while (done) {

                if (player == 1){
                    cout << "Player: " << player << " Enter from 1 - 7:\n";
                    cin >> input;
                }
                else {
                    input = AI();
                }
                input--;
                cout << "\nThis is the input: " << input <<"\n";
                if (board[0][input] != 0){
                    cout << "Full Column please select another number\n";
                    draw();
                    continue;
                }

                int count = 0;

                while (count < 6) {
                    if (board[count][input] != 0){
                        break;
                    }
                    count++;
                }

                board[count-1][input] = player;

                if (ldfs(count-1,input,player) > 2 ||
                    rdfs(count-1,input,player) > 2 ||
                    udfs(count-1,input,player) > 2 ||
                    ddfs(count-1,input,player) > 2 ||
                    dudfs(count-1,input,player) > 2 ||
                    dddfs(count-1,input,player) > 2 ||
                    drdfs(count-1,input,player) > 2 ||
                    dldfs(count-1,input,player) > 2 ){
                    draw();
                    if (player == 0){
                    cout << "Game Over! Player: " << player << " wins";}
                    else {
                        cout << "Game Over! A dummy bot just beat you.";
                    }
                    return -1;
                }
                draw();

                if (player == 1){

                    player = 2;
                }
                else{
                    cout << "Bot just played " << input + 1<< "\n";
                    player = 1;
                }
            }

    }


}


int main() {
    init();
    draw();
    choose();
    return 0;
}
