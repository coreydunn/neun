CXXFLAGS=  -Wfatal-errors
CFLAGS=    -Wfatal-errors
LDFLAGS=   -s
OBJS=      csv.o nn.o

all: nn
nn: main.o $(OBJS)
	$(CXX) $^ -o $@ $(CXXFLAGS)
%.o: %.cc
	$(CXX) -c $^ $(CXXFLAGS)
clean:
	$(RM) *.o nn
