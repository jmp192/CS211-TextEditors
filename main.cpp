#ifdef _WIN32
//Windows includes
#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#include "Trie.h"
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

 //void draw_centered(WINDOW* win, int max_y, int max_x, string text);

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
		init_pair(1, COLOR_GREEN, COLOR_GREEN);

		attron(COLOR_PAIR(1));
		mvaddch(0, i, ACS_BLOCK);
		attroff(COLOR_PAIR(1));

		//bottom row
		mvaddch(num_rows - 1, i, ACS_BLOCK);
	}

	// TEXT EDITOR NAME, VERSION, and FILE NAME
	char txtName[20] = "My Micro 1";
	char fileName[20] = "File: ";
	init_pair(2, COLOR_YELLOW, COLOR_GREEN);

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
	mvprintw(39, 1, "^F: FILE	^E: EDIT	^V: VIEW	^H: HELP");
	attroff(COLOR_PAIR(2));

		//INPUT CODE here

		////creating a NEW WINDOW for input
		char myChar = wgetch(main_window);
		WINDOW* inputwin = newwin(3, 12, 5, 5);
		box(inputwin, 0, 0);
		refresh();
		wrefresh(inputwin);

		switch (myChar)
		{
		case KEY_UP: mvwprintw(inputwin, 1, 1, "<Enter x to exit, z for newline>");
		}
		

		//keypad(inputwin, true);

		//INPUT VARIABLE
		char inChar;
		vector<char> user_input{};
		int i = 2;
		int j = 2;
			
		//switch for input
			/*switch (inChar)
			{
			case KEY_UP: j--;
				break;
			case KEY_DOWN: j++;
				break;
			case KEY_RIGHT: i--;
				break;
			case KEY_LEFT: i++;
				break;
			case KEY_BACKSPACE: ;
				break;
			case KEY_ENTER: ;
				break;
			};*/

			mvwprintw(main_window, 1, 1, "<Enter x to exit, z for newline>");
			bool keepGoing = true;

			while (i < num_cols && keepGoing == true)
			{
				while (j < num_cols && keepGoing == true)
				{
					inChar = wgetch(main_window);
					user_input.push_back(inChar);

					if (inChar == 'x')	//this character goes into input file
					{
						keepGoing = false;
					}
					else if (inChar == 'z')
					{
						i += 1;
						j = 1;
					}
					else
					{
						mvaddch(i, j, inChar);	//try adding these characters to a vector
					}
					j++;
				}
				i++;
			}

			//trie main code
			Trie dictionary{};

			string line = "";
			dictionary.addWord("abc");
			dictionary.addWord("aabc");
			dictionary.addWord("def");
			vector<string> result = dictionary.search("a");

			////expected result:  "abc", "aabc"
			for (auto item : result)
			{
				cout << item << endl;
			}

	//int cbreak(void);

	//char input = getch();
	/*char userstr[100];
	int getstr(char userstr);
	mvprintw(2, 2, userstr);*/

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

	/*
	END CURSES MODE
	*/
	endwin();

	//OUTPUT FILE
	//wofstream fout;
	ofstream fout;
	fout.open("myOutFile.txt");

	//use output file

	for (int i = 0; i < user_input.size(); i++)
	{
		//fout << i;
		fout << user_input[i];
		//break;
	}

	fout.close();

	//READ IN TRIE INPUT FILE TO VECTOR
	vector<char> trieInput{};
	ofstream fin;
	fin.open("myInFile.txt");

	//use output file

	for (int i = 0; i < trieInput.size(); i++)
	{
		//fin >> trieInput[i];
	}

	fin.close();

	fout.open("myOutFile.txt");
	for (int i = 0; i < trieInput.size(); i++)
	{
		fout << trieInput[i];
	}

	fout.close();

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