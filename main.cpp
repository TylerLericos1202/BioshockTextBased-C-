
/*
* Tyler Lericos
* Bioshock
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to print the game's introduction
void printIntroduction() {
    cout << "Welcome to BioShock Text Adventure!" << endl;
    cout << "You find yourself in the underwater city of Rapture." << endl;
    cout << "Your goal is to survive and uncover the mysteries of this city." << endl;
    cout << "Be careful, danger lurks around every corner." << endl;
    cout << "--------------------------------------------" << endl;
}

// Function to simulate a combat encounter
bool combat() {
    int playerHealth = 100;
    int enemyHealth = 50;

    cout << "You encounter a Splicer! Prepare for combat!" << endl;

    while (playerHealth > 0 && enemyHealth > 0) {
        // Player attacks
        int playerAttack = rand() % 20 + 10;
        enemyHealth -= playerAttack;
        cout << "You attack the Splicer dealing " << playerAttack << " damage. Splicer's health: " << enemyHealth << endl;
        
        // Check if enemy is defeated
        if (enemyHealth <= 0) {
            cout << "You defeated the Splicer!" << endl;
            return true;
        }

        // Enemy attacks
        int enemyAttack = rand() % 15 + 5;
        playerHealth -= enemyAttack;
        cout << "The Splicer attacks you dealing " << enemyAttack << " damage. Your health: " << playerHealth << endl;

        // Check if player is defeated
        if (playerHealth <= 0) {
            cout << "You were defeated by the Splicer!" << endl;
            return false;
        }
    }
    return false;
}

// Function to handle player movement
void move() {
    int choice;
    cout << "Choices" << endl;
    cout << "1. Explore the area" << endl;
    cout << "2. Search" << endl;
    cout << "3. Rest" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "You explore the area and find some interesting objects." << endl;
            break;
        case 2:
            cout << "You search for supplies but find nothing useful." << endl;
            break;
        case 3:
            cout << "You decide to rest and regain some health." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            move();
            break;
    }
}

int main() {
    srand(time(0)); // Seed random number generator

    

    printIntroduction();

    bool alive = true;
    while (alive) {
        move();
        alive = combat();
    }

    cout << "Game over! Thanks for playing BioShock Text Adventure!" << endl;

    return 0;
}
