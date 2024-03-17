// https://www.kushiro-ct.ac.jp/yanagawa/curses/about.html
// https://www.kushiro-ct.ac.jp/yanagawa/ex-2017/2-game/01.html
// https://okwave.jp/qa/q160619.html#goog_rewarded


#include <ncurses.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h> //test

#define FLAG_LENGTH 34
// #define LETTER_SIZE_X 10
#define LETTER_SIZE_Y 7

#define BAG_SIZE 256

#define MAP_SIZE_X 20
#define MAP_SIZE_Y 15

#define OBJECT_SIZE_X 6
#define OBJECT_SIZE_Y 3

#define SIGHT_X 5
#define SIGHT_Y 5


// char BAG[BAG_SIZE];
char MAP[MAP_SIZE_Y][MAP_SIZE_X];
char FLAG[FLAG_LENGTH][LETTER_SIZE_Y][MAP_SIZE_X];

void set_color() {
    int COLOR_BROWN = 8;

	start_color();

    // init_color(COLOR_BROWN, 165, 42, 42);
    init_color(COLOR_BROWN, 225, 102, 102);

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BROWN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	// init_pair(10, COLOR_BLACK, COLOR_WHITE);
	// bkgd(COLOR_PAIR(10));			// 背景は色10
}


void setFlag() {
    // katagaitai-CTF{segmentation_fault}
    int number, x, y;

    for(number = 0; number < FLAG_LENGTH; number++) {
        for(y = 0; y < LETTER_SIZE_Y; y++) {
            for(x = 0; x < MAP_SIZE_X; x++) {
                FLAG[number][y][x] = '\x00';
            }
        }
    }

// あ
// あ　　あ
// あ　あ
// ああ
// あ　あ
// あ　　あ

    number = 0;

    for(y = 0; y < LETTER_SIZE_Y - 1; y++) {
        FLAG[number][y][0] = '\xff';
    }
    for(x = 1; x <= 3; x++) {
        FLAG[number][4 - x][x] = '\xff';
        FLAG[number][x + 2][x] = '\xff';
    }

// あああ
// 　　　あ
// 　あああ
// あ　　あ
// あ　　あ
// 　ああ　あ

    number++;

    for(y = 3; y <= 4; y++) {
        FLAG[number][y][0] = '\xff';
    }
    for(y = 1; y <= 4; y++) {
        FLAG[number][y][3] = '\xff';
    }
    for(x = 1; x <= 2; x++) {
        FLAG[number][2][x] = '\xff';
        FLAG[number][5][x] = '\xff';
    }
    for(x = 0; x <= 2; x++) {
        FLAG[number][0][x] = '\xff';
    }
    FLAG[number][5][4] = '\xff';

// 　あ
// ああああ
// 　あ
// 　あ
// 　あ　あ
// 　ああ

    number++;

    for(y = 0; y < LETTER_SIZE_Y - 1; y++) {
        FLAG[number][y][1] = '\xff';
    }
    for(x = 0; x <= 3; x++) {
        FLAG[number][1][x] = '\xff';
    }
    for(x = 2; x <= 3; x++) {
        FLAG[number][7 - x][x] = '\xff';
    }

// a
    number++;

    for(y = 3; y <= 4; y++) {
        FLAG[number][y][0] = '\xff';
    }
    for(y = 1; y <= 4; y++) {
        FLAG[number][y][3] = '\xff';
    }
    for(x = 1; x <= 2; x++) {
        FLAG[number][2][x] = '\xff';
        FLAG[number][5][x] = '\xff';
    }
    for(x = 0; x <= 2; x++) {
        FLAG[number][0][x] = '\xff';
    }
    FLAG[number][5][4] = '\xff';


// 　ああああ
// あ　　あ
// 　あああ
// 　　　あ
// あ　　あ
// 　ああ

    number++;

    for(y = 1; y <= 4; y++) {
        FLAG[number][y][3] = '\xff';
    }
    for(x = 1; x <= 4; x++) {
        FLAG[number][0][x] = '\xff';
    }
    for(x = 1; x <= 2; x++) {
        FLAG[number][2][x] = '\xff';
        FLAG[number][5][x] = '\xff';
    }
    FLAG[number][1][0] = '\xff';
    FLAG[number][4][0] = '\xff';

// a
    number++;

    for(y = 3; y <= 4; y++) {
        FLAG[number][y][0] = '\xff';
    }
    for(y = 1; y <= 4; y++) {
        FLAG[number][y][3] = '\xff';
    }
    for(x = 1; x <= 2; x++) {
        FLAG[number][2][x] = '\xff';
        FLAG[number][5][x] = '\xff';
    }
    for(x = 0; x <= 2; x++) {
        FLAG[number][0][x] = '\xff';
    }
    FLAG[number][5][4] = '\xff';


// 　　あ
// 
// 　　あ
// 　　あ
// 　　あ
// 　　あ

    number++;

    for(y = 2; y <= 5; y++) {
        FLAG[number][y][2] = '\xff';
    }
    FLAG[number][0][2] = '\xff';

// t

    number++;

    for(y = 0; y < LETTER_SIZE_Y - 1; y++) {
        FLAG[number][y][1] = '\xff';
    }
    for(x = 0; x <= 3; x++) {
        FLAG[number][1][x] = '\xff';
    }
    for(x = 2; x <= 3; x++) {
        FLAG[number][7 - x][x] = '\xff';
    }

// a
    number++;

    for(y = 3; y <= 4; y++) {
        FLAG[number][y][0] = '\xff';
    }
    for(y = 1; y <= 4; y++) {
        FLAG[number][y][3] = '\xff';
    }
    for(x = 1; x <= 2; x++) {
        FLAG[number][2][x] = '\xff';
        FLAG[number][5][x] = '\xff';
    }
    for(x = 0; x <= 2; x++) {
        FLAG[number][0][x] = '\xff';
    }
    FLAG[number][5][4] = '\xff';

// i

    number++;

    for(y = 2; y <= 5; y++) {
        FLAG[number][y][2] = '\xff';
    }
    FLAG[number][0][2] = '\xff';

// 
// 
// あああああ
// 
// 
// 
    number++;

    for(x = 0; x <= 4; x++) {
        FLAG[number][2][x] = '\xff';
    }

// 　　あああ
// 　あ
// あ
// あ
// 　あ
// 　　あああ

    number++;

    for(x = 2; x <= 4; x++) {
        FLAG[number][0][x] = '\xff';
        FLAG[number][5][x] = '\xff';
    }
    for(y = 2; y <= 3; y++) {
        FLAG[number][y][0] = '\xff';
    }
    FLAG[number][1][1] = '\xff';
    FLAG[number][4][1] = '\xff';

// あああああ
// 　　あ
// 　　あ
// 　　あ
// 　　あ
// 　　あ

    number++;

    for(x = 0; x <= 4; x++) {
        FLAG[number][0][x] = '\xff';
    }
    for(y = 1; y <= 5; y++) {
        FLAG[number][y][2] = '\xff';
    }

// あああああ
// あ
// ああああ
// あ
// あ
// あ

    number++;

    for(y = 0; y <= 5; y++) {
        FLAG[number][y][0] = '\xff';
    }
    for(x = 1; x <= 4; x++) {
        FLAG[number][0][x] = '\xff';
    }
    for(x = 1; x <= 3; x++) {
        FLAG[number][2][x] = '\xff';
    }


// 　ああ
// 　あ
// あ
// 　あ
// 　ああ
// 

    number++;

    for(x = 1; x <= 2; x++) {
        FLAG[number][0][x] = '\xff';
        FLAG[number][4][x] = '\xff';
    }
    FLAG[number][1][1] = '\xff';
    FLAG[number][2][0] = '\xff';
    FLAG[number][3][1] = '\xff';

// ああああ
// あ
// ああああ
// 　　　あ
// ああああ
// 

    number++;

    for(x = 0; x <= 3; x++) {
        FLAG[number][0][x] = '\xff';
        FLAG[number][2][x] = '\xff';
        FLAG[number][4][x] = '\xff';
    }
    FLAG[number][1][0] = '\xff';
    FLAG[number][3][3] = '\xff';

// 　あああ
// あ　　　あ
// あああああ
// あ
// 　ああああ
// 

    number++;

    for(x = 1; x <= 3; x++) {
        FLAG[number][0][x] = '\xff';
    }
    for(x = 1; x <= 4; x++) {
        FLAG[number][2][x] = '\xff';
        FLAG[number][4][x] = '\xff';
    }
    for(y = 1; y <= 3; y++) {
        FLAG[number][y][0] = '\xff';
    }
    FLAG[number][1][4] = '\xff';

// g

    number++;

    for(y = 1; y <= 4; y++) {
        FLAG[number][y][3] = '\xff';
    }
    for(x = 1; x <= 4; x++) {
        FLAG[number][0][x] = '\xff';
    }
    for(x = 1; x <= 2; x++) {
        FLAG[number][2][x] = '\xff';
        FLAG[number][5][x] = '\xff';
    }
    FLAG[number][1][0] = '\xff';
    FLAG[number][4][0] = '\xff';

// 
// 
// あ　あ　あ
// 　あ　あ　あ
// 　あ　あ　あ
// 　あ　あ　ああ

    number++;

    for(y = 3; y <= 5; y++) {
        FLAG[number][y][1] = '\xff';
        FLAG[number][y][3] = '\xff';
        FLAG[number][y][5] = '\xff';
    }
    FLAG[number][2][0] = '\xff';
    FLAG[number][2][2] = '\xff';
    FLAG[number][2][4] = '\xff';
    FLAG[number][5][6] = '\xff';

// e
    number++;

    for(x = 1; x <= 3; x++) {
        FLAG[number][0][x] = '\xff';
    }
    for(x = 1; x <= 4; x++) {
        FLAG[number][2][x] = '\xff';
        FLAG[number][4][x] = '\xff';
    }
    for(y = 1; y <= 3; y++) {
        FLAG[number][y][0] = '\xff';
    }
    FLAG[number][1][4] = '\xff';

// 
// 
// あ　ああ
// 　あ　　あ
// 　あ　　あ
// 　あ　　ああ

    number++;

    for(y = 3; y <= 5; y++) {
        FLAG[number][y][1] = '\xff';
        FLAG[number][y][4] = '\xff';
    }
    for(x = 2; x <= 3; x++) {
        FLAG[number][2][x] = '\xff';
    }
    FLAG[number][2][0] = '\xff';
    FLAG[number][5][5] = '\xff';

// t

    number++;

    for(y = 0; y < LETTER_SIZE_Y - 1; y++) {
        FLAG[number][y][1] = '\xff';
    }
    for(x = 0; x <= 3; x++) {
        FLAG[number][1][x] = '\xff';
    }
    for(x = 2; x <= 3; x++) {
        FLAG[number][7 - x][x] = '\xff';
    }

// a
    number++;

    for(y = 3; y <= 4; y++) {
        FLAG[number][y][0] = '\xff';
    }
    for(y = 1; y <= 4; y++) {
        FLAG[number][y][3] = '\xff';
    }
    for(x = 1; x <= 2; x++) {
        FLAG[number][2][x] = '\xff';
        FLAG[number][5][x] = '\xff';
    }
    for(x = 0; x <= 2; x++) {
        FLAG[number][0][x] = '\xff';
    }
    FLAG[number][5][4] = '\xff';

// t

    number++;

    for(y = 0; y < LETTER_SIZE_Y - 1; y++) {
        FLAG[number][y][1] = '\xff';
    }
    for(x = 0; x <= 3; x++) {
        FLAG[number][1][x] = '\xff';
    }
    for(x = 2; x <= 3; x++) {
        FLAG[number][7 - x][x] = '\xff';
    }

// i

    number++;

    for(y = 2; y <= 5; y++) {
        FLAG[number][y][2] = '\xff';
    }
    FLAG[number][0][2] = '\xff';

// 
// 　あああ
// あ　　　あ
// あ　　　あ
// あ　　　あ
// 　あああ

    number++;

    for(y = 2; y <= 4; y++) {
        FLAG[number][y][0] = '\xff';
        FLAG[number][y][4] = '\xff';
    }
    for(x = 1; x <= 3; x++) {
        FLAG[number][1][x] = '\xff';
        FLAG[number][5][x] = '\xff';
    }

// n
    number++;

    for(y = 1; y <= 3; y++) {
        FLAG[number][y][1] = '\xff';
        FLAG[number][y][4] = '\xff';
    }
    for(x = 2; x <= 3; x++) {
        FLAG[number][0][x] = '\xff';
    }
    FLAG[number][0][0] = '\xff';
    FLAG[number][3][5] = '\xff';

// 
// 
// 
// 
// 
// あああああ

    number++;

    for(x = 0; x <= 4; x++) {
        FLAG[number][5][x] = '\xff';
    }

// 　　ああ
// 　あ
// ああああ
// 　あ
// 　あ
// 　あ
    number++;

    for(y = 1; y <= 5; y++) {
        FLAG[number][y][1] = '\xff';
    }
    for(x = 2; x <= 3; x++) {
        FLAG[number][0][x] = '\xff';
    }
    for(x = 0; x <= 3; x++) {
        FLAG[number][2][x] = '\xff';
    }

// a
    number++;

    for(y = 3; y <= 4; y++) {
        FLAG[number][y][0] = '\xff';
    }
    for(y = 1; y <= 4; y++) {
        FLAG[number][y][3] = '\xff';
    }
    for(x = 1; x <= 2; x++) {
        FLAG[number][2][x] = '\xff';
        FLAG[number][5][x] = '\xff';
    }
    for(x = 0; x <= 2; x++) {
        FLAG[number][0][x] = '\xff';
    }
    FLAG[number][5][4] = '\xff';

// 
// 
// あ　　あ
// あ　　あ
// あ　　あ
// 　ああ　あ

    number++;

    for(y = 2; y <= 4; y++) {
        FLAG[number][y][0] = '\xff';
        FLAG[number][y][3] = '\xff';
    }
    for(x = 1; x <= 2; x++) {
        FLAG[number][5][x] = '\xff';
    }
    FLAG[number][5][4] = '\xff';

// 　ああ
// 　　あ
// 　　あ
// 　　あ
// 　　あ
// 　　ああ

    number++;

    for(y = 1; y <= 4; y++) {
        FLAG[number][y][2] = '\xff';
    }
    for(x = 1; x <= 2; x++) {
        FLAG[number][0][x] = '\xff';
    }
    for(x = 2; x <= 3; x++) {
        FLAG[number][5][x] = '\xff';
    }

// t
    number++;

    for(y = 0; y < LETTER_SIZE_Y - 1; y++) {
        FLAG[number][y][1] = '\xff';
    }
    for(x = 0; x <= 3; x++) {
        FLAG[number][1][x] = '\xff';
    }
    for(x = 2; x <= 3; x++) {
        FLAG[number][7 - x][x] = '\xff';
    }

// ああ
// 　あ
// 　　あ
// 　あ
// ああ
// 

    number++;

    for(x = 0; x <= 1; x++) {
        FLAG[number][0][x] = '\xff';
        FLAG[number][4][x] = '\xff';
    }
    FLAG[number][1][1] = '\xff';
    FLAG[number][2][2] = '\xff';
    FLAG[number][3][1] = '\xff';
}


