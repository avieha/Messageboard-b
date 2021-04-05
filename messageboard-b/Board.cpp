#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <iterator>
#include "Direction.hpp"
#include "Board.hpp"
using ariel::Direction;
using namespace std;

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
                    if (board[row][column + i])
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
                    if (board[row + i][column])
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

    string Board::show() { return "show"; };
 
    Board::~Board(){};
}