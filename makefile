# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -IC:/Libraries/SFML-3.0.0/include -Iinclude
LDFLAGS = -LC:/Libraries/SFML-3.0.0/lib -lsfml-graphics -lsfml-window -lsfml-system

# Sources and target
SRC = main.cpp \
      src/event/event.cpp \
      src/event/testEvent.cpp \
      src/listener/testListener.cpp \
      src/listener/listener.cpp \
      src/bus/eventBus.cpp \
      src/listener/screenManager.cpp \
      src/screen/menuScreen.cpp \
      src/screen/gameScreen.cpp \
      src/screen/screen.cpp \
      src/screen/animatedScreen.cpp \
      src/ui/button.cpp \
      src/util/util.cpp \
      src/event/screenEvent.cpp \
      src/listener/lostEventListener.cpp

TARGET = engine.exe

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

# Clean rule
clean:
	del /Q *.o *.exe 2>nul || true
