CC = -std=c++17
GXX = g++
TARGET = run

$(TARGET): test.cpp
	$(GXX) -o $@ $(CC) $^

.PHONY:
clean:
	rm -r $(TARGET)