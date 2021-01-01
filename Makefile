
CXX = clang++
CXXFLAGS = -std=c++17 -Wall

LDLIBS = $(shell pkg-config --libs gtkmm-3.0)
INCLUDE = $(shell pkg-config --cflags gtkmm-3.0)

APPSOURCES = main.cpp todoapp.cpp
TESTSOURCES = todoTest.cpp
COMMONSOURCES = todo.cpp todoentry.cpp

APP=todo
TEST=testTodo


APPOBJECTS = ${APPSOURCES:.cpp=.o}
TESTOBJECTS = ${TESTSOURCES:.cpp=.o}
COMMONOBJECTS = ${COMMONSOURCES:.cpp=.o}

CLEANFILES = ${APP} ${APOOBJECTS} ${TESTOBJECTS} ${COMMONOBJECTS}

build: clean $(APPOBJECTS) $(COMMONOBJECTS)
	$(CXX) $(APPOBJECTS) $(COMMONOBJECTS) $(LDLIBS) -o $(APP)

test: clean $(TESTOBJECTS) $(COMMONOBJECTS)
	$(CXX) $(TESTOBJECTS) $(COMMONOBJECTS) -o $(TEST)

${APPOBJECTS}:	%.o: %.cpp
	$(CXX) $(INCLUDE) $(CXXFLAGS) -c $< -o $@

${TESTOBJECTS}:	%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

${COMMONOBJECTS}:	%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run:	$(APP)
	./$(APP)

clean:
	rm -rf $(CLEANFILES)