void drawPlayer(int center_x, int center_y, int key) {
    char head[OBJECT_SIZE_X + 2];
    char arms[OBJECT_SIZE_X + 3];
    char legs[OBJECT_SIZE_X + 1];

    if(key == 's') {
        strcpy(head,  "〇");
        strcpy(arms, "／||＞");
        strcpy(legs, " < \\");
    }else if(key == 'f') {
        strcpy(head,  "  〇");
        strcpy(arms, "＜||＼");
        strcpy(legs, "  / >");
    }else{
        strcpy(head,  " 〇");
        strcpy(arms, "／||＼");
        strcpy(legs, " /  \\");
    }

    mvaddstr(center_y, center_x + 1, head);
    mvaddstr(center_y + 1, center_x, arms);
    mvaddstr(center_y + 2, center_x, legs);
}


void drawGrass(int x, int y) {
    char grass[OBJECT_SIZE_Y][OBJECT_SIZE_X + 1] = {
        "wWwWwW",
        "WwWwWw",
        "wWwWwW"
    };

    attrset(COLOR_PAIR(1));
    for(int i = 0; i < OBJECT_SIZE_Y; i++) {
        mvaddstr(y + i, x, grass[i]);
    }
    attrset(COLOR_PAIR(0));
}


void drawTree(int x, int y) {
    char *head = " ／＼ ";
    char *body = "／＿＼";
    char *root = "  ||  ";

    attrset(COLOR_PAIR(1));
    mvaddstr(y, x, head);
    mvaddstr(y + 1, x, body);
    attrset(COLOR_PAIR(2));
    mvaddstr(y + 2, x, root);
    attrset(COLOR_PAIR(0));
}


