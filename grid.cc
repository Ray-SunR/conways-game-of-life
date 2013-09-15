//
//  grid.cpp
//  A4Q3
//
//  Created by Sun Renchen on 2013-07-09.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include "grid.h"
#include "textdisplay.h"
#include <iostream>
using namespace std;

Grid::Grid()
{
    theGrid = NULL;
    gridSize = 0;
    td = NULL;
    xw = NULL;
}

Grid::~Grid()
{
    clearGrid();
}

void Grid::clearGrid()
{
    delete td; // will call the destructor of TextDisplay
    delete xw;
    xw = NULL;
    td = NULL;
    for (int i = 0; i < gridSize; i++)
        delete theGrid[i];
    gridSize = 0;
    delete [] theGrid;
    theGrid = NULL;
}

void Grid::init(int n)
{
    if (gridSize) // clear grid if the grid existed.
        clearGrid();
    xw = new Xwindow;
    xw->fillRectangle(0, 0, 500, 500,Xwindow:: Black); //Set the background color to black
    gridSize = n;
    int width = 500 / n;//calculate the width and height of each pixel
    int height = width;
    td = new TextDisplay(gridSize); // initialize the TextDesiplay Pointer
    
    theGrid = new Cell* [gridSize]; // create a new grid.
    for (int i = 0; i < gridSize; i++)
        theGrid[i] = new Cell[gridSize]; // Will call the defualt constructor of Cell
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
        {
            
            theGrid[i][j].setCoords(i, j, i * height, j * width, height, width, xw);
            if (gridSize == 1)
                continue;
            if (gridSize == 2)
            {
                theGrid[0][0].addNeighbour(&theGrid[0][1]);
                theGrid[0][0].addNeighbour(&theGrid[1][0]);
                theGrid[0][0].addNeighbour(&theGrid[1][1]);
                theGrid[0][1].addNeighbour(&theGrid[0][0]);
                theGrid[0][1].addNeighbour(&theGrid[1][0]);
                theGrid[0][1].addNeighbour(&theGrid[1][1]);
                theGrid[1][0].addNeighbour(&theGrid[0][0]);
                theGrid[1][0].addNeighbour(&theGrid[0][1]);
                theGrid[1][0].addNeighbour(&theGrid[1][1]);
                theGrid[1][1].addNeighbour(&theGrid[0][0]);
                theGrid[1][1].addNeighbour(&theGrid[0][1]);
                theGrid[1][1].addNeighbour(&theGrid[1][1]);
                continue;
            }
            //Normal case
            if (i == 0 && j == 0)
            {
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j]);
            }
            else if (i == 0 && j == gridSize - 1)
            {
                theGrid[i][j].addNeighbour(&theGrid[i][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j - 1]);
            }
            else if (i == gridSize - 1 && j == 0)
            {
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j + 1]);
            }
            else if (i == gridSize - 1 && j == gridSize - 1)
            {
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j - 1]);
            }
            else if (i != 0 && i != gridSize - 1 && j == 0)
            {
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j + 1]);
            }
            else if (i == 0 && j != 0 && j != gridSize - 1)
            {
                theGrid[i][j].addNeighbour(&theGrid[i][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j + 1]);
            }
            else if (i == gridSize - 1 && j != 0 && j != gridSize - 1)
            {
                theGrid[i][j].addNeighbour(&theGrid[i][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j + 1]);
            }
            else if (j == gridSize - 1 && i != 0 && i != gridSize - 1)
            {
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j - 1]);
            }
            else
            {
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i - 1][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i][j + 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j - 1]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j]);
                theGrid[i][j].addNeighbour(&theGrid[i + 1][j + 1]);
            }
        }

}

//Once a cell has been turned on, it will be drawed on the window
void Grid::turnOn(int r, int c)
{
    theGrid[r][c].setLiving();
    theGrid[r][c].notifyDisplay(*td);
    theGrid[r][c].draw();
}

void Grid::tick()
{
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
            theGrid[i][j].resetNumNeiAlive();
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
            theGrid[i][j].notifyNeighbours();
    for (int i = 0; i < gridSize; i++)
        for (int j = 0; j < gridSize; j++)
        {
            theGrid[i][j].recalculate();
            theGrid[i][j].notifyDisplay(*td);
        }
}

ostream& operator<<(ostream& out, const Grid& g)
{
    if (g.td)
        return out << *(g.td);
    return out;
}

