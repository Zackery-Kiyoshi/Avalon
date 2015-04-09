
#include<iostream>
#include<algorithm>
#include<utility>
#include<tuple>
#include<vector>
#include<string>
#include<queue>
#include <functional>

#include <chrono>
#include <random>

#include"Player.h"
#include"myCode.h"
#include"GameRatio.h"

using std::vector;
using std::pair;
using std::tuple;
using std::string;

using std::make_pair;

using std::cout;
using std::endl;
using std::cin;

struct Game{

	vector<Player> players;
	GameRatio g;


	Game(vector<Player> p, GameRatio G){
		g = G;
		players = p;
	}

};




void main() {

	/*
	int toTesti = 10;
	for (int i = 0; i < toTesti; ++i){
		int roll = distribution(generator);
		cout << i << ": " << roll << endl;
	}
	*/

	/*

	Player pre();
	Role r;

	// pre.printStatus();
	r.print();
//	*/


	int disi = 10;
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, disi);
	int numPlayers = abs((distribution(generator) % 5)) + 5;
	int t = distribution(generator) % numPlayers;

	cout << "number of Players: " << numPlayers << endl;
	cout << "	for now this is set to 5" << endl;
	cout << endl;

	cout << endl;
	system("Pause");
	cout << endl;

	cout << "Enter your name: ";
	string a = "";
	cin >> a;

	Player me(a);

	cout << "Hello " << a << endl;
	cout << "Printing your Status" << endl;
	me.printStatus();

	/*

	Role custom("THE BOSS", "YEE", 0);
	me.changeRole(custom);
	me.changeLeader();
	
	cout << "Printing your Status" << endl;
	me.printStatus();

	//	*/

	cout << endl;
	system("Pause");
	cout << endl;


	// makes the players
	vector<Player> P{};
	Player josh("Josh");
	Player issac("Issac");
	Player jeff("Jeff");
	Player zach("Zach");
	Player clay("Clay");
	Player ali("Ali");
	Player mat("Elaine");

	P.push_back(josh);
	P.push_back(issac);
	P.push_back(jeff);
	P.push_back(zach);
	P.push_back(clay);
	P.push_back(ali);
	P.push_back(mat);
	P.push_back(me);

	// choose gameratio based on number of players
	//		possibly random not always the recomended one?
	//	(good,bad), normal Good, normal Bad, Merlin, Percival, Morgana, Mordred, Oberon, Assassian
	/*
	Players	5	6	7	8	9	10
	Good	3	4	4	5	6	6
	Evil	2	2	3	3	3	4
	*/
	// GameRatio gameratio1{ make_pair(good,bad),
	//	normal Good, normal Bad, Merlin, Percival, Morgana, Mordred, Oberon, Assassian  };

	GameRatio gameratio1;
	numPlayers = 5;

	if(5 == numPlayers) gameratio1 = GameRatio{ make_pair(3, 2), 1, 0, 1, 1, 1, 0, 0, 1 };
	if(6 == numPlayers) gameratio1 = GameRatio{ make_pair(4, 2), 1, 0, 1, 1, 1, 0, 0, 1 };
	if(7 == numPlayers) gameratio1 = GameRatio{ make_pair(4, 3), 1, 0, 1, 1, 1, 0, 0, 1 };
	if(8 == numPlayers) gameratio1 = GameRatio{ make_pair(5, 3), 1, 0, 1, 1, 1, 0, 0, 1 };
	if(9 == numPlayers) gameratio1 = GameRatio{ make_pair(6, 3), 1, 0, 1, 1, 1, 0, 0, 1 };
	if(10== numPlayers) gameratio1 = GameRatio{ make_pair(6, 4), 1, 0, 1, 1, 1, 0, 0, 1 };

	//	explain the game with the current roles in play
	explainGame(gameratio1);

	cout << endl;
	system("Pause");

	/*

	Number of people on each quest
	Players	5	6	7	8	9	10
	1st Q	2	2	2	3	3	3
	2nd Q	3	3	3	4	4	4
	3rd Q	2	4	3	4	4	4
	4th Q*	3	3	4	5	5	5
	5th Q	3	4	4	5	5	5

	*/

	runSetup(gameratio1, P);

	// make Game

	Game theGame(P, gameratio1);
	//theGame.round();

	cout << endl;
	system("Pause");

	//	the thumb thing
	revealStage(gameratio1);

	cout << endl;
	system("Pause");

	cout << endl;
	cout << endl;
	cout << endl;

	cout << "Print everyone status: "<< endl;
	cout << "Print everyone status: " << endl;
	cout << "Print everyone status: " << endl;
	cout << "Print everyone status: " << endl;
	cout << "Print everyone status: " << endl;

	me.printStatus();
	jeff.printStatus();
	ali.printStatus();
	zach.printStatus();
	mat.printStatus();
	clay.printStatus();
	josh.printStatus();
	issac.printStatus();

	cout << endl;
	system("Pause");

}



