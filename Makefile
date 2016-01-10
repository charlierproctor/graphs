# specify compiler and flags
CXX = g++
CXXFLAGS = -ggdb3 -std=c++11 -Wall -MMD 

# define the directories
BUILD_DIR = build
SRC_DIR = src
INC_DIR = include

# our target executable
TARGET = bin/graph

# calculate SRCS and OBJS
SRCS = $(shell find $(SRC_DIR) -type f -name *.cpp)
OBJS = $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRCS:.cpp=.o))

# create the target from the objects
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(TARGET)

# create the objects from the source files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c -o $@ $<

# clean: remove the build/* and target.
clean:
	$(RM) -r $(BUILD_DIR) $(TARGET)

# include generated dependences (build/*.d)
-include $(OBJS:%.o=%.d)

