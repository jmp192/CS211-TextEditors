#ifdef _WIN32
//Windows includes
#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#else
//Linux / MacOS includes
#include <curses.h>
#endif
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

#define ctrl(x)           ((x) & 0x1f)

// void draw_centered(WINDOW* win, int max_y, int max_x, string text);

int main(void)
{

	/*
	WINDOWS
	*/

	WINDOW* main_window = nullptr;
	int num_cols = 0;
	int num_rows = 0;

	//initialize window
	main_window = initscr();

	//raw - accepts raw keyboard input
	raw();

	//start color - allows color functions
	start_color();

	/*
	SETUP
	*/

	//RESIZE WINDOW
	resize_term(5000, 5000);
	getmaxyx(main_window, num_rows, num_cols);
	resize_term(num_rows - 1, num_cols - 1);
	getmaxyx(main_window, num_rows, num_cols);

	//turn keyboard echo
	noecho();

	cbreak();

	//turn on keypad input
	keypad(main_window, TRUE);

	//hide the cursor
	curs_set(FALSE);

	/*
	MAIN PROGRAM LOGIC
	*/

	//pause for user input
	//bool keep_going = true;
	//while (keep_going == true)
	//{
	//	//clear window
	//	wclear(main_window);

	//	ostringstream temp_str{};
	//	temp_str << "width: " << num_cols << " height: " << num_rows;
	//	draw_centered(main_window, num_rows, num_cols, temp_str.str().c_str());
	//	refresh();
	//	int input = wgetch(main_window);

	//	//Curses documentation says to use KEY_RESIZE, but you can also use
	//	//is_termresized.  In real life, use either/or but not both.
	//	if (is_termresized() == true)
	//	{
	//		resize_term(0, 0);
	//		getmaxyx(main_window, num_rows, num_cols);
	//	}
	//	switch (input)
	//	{
	//	case ctrl('c'):
	//		keep_going = false;
	//	case KEY_RESIZE:
	//		resize_term(0, 0);
	//		getmaxyx(main_window, num_rows, num_cols);
	//	}
	//}

	//ROWS MANIPULATION
	for (int i = 0; i < num_cols; i++)
	{
		//top row
		start_color();
		init_pair(1, COLOR_YELLOW, COLOR_YELLOW);

		attron(COLOR_PAIR(1));
		mvaddch(0, i, ACS_BLOCK);
		attroff(COLOR_PAIR(1));

		//bottom row
		mvaddch(num_rows - 1, i, ACS_BLOCK);
	}

	// TEXT EDITOR NAME, VERSION, and FILE NAME
	char txtName[20] = "My Micro 1";
	char fileName[20] = "File: ";
	init_pair(2, COLOR_BLACK, COLOR_WHITE);

	attron(COLOR_PAIR(2));
	mvprintw(0, 5, txtName);
	mvprintw(0, 50, fileName);
	attroff(COLOR_PAIR(2));

	//COLUMNS MANIPULATION
	for (int i = 0; i < num_rows; i++)
	{
		//left column
		mvaddch(i, 0, ACS_BLOCK);
		//right column
		mvaddch(i, num_cols - 1, ACS_BLOCK);
	}

	//GUI file text
	attron(COLOR_PAIR(2));
	mvprintw(29, 1, "^F: FILE	^E: EDIT	^V: VIEW	^H: HELP");
	attroff(COLOR_PAIR(2));

		//INPUT CODE here

		//creating a NEW WINDOW for input
		//WINDOW* inputwin = newwin(3, 12, 5, 5);
		//box(inputwin, 0, 0);
		//refresh();
		//wrefresh(inputwin);

		//keypad(inputwin, true);

		//HOW TO CREATE NEW, etc
		//int inchar = wgetch(main_window);
		//	
		//	//switch for input
		//	switch (inchar)
		//	{
		//	case key_up: mvwprintw(main_window, 1, 1, "you pressed up!"), wrefresh(main_window);
		//		break;
		//	case key_down: mvwprintw(main_window, 1, 1, "you pressed down!"), wrefresh(main_window);
		//		break;
		//	case key_right: mvwprintw(main_window, 1, 1, "you pressed right!"), wrefresh(main_window);
		//		break;
		//	case key_left: mvwprintw(main_window, 1, 1, "you pressed left!"), wrefresh(main_window);
		//		break;
		//	};

			/*for (int i = 0; i < num_cols; i++)
			{
				mvwprintw(main_window, 1, 1, "<Enter exit to exit>");

				getch();

				if (inChar == 'a' && inChar != 'e')
				{
					mvaddch( i + 2, 2, 'a');

					getch();
				}
			}

	getch();*/

	//INPUT CODE HERE
	//get user input
	//pause for input

	//int cbreak(void);

	//int input = 0;

	//while (input != toupper('q'))
	//{
	//	input = getch();

	//	clear();	// wipe screen of previous contents
	//	//mvprintw("You pressed key %c, code %d.", input, input);
	//	mvprintw(input, input, "You pressed key %c, code %d.");
	//	refresh();
	//}

	//char input = getch();
	/*char userstr[100];
	int getstr(char userstr);
	mvprintw(2, 2, userstr);*/

	//int input = getch();


	//START NEW TEXT FILE

	//wifstream fin;
	//ifstream fin;
	//fin.open("C:\Users\James Pelligra\2019-fall-cs211\projects\TextEditor\TextEditorProject1");
	//fin.open("myInFile.txt");

	//use file here


	//char   tryOne[90];
	//fin >> tryOne;
	//mvprintw(4, 4, tryOne);
	//wrefresh(main_window);

	//try a nested statement to USE FILE

	//fin.close();


	//OUTPUT FILE
	//wofstream fout;
	//ofstream fout;
	//fout.open("myOutFile.txt");

	//use output file

	//fout.close();


	/*
	END CURSES MODE
	*/
	endwin();

	return 0;
}


	//Centered Drawing Function Definition
	/*void draw_centered(WINDOW* win, int max_y, int max_x, string text)
	{
		int length = text.length();
		int left_margin = (max_x - length) / 2;
		int top_margin = (max_y - 1) / 2;
		mvwprintw(win, top_margin, left_margin, text.c_str());
	}*/