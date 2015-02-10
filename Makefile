CPPFLAGS = -g -Wall -O2
AITester: main.o BoardV2.o Message.o PlayerV1.o AITester.o \
	CleanPlayer.o OrigGamblerPlayer.o HumanPlayer.o MyPlaya.o
	g++ $(CPPFLAGS) -o AITester main.o BoardV2.o Message.o PlayerV1.o AITester.o \
	CleanPlayer.o OrigGamblerPlayer.o HumanPlayer.o MyPlaya.o
	@echo "Executable is 'AITester'"

clean:
	rm -f AITester *.o

main.o: main.cpp BoardV2.h AITester.h Message.h defines.h PlayerV1.h 
	g++ $(CPPFLAGS) -c main.cpp
	
BoardV2.o: 
	@echo "Getting BoardV2.o from your binaries.tar ... "
	tar xvf binaries.tar BoardV2.o
	#g++ $(CPPFLAGS) -c BoardV2.cpp
Message.o: Message.cpp Message.h defines.h
PlayerV1.o: PlayerV1.cpp PlayerV1.h Message.h defines.h
AITester.o: 
	@echo "Getting AITester.o from your binaries.tar ... "
	tar xvf binaries.tar AITester.o
MyPlaya.o: MyPlaya.cpp MyPlaya.h PlayerV1.h Message.h defines.h
CleanPlayer.o: 
	@echo "Getting CleanPlayer.o from your binaries.tar ... "
	tar xvf binaries.tar CleanPlayer.o
OrigGamblerPlayer.o: 
	@echo "Getting OrigGamblerPlayer.o from your binaries.tar ... "
	tar xvf binaries.tar OrigGamblerPlayer.o
HumanPlayer.o: HumanPlayer.cpp HumanPlayer.h PlayerV1.h Message.h defines.h