void drawBuilding(int x, int y) {
    char building[OBJECT_SIZE_Y * 2][OBJECT_SIZE_X * 4 * 3 + 1] = {
        "　────────────────────",
        "／　　　　　　　　　　＼",
        "┬─────┌────┐───────────┐",
        "│     │   .│    ┌─┬─┐  │",
        "│     │    │    └─┴─┘  │",
        "┴─────┴────┴───────────┴"
    };

    for(int i = 0; i < OBJECT_SIZE_Y * 2; i++) {
        mvaddstr(y + i, x, building[i]);
    }
}


void drawRabbit(int x, int y) {
    char rabbit[OBJECT_SIZE_Y * 2][OBJECT_SIZE_X * 2 + 1] = {
        "/\\   /\\",
        "\\ \\_/ /",
        " (`Y')",
        "()~*~()",
        "(     )",
        "(_)-(_)"
    };

    for(int i = 0; i < OBJECT_SIZE_Y * 2; i++) {
        mvaddstr(y + i, x + 3, rabbit[i]);
    }
}


void initMap() {
    // 0: 空白, 1: 木
    for(int i = 0; i < MAP_SIZE_Y; i++) {
        for(int j = 0; j < MAP_SIZE_X; j++) {
            MAP[i][j] = '\x00';
        }
    }

    for(int i = 0; i < MAP_SIZE_X; i++) {
        MAP[0][i] = 't';
        MAP[MAP_SIZE_Y - 1][i] = 't';
    }
    MAP[0][9] = '\x01';
    MAP[0][10] = '\x01';

    for(int i = 1; i < MAP_SIZE_Y - 1; i++) {
        MAP[i][0] = 't';
        MAP[i][MAP_SIZE_X - 1] = 't';
    }

    MAP[3][4] = 'B'; MAP[3][5] = 'b'; MAP[3][6] = 'b'; MAP[3][7] = 'b';
    MAP[4][4] = 'b'; MAP[4][5] = '\x02'; MAP[4][6] = 'b'; MAP[4][7] = 'b';
}


