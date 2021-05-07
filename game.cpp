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
	bool debug = true;
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
		else if(tmp == "-d"){
			debug = true;
		}
	}
	if(invalidArg){
		cout << "Invalid arguments" << endl;
		//TODO write something meaningful
		return 0;
	}

	GameClient& client = GameClient::createInstance(debug);
	
	if(client.Construct(512, 400, 2, 2)){
		client.Start();
	}
	return 0;
}
