#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <iterator>
#include "Direction.hpp"
#include "Board.hpp"
using ariel::Direction;
using namespace std;

// int main()
// {
//     ariel::Board b;
//     cout << "first show, empty board:\n";
//     b.show();
//     b.post(0, 0, Direction::Horizontal, "check");
//     if (b.read(0, 0, Direction::Horizontal, 5) == "check")
//     {
//         cout << "True" << endl;
//     }
//     if (b.read(1, 0, Direction::Horizontal, 5) == "_____")
//     {
//         cout << "True" << endl;
//     }
//     b.post(0, 1, Direction::Horizontal, "check");
//     if (b.read(0, 0, Direction::Horizontal, 6) == "ccheck")
//     {
//         cout << "True" << endl;
//     }
//     b.post(0, 0, Direction::Horizontal, "_");
//     if (b.read(0, 0, Direction::Horizontal, 6) == "_check")
//     {
//         cout << "True" << endl;
//     }
//     b.post(1, 0, Direction::Horizontal, "check2");
//     if (b.read(1, 5, Direction::Horizontal, 1) == "2")
//     {
//         cout << "True" << endl;
//     }
//     b.post(1, 0, Direction::Horizontal, "22222");
//     if (b.read(0, 0, Direction::Horizontal, 6) == "222222")
//     {
//         cout << "True" << endl;
//     }
//     cout << "second show: \n";
//     b.show();
//     b.post(2, 2, Direction::Horizontal, "#");
//     if (b.read(2, 1, Direction::Horizontal, 3) == "_#_")
//     {
//         cout << "True" << endl;
//     }
//     b.post(3, 0, Direction::Horizontal, "fivech");
//     if (b.read(3, 3, Direction::Horizontal, 3) == "ech")
//     {
//         cout << "True" << endl;
//     }
//     b.post(4, 0, Direction::Horizontal, "!@#$%^");
//     if (b.read(4, 0, Direction::Horizontal, 4) != "____")
//     {
//         cout << "True" << endl;
//     }
//     b.post(0, 0, Direction::Horizontal, "a");
//     if (b.read(0, 0, Direction::Vertical, 5) == "a2_f!")
//     {
//         cout << "True" << endl;
//     }
//     b.post(1, 3, Direction::Vertical, "check");
//     if (b.read(0, 1, Direction::Vertical, 5) == "c2_i@")
//     {
//         cout << "True" << endl;
//     }
//     if (b.read(0, 1, Direction::Vertical, 5) == "c2 i@")
//     {
//         cout << "True" << endl;
//     }
//     b.post(2, 2, Direction::Vertical, "!");
//     if (b.read(0, 2, Direction::Vertical, 6) == "h2!v#_")
//     {
//         cout << "True" << endl;
//     }
//     b.post(0, 4, Direction::Vertical, "c2_c%_");
//     b.post(0, 4, Direction::Vertical, "c2_c%-");
//     b.post(0, 0, Direction::Vertical, "");
//     if (b.read(0, 5, Direction::Vertical, 6) == "k2_h1_")
//     {
//         cout << "True" << endl;
//     }
//     bool a = (b.read(0, 0, Direction::Horizontal, 6) == "acheck");
//     if (a)
//     {
//         cout << "True\n"
//              << endl;
//     }
//     cout << "last show:\n";
//     b.show();
//     cout << endl;
//     ariel::Board b2;
//     cout << "second board, first show with empty board:\n";
//     b2.show();
//     b2.post(50, 100, Direction::Vertical, "aviem");
//     b2.post(100, 200, Direction::Horizontal, "abcd");
//     cout << "second show:\n";
//     b2.show();
//     string t = "____________________________________________________________________________________________________";
//     string c = b2.read(100, 100, Direction::Horizontal, 100);
//     bool d = (t == c);
//     if (d)
//     {
//         cout << "number of underscores is equal!" << endl;
//     }
//     cout << "number of underscores until char 'a': " << t.length();
//     return 0;
// }

namespace ariel
{
    Board::Board(){};

    void Board::post(unsigned int row, unsigned int column, ariel::Direction d, string const &s)
    {
        if (d == Direction::Horizontal)
        {
            for (size_t i = 0; i < s.length(); i++)
            {
                board[row][column + i] = s.at(i);
            }
        }

        if (d == Direction::Vertical)
        {
            for (size_t i = 0; i < s.length(); i++)
            {
                board[row + i][column] = s.at(i);
            }
        }
    };

    string Board::read(unsigned int row, unsigned int column, ariel::Direction d, unsigned int num)
    {
        string s;

        if (d == Direction::Horizontal)
        {
            for (size_t i = 0; i < num; i++)
            {
                if (!board[row].empty())
                {
                    if (board[row][column + i]!=0)
                    {
                        s += board[row][column + i];
                    }
                    else
                    {
                        s += "_";
                    }
                }
                else
                {
                    s += "_";
                }
            }
        }
        if (d == Direction::Vertical)
        {
            for (size_t i = 0; i < num; i++)
            {
                if (!board[row + i].empty())
                {
                    if (board[row + i][column]!=0)
                    {
                        s += board[row + i][column];
                    }
                    else
                    {
                        s += "_";
                    }
                }
                else
                {
                    s += "_";
                }
            }
        }
        return s;
    };

    void Board::show()
    {
        map<unsigned int, map<unsigned int, char>>::iterator itr = board.begin();
        map<unsigned int, char>::iterator in_itr = itr->second.begin();
        unsigned int min_row = board.begin()->first;
        unsigned int max_row = 0;
        unsigned int min_column = INT32_MAX;
        unsigned int max_column = 0;

        for (itr = board.begin(); itr != board.end(); itr++)
        {
            if (max_row < itr->first)
            {
                max_row = itr->first;
            }
            for (in_itr = itr->second.begin(); in_itr != itr->second.end(); in_itr++)
            {
                if (max_column < in_itr->first)
                {
                    max_column = in_itr->first;
                }

                if (min_column > in_itr->first)
                {
                    min_column = in_itr->first;
                }
            }
        }

        for (unsigned int i = min_row; i <= max_row; i++)
        {
            cout << i << ": ";
            for (unsigned int j = min_column; j <= max_column; j++)
            {
                if (board[i][j]==0)
                {
                    cout << "_";
                }
                else
                {
                    cout << board[i][j];
                }
            }
            cout << "\n";
        }
    };

    Board::~Board(){};
}