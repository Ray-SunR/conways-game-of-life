#Conway's Game of Life
Contributor: Renchen Sun

##Installation
1. Clone this repository to your local directory. 
2. In Xnix terminal
3. make

An executable conwaygame would be generated

For cleanning out those generated files:
**make clean**

###Note: Xlib is required for compiling this program

##Introduction
The Conway's Game of Life is composed by a n x n grid. In the begeinning of the game, we specify an initial cell. The game then moves in successive generations, in which cells can either come to live, die, or stay the same, according to the following rule:
1. a living cell with fewther than two live neighbours or more than three live neighbours dies
2. a living cell with two or three live neighbours continue to live
3. a dead cell with exactly three live neighbours comes to live; otherwise, it remains dead.

####Definition of neighbours: Neighbours are those cells that are immediately surround it. See the picture below for a deep understanding:

Demo: cell 'O' is surrounded by its 8 neighbours 'x'   
xxx
xOx
xxx 

##UML																											
																													
	----------------------------------------------      -------------------------------------------------			
    |  		           TextDisplay               |     |					  Cell 						|			
	----------------------------------------------		-------------------------------------------------			
	|					     					 |	   |					                            |<------------|
	|notify(r: integer, c: integer, ch: character|<>-->|	setLiving(void):void                        |			  |
	|				                             |     |	setCoords(r:integer, c:integer, max:integer)|			  |
	----------------------------------------------	   |	notifyDisplay(td:TextDisplay&)              |<>------------
			^										   |	resetNumNeiAlive()                          |
			|										   |	addNeighbour(neighbour: cell*)              |
			|										   |	notify()                                    |
			|										   |	notifyNeighbours()                          |
			|										   |	recalculate()                               |
		    |										    ------------------------------------------------	
		   <>														^
	 --------------------------------------------					|	
	|					Grid					|					|
	 --------------------------------------------					|
	|	init(n: integer)						|					|
	|	tick()									|<>------------------
	|	turnon(r:integer, c:integer)			|
	 --------------------------------------------
	 
	 
##Command
1. new n       
Creates a new n × n grid, where n ≥ 1. If there was already an active grid, that grid is destroyed and replaced with the new one.
2. init      
Enters initialization mode. Subsequently, read pairs of integers r c and set the cell at row r, column c as alive. The top-left corner is row 0, column 0. The coordinates -1 -1 end initialization mode. It is possible to enter initialization mode more than once, and even while the simulation is running.
3. step      
Runs one tick of the simulation (i.e., transforms the grid into the immediately succeeding generation).
4. steps n      
Runs n steps of the simulation.
5. print      
Prints the grid.	 

The program quits when the input stream is exhausted. You may assume that inputs are valid.


##Example
####Note:Italics are input
*new 5*      
*init*      
*12*     
*22*     
*32*      
*-1*      
*-1*      
*print*       
_____      
__X__      
__X__     
__X__      
_____       
*step*       
*print*       
_____       
_____      
_XXX_       
_____       
_____     
