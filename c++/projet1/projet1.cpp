#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>



using namespace std;

class Character {
public:
    Character(string name, int health, int attack) : name(name), health(health), attack(attack) {}
    void takeDamage(int damage) {
        health -= damage;
    }
    bool isAlive() {
        return health > 0;
    }
    int getAttack() {
        return attack;
    }
    string getName() {
        return name;
    }
    int getHealth() {
        return health;
    }
    int generateRandomDamage() {
        return rand() % (attack / 2) + attack / 2;
    }

private:
    string name;
    int health;
    int attack;
};

void battle(Character& player, Character& enemy) {
    int playerDamage = player.generateRandomDamage();
    int enemyDamage = enemy.generateRandomDamage();

    if (player.isAlive() && enemy.isAlive()) {
        cout << player.getName() << " (Health: " << player.getHealth() << ") attacks " << enemy.getName() << " for " << playerDamage << " damage." << endl;
        enemy.takeDamage(playerDamage);
        if (!enemy.isAlive()) {
            cout <<" GG EZ "<< enemy.getName() << " has been defeated!" << endl;
            exit(1);
        }

        cout << enemy.getName() << " (Health: " << enemy.getHealth() << ") attacks " << player.getName() << " for " << enemyDamage << " damage." << endl;
        player.takeDamage(enemyDamage);
        if (!player.isAlive()) {
            cout << " noooo by your fault "<< player.getName() << " has been defeated! poor" << player.getName() << endl;
            exit(1);
        }
    }
}

void block(Character& player, Character& enemy){
    int enemyDamage = enemy.generateRandomDamage();
    int playerBlock = enemyDamage / 2;

    if (player.isAlive() && enemy.isAlive()) {
        cout << enemy.getName() << " (Health: " << enemy.getHealth() << ") attacks " << player.getName() << " for " << playerBlock << " damage." << endl;
        player.takeDamage(enemyDamage - playerBlock);
        if (!player.isAlive()) {
            cout << " noooo by your fault "<< player.getName() << " has been defeated! poor" << player.getName() << endl;
            exit(1);
        }
    }

}



int main() {
    srand(time(nullptr));

    Character player("jaque", 100, 20);
    Character enemy("juan", 100, 20);

    cout << "time to fight" << endl;

    while (player.isAlive() && enemy.isAlive()) {
        cout << "---------------------------------" << endl;
        cout << player.getName() << " (Health: " << player.getHealth() << ") vs. " << enemy.getName() << " (Health: " << enemy.getHealth() << ")" << endl;
        cout << "1. Attack" << endl;
        cout << "2. block" << endl;
        cout << "Choose your action: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                battle(player, enemy);
                break;
            case 2:
                block(player, enemy);
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
    return 0;
}
