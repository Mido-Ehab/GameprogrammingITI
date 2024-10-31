#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;

class TreasureHunt {
public:
    TreasureHunt(const std::string& filename);
    void startTreasureHunt();

private:
    void loadMap(const std::string& filename);
    void drawPositions();
    void updatePositions(char input);
    bool checkWin() const;

    vector<string> map;
    int playerX, playerY;
    int treasureX, treasureY;
};
