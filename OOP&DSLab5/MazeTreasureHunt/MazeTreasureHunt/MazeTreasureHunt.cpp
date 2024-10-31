#include "MazeTreasureHunt.h" 
using namespace std;

const int W = 70;
const int H = 20;

TreasureHunt::TreasureHunt(const string& filename) {
    srand(static_cast<unsigned>(time(0))); // Initialize the random number generator
    loadMap(filename);

    // Randomize player position within the map boundaries
    do {
        playerX = 21;
        playerY = 3;
    } while (map[playerY][playerX] != ' '); // Ensure the player starts in an empty space

    // Find treasure position on the map
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (map[y][x] == '$') {
                treasureX = x;
                treasureY = y;
                break;
            }
        }
    }
}

void TreasureHunt::loadMap(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening map file." << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        if (line.size() >= W) {
            map.push_back(line.substr(0, W)); // Store only the first W characters
        }
        else {
            line.resize(W, ' ');
            map.push_back(line);
        }
    }

    // Fill the rest of the map if there are fewer than H lines
    while (map.size() < H) {
        map.push_back(string(W, ' '));
    }

    file.close();
}

void TreasureHunt::drawPositions() {
    system("cls"); // Clear screen after every input
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (x == playerX && y == playerY) {
                cout << "M"; // Player character
            }
            else if (x == treasureX+2 && y == treasureY+5) {
                cout << "$"; // Collectible item
            }
            else {
                cout << map[y][x]; // Map character
            }
        }
        cout << endl;
    }
}

void TreasureHunt::updatePositions(char input) {
    switch (input) {
    case 'w': case 'W':
        if (playerY > 0 && map[playerY - 1][playerX] == ' ') playerY--;
        break;
    case 's': case 'S':
        if (playerY < H - 1 && map[playerY + 1][playerX] == ' ') playerY++;
        break;
    case 'a': case 'A':
        if (playerX > 0 && map[playerY][playerX - 1] == ' ') playerX--;
        break;
    case 'd': case 'D':
        if (playerX < W - 1 && map[playerY][playerX + 1] == ' ') playerX++;
        break;
    }
}

bool TreasureHunt::checkWin() const {
    return playerX == treasureX+2 && playerY == treasureY+5;
}

void TreasureHunt::startTreasureHunt() {
    char input;
    do {
        drawPositions();
        input = _getch(); // Get user input without waiting for Enter key
        updatePositions(input);
        if (checkWin()) {
            system("cls");
            cout << "WINNER WINNER CHICKEN DINNER YOU GOT THE TREASURE!" << endl;
            break;
        }
    } while (input != 'q');
}

int main() {
    TreasureHunt TreasureHunt("Maze.txt");
    TreasureHunt.startTreasureHunt();
    return 0;
}
