#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
#include <random>

using namespace std;
using namespace sf;
using namespace sfp;

int gridSize = 10;
int windowSize = 500;
int cellSize = windowSize / gridSize;

int main() {
    RenderWindow window(VideoMode(windowSize, windowSize), "Kaitlyn's Game of Life");
    World world(Vector2f(0, 1));

	
    //Make vector
    vector<vector<RectangleShape>> cells(gridSize, vector<RectangleShape>(gridSize));

    //Add cells
    for (int a = 0; a < gridSize; a++) {
        for (int b = 0; b < gridSize; b++) {
            cells[a][b].setSize(Vector2f(cellSize, cellSize));
            cells[a][b].setPosition(a * cellSize, b * cellSize);
            cells[a][b].setFillColor(sf::Color::White);
        }
    }

    //Opens window
    while (window.isOpen()) {

        for (int a = 0; a < gridSize; a++) {
            for (int b = 0; b < gridSize; b++) {
                window.draw(cells[a][b]);
            }
        }
    }
}