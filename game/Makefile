TARGETS=game
CXXFLAGS=-g -Iinclude -Itermplay/include
CXX=g++
LD=g++
LDFLAGS=
LDLIBS=termplay/lib/libtermplay.a

LIB_OBJ=termplay/lib/keyboard.o \
        termplay/lib/terminal.o \
	    termplay/lib/thing.o \
	    termplay/lib/movingThing.o \
		termplay/lib/game.o\

OBJ=

all: $(TARGETS)
game: src/main.o $(OBJ) $(LDLIBS)
	$(CXX) -o $@ src/main.o $(OBJ) $(LIB_OBJ) $(LDFLAGS) $(LDLIBS)

src/main.o: src/main.cpp $(OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

termplay/lib/terminal.o: termplay/lib/terminal.cpp termplay/include/terminal.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

termplay/lib/libtermplay.a: $(LIB_OBJ)
	rm -f $@
	ar rcs $@ $(LIB_OBJ)


clean:
	rm -f $(TARGETS) a.out src/*.o termplay/lib/*.o termplay/lib/*.a