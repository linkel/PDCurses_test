#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main()
{
    int x = 5;
    int y = 5;
    int ch; //Key input variable
    initscr();
    curs_set(0);
    keypad(stdscr, TRUE);
    noecho(); //Turns off echo, which is when input character shows on screen.
    while(1)
    {
        mvprintw(y,x, "X");
        ch = getch();
        if (ch == KEY_DOWN)
        {
            y++;
            clear();
        }
        if (ch == KEY_UP)
        {
            y--;
            clear();
        }
        if (ch == KEY_LEFT)
        {
            x--;
            clear();
        }
        if (ch == KEY_RIGHT)
        {
            x++;
            clear();
        }
        refresh();
    }
    endwin();

    return 0;
}
