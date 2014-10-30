LDLIBS=-lglut -lGLEW -lGL -lSOIL 
CFLAGs=-c -Wall -g -O
SRC= render.cpp main.cpp geometry.cpp scene.cpp view.cpp
OBJ=$(SRC:.cpp=.o)
EXE=triangle

#all: $(SRC) $(EXE)
	
#$(EXE): $(OBJ)
#		g++ -o $@ $(LDLIBS) $(OBJ) 
#.cpp.o:
#	g++ $(CFLAGS) $< -o $@


#triangle: ../common/shader_utils.o

all:
	g++ $(SRC) $(CFLAGS) $(LDLIBS) -o $(EXE) common/shader_utils.o 

clean:
	rm -f *.o $(EXE)

.PHONY: all clean
