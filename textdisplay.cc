//
//  textdisplay.cc
//  A4Q3
//
//  Created by Sun Renchen on 2013-07-09.
//  Copyright (c) 2013 University of Waterloo. All rights reserved.
//

#include <iostream>
#include "textdisplay.h"
using namespace std;
TextDisplay::TextDisplay(int n): gridSize(n),i(0),j(0)
{
    theDisplay = new char* [n];
    for (int i = 0; i < n; i++)
    {
        theDisplay[i] = new char[n];
        for (int j = 0; j < n; j++)
            theDisplay[i][j] = '_';
    }
}

void TextDisplay::notify(int r, int c, char ch)
{
    theDisplay[r][c] = ch;
}

TextDisplay::~TextDisplay()
{
    for (int i = 0; i < gridSize; i++)
        delete theDisplay[i];
    delete [] theDisplay;
}

ostream& operator<< (ostream& out, const TextDisplay& td)
{
    for (int i = 0; i < td.gridSize; i++)
    {
        for (int j = 0; j < td.gridSize; j++)
            out << td.theDisplay[i][j];
        out << endl;
    }
    return out;
}