void drawMap(int player_x, int player_y, int center_x, int center_y) {
    for(int y = (-1) * SIGHT_Y; y <= SIGHT_Y; y++) {
        for(int x = (-1) * SIGHT_X; x <= SIGHT_X; x++) { // 描画範囲内で
            if(player_y + y >= 0 && player_y + y < MAP_SIZE_Y) {
                if(player_x + x >= 0 && player_x + x < MAP_SIZE_X) { // MAP内ならば
                    if(MAP[player_y + y][player_x + x] == '\x01') drawGrass(center_x + x * OBJECT_SIZE_X, center_y + y * OBJECT_SIZE_Y); // 草を描画
                    if(MAP[player_y + y][player_x + x] == 't') drawTree(center_x + x * OBJECT_SIZE_X, center_y + y * OBJECT_SIZE_Y); // 木を描画
                    if(MAP[player_y + y][player_x + x] == 'B') drawBuilding(center_x + x * OBJECT_SIZE_X, center_y + y * OBJECT_SIZE_Y); // 建物を描画
                }
            }
        }
    }
    drawRabbit(5, 5);//test
}


void printMapCode(int player_x, int player_y, int center_x, int center_y) {
    char test_buf[OBJECT_SIZE_X + 1];

    for(int y = (-1) * SIGHT_Y; y <= SIGHT_Y; y++) {
        for(int x = (-1) * SIGHT_X; x <= SIGHT_X; x++) { // 描画範囲内で
            // if(player_y + y >= 0 && player_y + y < MAP_SIZE_Y) {
            //     if(player_x + x >= 0 && player_x + x < MAP_SIZE_X) {
                    // code = MAP[player_y + y][player_x + x]; // *** stack smashing detected ***: terminatedが表示される
                    if(MAP[player_y + y][player_x + x] >> 4 == '\x00') {
                        sprintf(test_buf, " <0x0f");
                        attrset(COLOR_PAIR(0));
                    }else {
                        sprintf(test_buf, " 0x?? ");
                        attrset(COLOR_PAIR(0) | A_REVERSE);
                        mvaddstr(center_y + y * OBJECT_SIZE_Y, center_x + x * OBJECT_SIZE_X, "      ");
                        mvaddstr(center_y + y * OBJECT_SIZE_Y + 2, center_x + x * OBJECT_SIZE_X, "      ");
                    }
                    mvaddstr(center_y + y * OBJECT_SIZE_Y + 1, center_x + x * OBJECT_SIZE_X, test_buf);
                    attrset(COLOR_PAIR(0));
            //     }
            // }
        }
    }
}


