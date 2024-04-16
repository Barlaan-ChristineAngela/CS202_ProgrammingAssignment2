carnivalComplete: driver.o patron.o worldTour.o teacups.o magicCarpet.o ride.o dollars.o ariarys.o
	g++ -o carnivalComplete driver.o patron.o worldTour.o teacups.o magicCarpet.o ride.o dollars.o ariarys.o
driver.o: driver.cpp patron.h calculator.h
	g++ -c driver.cpp
worldTour.o: worldTour.cpp worldTour.h ride.h
	g++ -c worldTour.cpp
teacups.o: teacups.cpp teacups.h ride.h
	g++ -c teacups.cpp
magicCarpet.o: magicCarpet.cpp magicCarpet.h ride.h
	g++ -c magicCarpet.cpp
ride.o: ride.cpp ride.h
	g++ -c ride.cpp
dollars.o: dollars.cpp dollars.h calculator.h
	g++ -c dollars.cpp
ariarys.o: ariarys.cpp ariarys.h calculator.h
	g++ -c ariarys.cpp
patron.o: patron.cpp patron.h ride.h magicCarpet.h teacups.h worldTour.h dollars.h ariarys.h calculator.h
	g++ -c patron.cpp
clean:
	rm *.o carnivalComplete