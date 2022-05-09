
all: jazz

jazz: main.cpp realbook.h
	g++ -Wall main.cpp -o jazz

evshow: evshow.cpp
	g++ -Wall evshow.cpp -o evshow

clean:
	
