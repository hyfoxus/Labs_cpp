//
// Created by Gleb Nemirko on 21.11.2022.
//

#include "Dragon.h"
#include "Tower.cpp"
#include "Head.cpp"


using namespace std;

void Dragon::TakeDamage(int damage) {
    if (is_alive){
        if ((health_points - damage) > 0){
            health_points -= damage;
        } else{
            health_points = 0;
            is_alive = false;
            cout << "Dragon was killed!" << endl;
        }
    }
}

void Dragon::AttackCastle() {

        if (random_strategy) {
            while (is_alive){
                int main_target;

                do {
                    main_target = rand() % target_castle.getSize();
                } while (!(target_castle.getTower(main_target).getState()));

                heads[1].setTarget(main_target);
                if (main_target == 0) heads[0].setTarget(target_castle.getSize() - 1);
                else heads[0].setTarget(main_target - 1);
                if (main_target == target_castle.getSize() - 1) heads[2].setTarget(0);
                else heads[2].setTarget(main_target + 1);

                for (int i = 0; i < 3; ++i) {
                    int auxDragon = heads[i].AttackTower();
                    cout << "Dragon dealt " << auxDragon << " damage to Tower №" << heads[i].getTarget() <<endl;
                    target_castle.getTower(heads[i].getTarget()).TakeDamage(auxDragon);

                    target_castle.CheckTowers();
                    int auxTower = target_castle.getTower(heads[i].getTarget()).Attack();
                    cout << "Tower dealt " << auxTower << " damage to Dragon!" <<endl;
                    TakeDamage(auxTower);
                }

                if (target_castle.getState() || is_alive == false) break;
            }
        } else {
            int main_target = rand() % target_castle.getSize();

            while (is_alive){
                if (!(target_castle.getTower(main_target).getState())) {
                    do {
                        main_target = rand() % target_castle.getSize();
                    } while (!(target_castle.getTower(main_target).getState()));
                }

                heads[1].setTarget(main_target);
                if (main_target == 0) heads[0].setTarget(target_castle.getSize() - 1);
                else heads[0].setTarget(main_target - 1);
                if (main_target == target_castle.getSize() - 1) heads[2].setTarget(0);
                else heads[2].setTarget(main_target + 1);

                for (int i = 0; i < 3; ++i) {
                    int auxDragon = heads[i].AttackTower();
                    cout << "Dragon dealt " << auxDragon << " damage to Tower №" << heads[i].getTarget() <<endl;
                    target_castle.getTower(heads[i].getTarget()).TakeDamage(auxDragon);
                    target_castle.CheckTowers();
                    int auxTower = target_castle.getTower(heads[i].getTarget()).Attack();
                    cout << "Tower dealt " << auxTower << " damage to Dragon!" << endl;
                    TakeDamage(auxTower);
                }

                if (target_castle.getState() || is_alive == false) break;
            }
        }

}

void Dragon::showStats() {

    int dragon_damage;
    for (int i = 0; i < 3; ++i) {
        dragon_damage += heads[i].getDamageDealt();
        cout << i <<" Head damage: " << heads[i].getDamageDealt() << endl;
    }
    cout << "Dragon's damage: " << dragon_damage << endl;

    int castle_damage;
    for (int i = 0; i < target_castle.getSize(); ++i) {
        castle_damage += target_castle.getTower(i).getDamageDealt();
        cout << i <<" Tower damage: " << target_castle.getTower(i).getDamageDealt() << endl;
    }
    cout << "Castle's damage: " << castle_damage << endl;

}