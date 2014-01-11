XX = g++
CXXFLAGS = -Wall -MMD -L/usr/X11R6/lib -lX11
EXEC = conwaygame
OBJECTS = conwaygame.o cell.o grid.o window.o textdisplay.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
 
.PHONY: clean
