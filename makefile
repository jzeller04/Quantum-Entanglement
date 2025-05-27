# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -IC:/Libraries/SFML-3.0.0/include -Iinclude/engine -Iinclude/game -IC:/Libraries/ModernJson
LDFLAGS = -LC:/Libraries/SFML-3.0.0/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# Sources and target
SRC = main.cpp \
      src/engine/event/event.cpp \
      src/engine/event/testEvent.cpp \
      src/engine/listener/testListener.cpp \
      src/engine/listener/listener.cpp \
      src/engine/bus/eventBus.cpp \
      src/engine/listener/screenManager.cpp \
      src/engine/screen/menuScreen.cpp \
      src/engine/screen/screen.cpp \
      src/engine/screen/animatedScreen.cpp \
      src/engine/ui/button.cpp \
      src/engine/util/util.cpp \
      src/engine/event/screenEvent.cpp \
      src/engine/listener/lostEventListener.cpp \
      src/game/entity/entity.cpp \
      src/game/level/levelScreen.cpp \
      src/game/entity/player/playerEntity.cpp \
      src/engine/listener/soundListener.cpp \
      src/engine/event/soundEvent.cpp \
      src/engine/event/musicEvent.cpp \
      src/engine/listener/musicListener.cpp \
      src/game/save/playerData/playerData.cpp \
      src/game/quantumEntanglement.cpp \
      src/game/entity/particle/electron.cpp

TARGET = engine.exe

# Default rule
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

# Clean rule
clean:
	del /Q *.o *.exe 2>nul || true