void drawWindow(int h, int w, int player_x, int player_y, int key) {
    int center_x = (w - OBJECT_SIZE_X) / 2;
    int center_y = (h - OBJECT_SIZE_Y) / 2;

    drawMap(player_x, player_y, center_x, center_y);
    printMapCode(player_x, player_y, center_x, center_y); // test
    drawPlayer(center_x, center_y, key);
}


int main() {
	int  player_x, player_y, w, h;
	int	key = 'd';

    setFlag();

    setlocale(LC_ALL, "");

	initscr();

    set_color();
	noecho();		// echo();
	cbreak();		// nocbreak();
    keypad(stdscr, TRUE);
	getmaxyx(stdscr, h, w);

    initMap();
	player_x = 7;
	player_y = 15;


	while (1) {
		erase();
        drawWindow(h, w, player_x, player_y, key);
        char test[OBJECT_SIZE_X + 1]; sprintf(test, "%d %d", player_x, player_y);
        addstr(test);//test
		refresh();
        
        // usleep(100000);
        flushinp(); // 入力バッファのクリア
		key = getch();
        if (key == 'q') break;
        switch (key) {
		case 'e':
        case KEY_UP:
            if(MAP[player_y - 1][player_x] >> 4 == '\x00')
                player_y--;
            break;
		case 'd':
        case KEY_DOWN:
            if(MAP[player_y + 1][player_x] >> 4 == '\x00')
                player_y++;
            break;
		case 's':
        case KEY_LEFT:
            if(MAP[player_y][player_x - 1] >> 4 == '\x00')
                player_x--;
            break;
		case 'f':
        case KEY_RIGHT:
            if(MAP[player_y][player_x + 1] >> 4 == '\x00')
                player_x++;
            break;
        default: break;
        }
	}
	endwin();
	return (0);
}