//
//  cell.cc
//  A4Q3
//
//  Created by Sun Renchen on 2013-07-09.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>
#include "cell.h"   
Cell::Cell()
{
    isAlive = false;
    numNeighbours = 0;
    numNeighbourAlive = 0;
    r = 0;
    c = 0;
    for (int i = 0; i < maxNeighbours; i++)
        neighbours[i] = NULL;
}

void Cell::addNeighbour(Cell* neighbour)
{
    neighbours[numNeighbours++] = neighbour;
}

void Cell::notify()
{
    numNeighbourAlive++;
}

void Cell::notifyNeighbours()
{
    if (isAlive)
    {
        for (int i = 0; i < numNeighbours; i++)
            neighbours[i]->notify();
    }
}

void Cell::setLiving()
{
    isAlive = true;
}

void Cell::recalculate()
{
    if (isAlive && (numNeighbourAlive < 2 || numNeighbourAlive > 3))
    {
        isAlive = false;
        undraw();
    }
    else if (isAlive && (numNeighbourAlive == 2 || numNeighbourAlive == 3))
        isAlive = true;
    else if (!isAlive && numNeighbourAlive == 3)
    {
        isAlive = true;
        draw();
    }
    else
        isAlive = false;
}

void Cell::resetNumNeiAlive()
{
    numNeighbourAlive = 0;
}

void Cell::notifyDisplay(TextDisplay &t)
{
    if (isAlive)
        t.notify(r, c, 'X');
    else
        t.notify(r, c, '_');
}

void Cell::setCoords(int r, int c, int x, int y, int width, int height, Xwindow* xw)
{
    this->r = r;
    this->c = c;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->xw = xw;
}

//Once called, it will draw a rectangle on the window
void Cell::draw()
{
    xw->fillRectangle(y, x, width, height, Xwindow::White);
}

//Once called, it will fill the rectangle with black which means it is a dead cell
void Cell::undraw()
{
    xw->fillRectangle(y, x, width, height, Xwindow::Black);
}
