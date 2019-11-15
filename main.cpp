#define PDC_DLL_BUILD 1
#include "curses.h"
#include "panel.h"
#include "curspriv.h"
#include "Trie.h"
#include "Prior.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

#define ctrl(x)           ((x) & 0x1f)

 //void draw_centered(WINDOW* win, int max_y, int max_x, string text);

#include <iostream>
#include <queue>
#include <string>
using namespace std;

class MaxHeapPairComparer
{
public:
	template<typename K, typename V>
	bool operator()(const pair<K, V>& left, const pair <K, V>& right)
	{
		return left.second < right.second;
	}
};
class MinHeapPairComparer
{

public:
	template<typename K, typename V>
	bool operator()(const pair<K, V>& left, const pair <K, V>& right)
	{
		return left.second > right.second;
	}
};

int main(void)
{

	//TRIE TREE CODE
	Trie tree;
	ifstream fin;
	fin.open("myInFile.txt");
	string readThis;
	if (fin.good())
	{
		while (getline(fin, readThis))
		{
			tree.addWord(readThis);
		}
	}
	fin.close();
	cout << endl;

	vector<string> test = tree.search("type");
	for (int i = 0; i < test.size(); i++)
	{
		cout << test[i] << endl << endl;
	}

	//PRIORITY QUEUE CODE
	/*fin.open("priorInFile.txt");
	string readThat;
	if (fin.good())
	{
		while (getline(fin, readThat))
		{

		}
	}*/

	/*int		 index;
	ifstream fin;
	string wordArray[100];

	fin.open("InFile.txt");

	for (index = 0; index < 100; index++)
	{
		getline(fin, wordArray[index]);

		fin.ignore(1000, '\n');
	}*/

	fin.close();

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

		//creating a NEW WINDOW for input
		WINDOW* inputwin = newwin(10, 20, 5, 5);
		box(inputwin, 0, 0);
		mvwprintw(inputwin, 1, 1, "this is a box");
		refresh();
		wrefresh(inputwin);

		/*vector<string> test = t.search("stati");
		for (int i = 0; i < test.size(); i++)
		{
			cout << test[i] << endl;
		}*/

		//input test with switch and outputting
		/*char myChar = wgetch(main_window);
		switch (myChar)
		{
			case KEY_UP: mvwprintw(inputwin, 1, 1, "<Enter x to exit, z for newline>");
		}*/
		
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

	/*
	END CURSES MODE
	*/
	endwin();

	//OUTPUT FILE
	//wofstream fout;
	ofstream fout;
	fout.open("myOutFile.txt");

	/*unordered_map<string, int> sentence;
	string word = "";
	string stringMax = "";
	int intMax = 0;

	for (int i = 0; i < user_input.size(); i++)
	{
		if (user_input[i] == "")
		{
			return "";
		}

		for (auto x : user_input)
		{
			if (x == ' ')
			{
				if (sentence.count(word) > 0)
				{
					sentence[word]++;
				}
				else
				{
					sentence[word] = 1;
				}
				word = "";
			}
			else
			{
				word = word + x;
			}
		}
	}
	sentence[word]++;*/

	//use output file
	//CREATE BINARY FORMAT
	for (int i = 0; i < user_input.size(); i++)
	{
		fout << user_input[i];
	}

	/*unordered_map<string, int> sentence;
	string word = "";
	while (!fout.eof())
	{
		getline(fout, word, ' ');
		sentence[word]++;
	}*/

	fout.close();

	//ifstream fin;
	fin.open("priorInFile.txt");
	unordered_map<string, int> sentence;
	string word;

	while (fin >> word)
	{
		++sentence[word];
	}
	for (auto result : sentence)
	{
		cout << result.first << ": " 
			 << result.second << endl;
	}
	
	//PRIORITY QUEUE
	priority_queue<pair<string, int>, vector<pair<string, int>>, MaxHeapPairComparer> max_pq{};
	//BUILDING MAX HEAP
	for (auto y : sentence)
	{
		max_pq.push(make_pair(y.first, y.second));
	}

	cout << endl << endl;

	int decVal;
	int binaryArray[32];
	//NOW, POP AND ASSIGN EACH WORD A UNQUE BINARY STRING VALUE
	fout.open("mySecOutFile.txt");
	ofstream foutTwo;
	foutTwo.open("BinMapOut.txt");
	while (max_pq.empty() == false)
	{
		int index = 0;
		decVal = max_pq.top().second;
		while (decVal > 0)
		{
			binaryArray[index] = decVal % 2;
			decVal = decVal / 2;
			index++;
			//max_pq.top().second = decVal;
		}

		//cout << max_pq.top().first << ": " << max_pq.top().second << endl;
		cout << max_pq.top().first << ": ";
		foutTwo << max_pq.top().first << ": ";

		for (int j = index - 1; j >= 0; j--)
		{
			cout << binaryArray[j];
			fout << binaryArray[j];
			foutTwo << binaryArray[j];

		}
		cout << endl;
		fout << " ";
		foutTwo << endl;
		max_pq.pop();
	}
	fout.close();
	foutTwo.close();
	cout << endl << endl;

	/*unordered_map<string, int> newSentence;
	while (fin >> word)
	{
		++newSentence[word];
	}*/

	//while (!finTwo.eof())
	//{
	//	if(word != " ")
	//	{
	//		getline(finTwo, word, ' ');
	//	}
	//	else if(word != "\n")
	//	{
	//		getline(finTwo, word, '\n');
	//	}
	//	/*if (word != word + " " || word != word + "\n")
	//	{
	//		sentence[word]++;
	//	}*/
	//	sentence[word]++;
	//	//++sentence[word];
	//}

	//ofstream foutSec;
	/*fout.open("mySecOutFile.txt");
	for (auto row : sentence)
	{
		fout << row.first << ": " << row.second << endl;
	}*/

	/*while (!foutSec.eof())
	{
		foutSec << sentence["orange"] << endl;
	}*/

	return 0;
}