// #pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <map>
#include "Direction.hpp"

using namespace std;

namespace ariel
{
    class Board
    {
    private:
        map<unsigned int,map<unsigned int,char>> board;

    public:
        Board();
        ~Board();
        void post(unsigned int row, unsigned int column, Direction d, string const &s);
        string read(unsigned int row, unsigned int column, Direction d, unsigned int num);
        string show();
    };
}