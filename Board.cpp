#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <iterator>
#include "Direction.hpp"
#include "Board.hpp"
using namespace ariel;
using namespace std;

namespace ariel
{
    Board::Board(){};

    void Board::post(unsigned int row, unsigned int column, Direction d, string const &s)
    {   //post horizontal strings
        if (d == Direction::Horizontal)
        {
            for (size_t i = 0; i < s.length(); i++)
            {
                board[row][column + i] = s.at(i);
            }
        }
        //post vertical strings
        if (d == Direction::Vertical)
        {
            for (size_t i = 0; i < s.length(); i++)
            {
                board[row + i][column] = s.at(i);
            }
        }
    };

    string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int num)
    {
        string s;
        //reads horizontal strings
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

        //reads vertical strings
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
         
        //determine the exact borders of the board
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

        //prints chars, otherwise prints underscores.

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