#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

//This is the map! It is an array that holds a bunch of chars.
char *map[]={
"###############",
"#         #  T#",
"#            T#",
"#         #####",
"#####         #",
"#   #         #",
"#         N   #",
"#   #         #",
"#b  #         #",
"###############",
"Hit q to quit. "
};

int main()
{
    keypad(initscr(),1);
    int x = 2;
    int y = 2;
    int yy;
    int xx;
    int ch; //Key input variable
    curs_set(0);
    //keypad(stdscr, TRUE);
    noecho(); //Turns off echo, which is when input character shows on screen.
    while('q'!=(ch=getch())) //as long as the character input is not q the program goes on
    {
        for(yy=0;yy<11;yy++){
            for(xx=0;xx<15;xx++){
                mvaddch(yy,xx,map[yy][xx]);
            }
        }
        if (ch == KEY_DOWN && ' '==map[y+1][x]) //I was surprised when I realized increasing y was going down, then it made sense.
        {
            y++;
        }
        if (ch == KEY_UP && ' '==map[y-1][x]) //same as above. upper left is 0,0, y increases downwards
        {
            y--;
        }
        if (ch == KEY_LEFT && ' '==map[y][x-1])
        {
            x--;
        }
        if (ch == KEY_RIGHT && ' '==map[y][x+1])
        {
            x++;
        }
        mvaddch(y,x,'@'); //mvaddch takes a char, mvprintw takes a string and invokes printf
        //refresh(); //do I need this?
    }
    endwin();

    return 0;
}
