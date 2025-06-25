CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Add include directories
INCLUDES = -I. -Icore -Iui -Imodes -Icommand -Isyntax -Iplugin -Iutil

SRC = \
    main.cpp \
    core/editor.cpp core/buffer.cpp \
    ui/opengl_screen.cpp \
	ui/opengl_screen.o  \
    modes/mode_handler.cpp \
    command/command_parser.cpp \
    syntax/highlighter.cpp \
    plugin/plugin_manager.cpp \
    util/logger.cpp

OBJ = $(SRC:.cpp=.o)
TARGET = TextEditor

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
