include <stdio.h>

#define WIN_SCORE 21
#define table_w 80;
#define table_h  25;
#define racket_size  3;
#define racket_1_y 9;
#define racket_2_y 9;


void ballRacketMovement();
void drawField(int ball_x, int ball_y, int racket_1_x, int racket_1_y, int racket_2_x, int racket_2_y, int racket_size, int ball_start_x, int ball_start_y, int table_h, int table_w);
void cleanScreen();

int main(){
    int score_p1 = 0;// Change
    int score_p2 = 0;// Change


    while (score_p1 < WIN_SCORE && score_p2 < WIN_SCORE) {
        drawField(int ball_x, int ball_y, int racket_1_x, int racket_1_y, int racket_2_x, int racket_2_y, int racket_size, int ball_start_x, int ball_start_y, int table_h, int table_w);
        printf("Player 1: %d | Player 2: %d\n", score_p1, score_p2);

        char move1 = getchar();
        char move2 = getchar();

        ballRacketMovement();
        cleanScreen();
    }

    if (score_p1 == WIN_SCORE) {
        printf("Player 1 wins!\n");
    } 
    if (score_p2 == WIN_SCORE) {
        printf("Player 2 wins!\n");
    }

    return 0;
}


void drawField(int ball_x, int ball_y, int racket_1_x, int racket_1_y, int racket_2_x, int racket_2_y, int racket_size, int ball_start_x, int ball_start_y, int table_h, int table_w) {
    for (int i = 0; i < table_h; i++) {
        for (int j = 0; j < table_w; j++) {
            if (i == 0 || i == table_h - 1) {
                // Верхняя и нижняя линии
                printf("-");
            } else if (j == 0 || j == table_w - 1) {
                // Боковые грани
                printf("|");
            } else if ((j >= racket_1_x && j < racket_1_x + racket_size && i >= racket_1_y && i < racket_1_y + racket_size) ||
                       (j >= racket_2_x && j < racket_2_x + racket_size && i >= racket_2_y && i < racket_2_y + racket_size)) {
                // Ракетки
                printf("|");
            } else if (j == ball_x && i == ball_y) {
                // Мяч
                ball_x = ball_start_x;
                ball_y = ball_start_y;
                printf("O");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
 void ballRacketMovement() {
    char player_in;
    int racket_1_y, racket_2_y, racket_1_x, racket_2_x, table_h, ball_y, ball_x, move_ball_x, move_ball_y, table_w, racketstart_1_x, racketstart_2_x, 
    racketstart_1_y, racketstart_2_y, ball_start_x, ball_start_y, score_p1, score_p2;
    
    
    while(1)
    {
        player_in = getchar();
        if (( player_in == 'a' || player_in == 'z' || player_in == 'k' || player_in == 'm' || player_in == ' ') && player_in != '\n') 
        {
            if (ball_y == 1 || ball_y == table_h) {
            move_ball_y *= -1;
            }
            ball_x += move_ball_x;
            ball_y += move_ball_y;

            switch (player_in = getchar)
            {
                case 'a': // Игрок 1 верх предел
                    if ((racket_1_y + 2) != table_h)
                    {
                        racket_1_y++;
                    }
                    racket_1_y;
                    break;
                case 'z': // Игрок 1 низ предел
                    if ((racket_1_y - 2) != 0)
                    {
                        racket_1_y--;
                    }
                    racket_1_y;
                    break;
                case ' ': // Игрок пропускает ход
                    racket_1_y;
                    break;
                case 'k': // Игрок 2 вверх предел
                    if ((racket_2_y + 2) != table_h)
                    {
                        racket_2_y++;
                    }
                    racket_2_y;
                    break;
                case 'm': // Игрок 2 вниз предел
                    if ((racket_2_y - 2) != 0)
                    {
                        racket_2_y--;
                    }
                    racket_2_y;
                    break;
            }
    
        }   

     if ((((ball_y == racket_1_y - 1) || (ball_y == racket_1_y) ||
            (ball_y == racket_1_y + 1)) &&
           ball_x == racketstart_1_x) ||
          (((ball_y == racket_2_y - 1) || (ball_y == racket_2_y) ||
            (ball_y == racket_2_y + 1)) &&
           ball_x == racketstart_2_x)) {
        move_ball_x *= -1;
      } else if (ball_x == 1) {
        score_p1++;// счет 2 игрока ++;
        ball_x = ball_start_x;
        ball_y = ball_start_y;
        racket_1_y = racketstart_2_y, racket_2_y = racketstart_2_y;
        move_ball_x = 1; // направление движения шарика x = 1;
      } else if (ball_x == 78) {
       score_p2++;// счет 1 игрока ++;
        ball_x = ball_start_x;
        ball_y = ball_start_y;
        racket_1_y = racketstart_1_y, racket_2_y = racketstart_2_y;
        move_ball_x = -1; // направление движения шарика x = -1;
      }
    }
}

void clearScreen()
{
    printf("\033[2J"); // escape-последовательность для очистки экрана.
    printf("\033[0;0f"); // эта последовательность возвращает курсор в левый верхний угол.
}