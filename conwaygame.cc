//
//  main.cpp
//  A4Q3
//
//  Created by Sun Renchen on 2013-07-09.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//  Game of Life consists of an n × n-grid of cells, each of which can be either alive or dead. When the game begins, we specify an initial configuration of living and dead cells. The game then moves through successive generations, in which cells can either die, come to life, or stay the same, according to the following rules:
//  • a living cell with fewer than two live neighbours or more than three live neighbours dies;
//  • a living cell with two or three live neighbours continues to live
//  • a dead cell with exactly three live neighbours comes to life; otherwise, it remains dead.
//  When you run your program, it will listen on stdin for commands. Your program must accept the following commands:
//  • new n Creates a new n × n grid, where n ≥ 1. If there was already an active grid, that grid is destroyed and replaced with the new one.
//  • init Enters initialization mode. Subsequently, read pairs of integers r c and set the cell at row r, column c as alive. The top-left corner is row 0, column 0. The coordinates -1 -1 end initialization mode. It is possible to enter initialization mode more than once, and even while the simulation is running.
//  • step Runs one tick of the simulation (i.e., transforms the grid into the immediately succeeding generation).
//  • steps n Runs n steps of the simulation.
//  • print Prints the grid.
//  The program quits when the input stream is exhausted.
//  Sample input:
//  new 5 init 12 22 32 -1 -1 print step print
//  Sample output: (with graphical display as well)
//  _____
//  __X__
//  __X__
//  __X__
//  _____
//  _____
//  _____
//  _XXX_
//  _____
//  _____

#include <iostream>
#include "textdisplay.h"
#include "grid.h"
#include "cell.h"
using namespace std;

int main(int argc, const char * argv[])
{
    Grid* g = new Grid;
    string command;
    while (cin >> command)
    {
        if (command == "new")
        {
            int size;
            cin >> size;
            g->init(size);
        }
        else if (command == "init")
        {
            int r,c;
            cin >> r >> c;
            while (r != -1 && c != -1)
            {
                g->turnOn(r, c);
                cin >> r >> c;
            }
        }
        else if (command == "step")
            g->tick();
        else if (command == "steps")
        {
            int time;
            cin >> time;
            for (int i = 0; i < time; i++)
                g->tick();
        }
        else
            cout << *g;
    }
    delete g;
    return 0;
}

