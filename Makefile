TARGET = chess

CC = g++ -std=c++14
CXXFLAGS =
#CXXFLAGS += -Wall 
#CXXFLAGS += -Wextra
#CXXFLAGS += -predantic 

LFLAGS = -Wall -l m

MD  = mkdir -p


SRC_DIR = src
INC_DIR = include
BIN_DIR = bin
BUILD_DIR = obj

SRC_EXT = cpp
OBJ_EXT = o

INC = $(shell find $(INC_DIR) -type d)

SOURCES = $(shell find $(SRC_DIR) -type f -name "*.$(SRC_EXT)")
INCLUDES = $(patsubst %, -I%, $(INC))
OBJECTS = $(patsubst $(SRC_DIR)/%.$(SRC_EXT), $(BUILD_DIR)/%.$(OBJ_EXT), $(SOURCES))

SRC_DIRS = $(shell find $(SRC_DIR) -type d)
OBJ_DIRS = $(patsubst $(SRC_DIR)%, $(BUILD_DIR)%, $(SRC_DIRS))


# LINKING
$(TARGET) : $(OBJECTS)
	@$(MD) $(BIN_DIR)
	@$(CC) -o $(BIN_DIR)/$(TARGET) $^ $(LFLAGS)

# COMPILING
$(BUILD_DIR)/%.$(OBJ_EXT) : $(SRC_DIR)/%.$(SRC_EXT)
	@$(MD) $(OBJ_DIRS)
	@$(CC) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@echo Removing /$(BUILD_DIR) directory and all of its content.
	@$(RM) -rf $(BUILD_DIR)

cleaner: clean
	@echo Removing executables from /$(BIN_DIR)
	@$(RM) $(BIN_DIR)/*.exe

