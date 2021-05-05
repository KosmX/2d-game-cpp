#define OLC_PGE_APPLICATION
#define OLC_PGEX_TRANSFORMEDVIEW
#include "olcPixelGameEngine.h"
#include "mainGame.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	cout << argv[0] << endl;
	
	bool invalidArg = false;
	for(int i = 0; i < argc; i++){
		std::string tmp(argv[i]);
		if(tmp == "-r" || tmp == "--resource"){
			if(i + 1 < argc){
				cout << "O.K. I'll read it, but //TODO" << endl;
				//TODO
			}
			else{
				invalidArg = true;
			}
		}
	}
	if(invalidArg){
		cout << "Invalid arguments" << endl;
		//TODO write something meaningful
	}

	GameClient::createInstance();

	GameClient& client = GameClient::createInstance();
	
	if(client.Construct(256, 240, 4, 4)){
		client.Start();
	}
	return 0;
}
