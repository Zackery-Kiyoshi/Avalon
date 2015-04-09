#ifndef GAME
#define GAME

#include <algorithm>
#include <map>
#include <vector>
#include <random>

#include"Agent.h"

using std::map;
using std::pair;
using std::vector;
using std::pair;
using std::make_pair;

class Game {
private:
// Game Information
// why are these needed?
// static??????
static map<int, vector<int>> playerSplit;
static map<int, vector<int>> missionSplit;

map<int, vector<int>> playerSplit1;

// Localized per game
vector<Agent> players;
map<char, vector<int>> playerRoles;
int curPhase, curLead, curMiss, failedPasses, goodWin, evilWin;

// Agents will access via Game reference.
vector<int> curParty;

// Used to create logs
// TODO - Create Log Handlers
bool LogWritter;

// Methods used in setting up game flow
bool gameEnded();                                       // Done!
void nextPhase();                                       // Done!
void deliberate();                                      // Needs Work
void phase_createParty();                               // Done!
void phase_voteParty();                                 // Done!
void phase_voteMission();                               // Done!

// Misc. methods used for convience
void nextLeader();                                      // Done!
void setNew();                                          // Done!

public:

Game(vector<Agent> pys, vector<char> roles, int l);     // Needs Work
Game(vector<Agent> pys, vector<char> roles, map<int, char> fRole, int l); // Needs Work
void start();                                           // Needs Work
// changed to bool->int because thats what it is
const vector<int>& getCurParty();                      // Done!
const int reqFailed();                                  // Done!


// why maps?????

map<int, vector<int>> mymap;
mymap.insert( pair<int, vector<int>>(5, vector < int > { 3, 2 }) );

playerSplit1.insert( make_pair(5, vector < int > { 3, 2 }) );
playerSplit1.insert( pair<int, vector<int>>(6, vector < int > {4, 2}));

//		[6] = { 4, 2 };
map<int, vector<int>> Game::playerSplit[7] = { 4, 3 };
map<int, vector<int>> Game::playerSplit[8] = { 5, 3 };
map<int, vector<int>> Game::playerSplit[9] = { 6, 3 };
map<int, vector<int>> Game::playerSplit[10] = { 6, 4 };

map<int, vector<int>> Game::missionSplit[5] = { 2, 3, 2, 3, 3 };
map<int, vector<int>> Game::missionSplit[6] = { 2, 3, 4, 3, 4 };
map<int, vector<int>> Game::missionSplit[7] = { 2, 3, 3, 4, 4 };
map<int, vector<int>> Game::missionSplit[8] = { 3, 4, 4, 5, 5 };
map<int, vector<int>> Game::missionSplit[9] = { 3, 4, 4, 5, 5 };
map<int, vector<int>> Game::missionSplit[10] = { 3, 4, 4, 5, 5 };

};









map<int, vector<int>> Game::playerSplit[5] = { 3, 2 };
map<int, vector<int>> Game::playerSplit[6] = { 4, 2 };
map<int, vector<int>> Game::playerSplit[7] = { 4, 3 };
map<int, vector<int>> Game::playerSplit[8] = { 5, 3 };
map<int, vector<int>> Game::playerSplit[9] = { 6, 3 };
map<int, vector<int>> Game::playerSplit[10] = { 6, 4 };

map<int, vector<int>> Game::missionSplit[5] = { 2, 3, 2, 3, 3 };
map<int, vector<int>> Game::missionSplit[6] = { 2, 3, 4, 3, 4 };
map<int, vector<int>> Game::missionSplit[7] = { 2, 3, 3, 4, 4 };
map<int, vector<int>> Game::missionSplit[8] = { 3, 4, 4, 5, 5 };
map<int, vector<int>> Game::missionSplit[9] = { 3, 4, 4, 5, 5 };
map<int, vector<int>> Game::missionSplit[10] = { 3, 4, 4, 5, 5 };

