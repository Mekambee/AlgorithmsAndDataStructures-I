CC = g++
CFLAGS = -Wall -std=c++11
OBJECTS = main.o 
TARGET = main.out

%.o : %.cpp Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) $(LIBS) $(OBJECTS) -o $(TARGET)
	./$@

.PHONY : clean

clean :
	$(RM) $(TARGET) *.o core