bool Game::gameEnded() {
return (goodWin >= 3) || (evilWin >= 3) || (failedPasses >= 5);
}

void Game::nextPhase() {
switch (curPhase) {
case 0: phase_createParty(); break;
case 1: phase_voteParty(); break;
case 2: phase_voteMission(); break;
}
}

void Game::deliberate() {
// TODO - Create Deliberate Method
}

void Game::phase_createParty() {
curParty = players[curLead].createParty();
for (auto player : players) { player.reviewParty(); }
curPhase = 1;
}

void Game::phase_voteParty() {
vector<bool> votes;
for (auto player : players) {
votes.push_back(player.voteParty());
}
for (auto player : players) {
player.reviewPartyResults(votes);
}
int countTrue = count_if(votes.begin(), votes.end(), [](bool b){ return b; });
if (countTrue >= players.size() / 2 + 1) {
failedPasses = 0; // curState = 2;
}
else {
failedPasses += 1; // curState = 1;
nextLeader();
}
}

void Game::phase_voteMission() {
vector<int> votes(2); // votes[0] = #Success, votes[1] = #Fail
for (auto p : curParty) {
if (players[p].voteMission())
votes[0] += 1;
else
votes[1] += 1;
}
for (auto player : players) { player.reviewMissionResults(votes); }
if (votes[1] >= reqFailed())
evilWin += 1;
else
goodWin += 1;
curPhase = 0;
}

void Game::nextLeader() {
if (curLead >= players.size() - 1)
curLead = 0;
else
curLead += 1;
}

void Game::setNew() {
curPhase = curMiss = failedPasses = goodWin = evilWin = 0;
}

// PUBLIC FUNCTIONS

// TODO - Look up Constructor Delegation
Game::Game(vector<Agent> pys, vector<char> roles = { 'M', 'A' }, int l = -1) {

setNew();
players = pys;
if (l == -1) {
std::default_random_engine generator;
std::uniform_int_distribution<int> roll(0, players.size() - 1);
curLead = roll(generator);
}
else
curLead = l;

// Assign roles randomly
vector<int> plyDeck;
for (int x = 0; x < players.size(); ++x) plyDeck.push_back(x);
std::random_shuffle(plyDeck.begin(), plyDeck.end());

playerRoles['+'] = {};
playerRoles['-'] = {};

while (!roles.empty()) {
int p = plyDeck.back(); plyDeck.pop_back();
char c = roles.back(); roles.pop_back();
switch (c) {
case 'M': // Merlin
case 'P': // Percival
case 'G': playerRoles['+'].push_back(p); break; // generic Good
case 'A': // Assassin
// changed from G to R
case 'R': // morGana
case 'D': // morDred
case 'O': // Oberron
case 'E': playerRoles['-'].push_back(p); break; // generic Evil
}
players[p].setRole(c);
if (playerRoles.find(c) != playerRoles.end())
playerRoles[c].push_back(p);
else
playerRoles[c] = { p };
}

vector<vector<int>> evilPlayers;
for (int p : playerRoles['-']) {
vector<int> tmp(players.size());
}

// Assign Knowledge
if (playerRoles.find('M') != playerRoles.end()) {
// TODO - Create 2D Vector Of Evil. Don't forget to remove Mordred!
if (playerRoles.find('D') != playerRoles.end()) {

}
}
if (playerRoles.find('P') != playerRoles.end()) {
// TODO - Create 2D Vector of Morgana + Merlin
}
for (int p : playerRoles['-']) {
// TODO - Pass and Create Vector of Evil. Don't forget to remove Oberron!
}

}

void Game::start() {
while (!gameEnded()) {
deliberate();
nextPhase();
}
// TODO - Review results of game.
}

// changed to bool->int because thats what it is
const vector<int>& Game::getCurParty() {
return curParty;
}

const int Game::reqFailed() {
if (curMiss == 3 && players.size() >= 7)
return 2;
else
return 1;
}



#endif // !D
