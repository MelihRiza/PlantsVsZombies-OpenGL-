#include "lab_m1/tema1/tema.h"

#include <vector>
#include <iostream>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"


using namespace std;
using namespace m1;

void tema::DrawEnemies(float deltaTimeSeconds, line* l) {
    vector<int> position_to_erase;

    for (int i = 0; i < l->enemiesOnLine.size(); i++) {
        modelMatrix = glm::mat3(1);
        modelMatrix[2][1] = l->slot0Y;

        if (l->enemiesOnLine[i].first.second == 0) {

            if (l->enemiesOnLine[i].second.first <= 0 && l->enemiesOnLine[i].second.second < 1) {
                modelMatrix *= transform2D::Scale(l->enemiesOnLine[i].second.second, l->enemiesOnLine[i].second.second);
                l->enemiesOnLine[i].second.second -= 1.5 * deltaTimeSeconds;
            }

            modelMatrix[2][0] = l->enemiesOnLine[i].first.first;
            modelMatrix[2][1] = l->enemiesY;
            RenderMesh2D(meshes["hexagon0"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["hexagonMini"], shaders["VertexColor"], modelMatrix);

            if (l->enemiesOnLine[i].second.second < 0.1) {
                position_to_erase.push_back(i);
            }
        }
        else if (l->enemiesOnLine[i].first.second == 1) {

            if (l->enemiesOnLine[i].second.first <= 0 && l->enemiesOnLine[i].second.second < 1) {
                modelMatrix *= transform2D::Scale(l->enemiesOnLine[i].second.second, l->enemiesOnLine[i].second.second);
                l->enemiesOnLine[i].second.second -= 1.5 * deltaTimeSeconds;
            }

            modelMatrix[2][0] = l->enemiesOnLine[i].first.first;
            modelMatrix[2][1] = l->enemiesY;
            RenderMesh2D(meshes["hexagon1"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["hexagonMini"], shaders["VertexColor"], modelMatrix);

            if (l->enemiesOnLine[i].second.second < 0.1) {
                position_to_erase.push_back(i);
            }
        }
        else if (l->enemiesOnLine[i].first.second == 2) {

            if (l->enemiesOnLine[i].second.first <= 0 && l->enemiesOnLine[i].second.second < 1) {
                modelMatrix *= transform2D::Scale(l->enemiesOnLine[i].second.second, l->enemiesOnLine[i].second.second);
                l->enemiesOnLine[i].second.second -= 1.5 * deltaTimeSeconds;
            }

            modelMatrix[2][0] = l->enemiesOnLine[i].first.first;
            modelMatrix[2][1] = l->enemiesY;
            RenderMesh2D(meshes["hexagon2"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["hexagonMini"], shaders["VertexColor"], modelMatrix);

            if (l->enemiesOnLine[i].second.second < 0.1) {
                position_to_erase.push_back(i);
            }
        }
        else if (l->enemiesOnLine[i].first.second == 3) {

            if (l->enemiesOnLine[i].second.first <= 0 && l->enemiesOnLine[i].second.second < 1) {
                modelMatrix *= transform2D::Scale(l->enemiesOnLine[i].second.second, l->enemiesOnLine[i].second.second);
                l->enemiesOnLine[i].second.second -= 1.5 * deltaTimeSeconds;
            }

            modelMatrix[2][0] = l->enemiesOnLine[i].first.first;
            modelMatrix[2][1] = l->enemiesY;
            RenderMesh2D(meshes["hexagon3"], shaders["VertexColor"], modelMatrix);
            RenderMesh2D(meshes["hexagonMini"], shaders["VertexColor"], modelMatrix);

            if (l->enemiesOnLine[i].second.second < 0.1) {
                position_to_erase.push_back(i);
            }
        }
    }

    for (int i = 0; i < position_to_erase.size(); i++) {
        KillEnemy(l, position_to_erase[i]);
    }

}

void tema::SpawnEnemy(float deltaTimeSeconds, line* l, int enemy_type) {
    l->enemiesOnLine.push_back(std::make_pair(std::make_pair(1100, enemy_type), std::make_pair(3, 1.0)));

    DrawEnemies(deltaTimeSeconds, l);
}

void tema::KillEnemy(line* l, int idx) {
    if (idx >= 0 && idx < l->enemiesOnLine.size()) {
        l->enemiesOnLine.erase(l->enemiesOnLine.begin() + idx);
    }
}

void tema::KillAttacker(line* l, int idx) {
    if (idx >= 0 && idx < l->attackersOnLine.size()) {
        l->attackersOnLine.erase(l->attackersOnLine.begin() + idx);
    }
}


void tema::advance_enemy(float deltaTimeSeconds, line* l0, line* l1, line* l2) {

    for (int i = 0; i < l0->enemiesOnLine.size(); i++) {
        if (l0->enemiesOnLine[i].first.first < 30) {
            lives_left -= 1;
            l0->enemiesOnLine.erase(l0->enemiesOnLine.begin() + i);
        }
        else if (l0->enemiesOnLine[i].second.first > 0) {
            l0->enemiesOnLine[i].first.first -= deltaTimeSeconds * 60;
        }
     
    }

    for (int i = 0; i < l1->enemiesOnLine.size(); i++) {
        if (l1->enemiesOnLine[i].first.first < 30) {
            lives_left -= 1;
            l1->enemiesOnLine.erase(l1->enemiesOnLine.begin() + i);
        }
        else if (l1->enemiesOnLine[i].second.first > 0) {
            l1->enemiesOnLine[i].first.first -= deltaTimeSeconds * 60;
        }
    
    }

    for (int i = 0; i < l2->enemiesOnLine.size(); i++) {
        if (l2->enemiesOnLine[i].first.first < 30) {
            lives_left -= 1;
            l2->enemiesOnLine.erase(l2->enemiesOnLine.begin() + i);
        }
        else if (l2->enemiesOnLine[i].second.first > 0) {
            l2->enemiesOnLine[i].first.first -= deltaTimeSeconds * 60;
        }
     
    }
}


void tema::DestroyAttacker(line* l0, line* l1, line* l2) {
    int pos_attacker = 0;
    int pos_enemy = 0;
    bool killed = false;
    for (auto& attacker : l0->attackersOnLine) {
        for (auto& enemy : l0->enemiesOnLine) {
            if (enemy.first.first - (attacker.first.first * 150 + 220) < 20 && enemy.first.first - (attacker.first.first * 150 + 220) > -40) {

                attacker.second.second = 0.98;
                killed = true;

                if (attacker.first.first == 0) {
                    l0->occupied_slot0 = false;
                }
                else if (attacker.first.first == 1) {
                    l0->occupied_slot1 = false;
                }
                else if (attacker.first.first == 2) {
                    l0->occupied_slot2 = false;
                }

            }
            pos_enemy += 1;
        }
        if (!killed) {
            pos_attacker += 1;
        }
        killed = false;
    }

    pos_attacker = 0;
    pos_enemy = 0;
    killed = false;
    for (auto& attacker : l1->attackersOnLine) {
        for (auto& enemy : l1->enemiesOnLine) {
            if (enemy.first.first - (attacker.first.first * 150 + 220) < 20 && enemy.first.first - (attacker.first.first * 150 + 220) > -40) {

                attacker.second.second = 0.98;
                killed = true;
                if (attacker.first.first == 0) {
                    l1->occupied_slot0 = false;
                }
                else if (attacker.first.first == 1) {
                    l1->occupied_slot1 = false;
                }
                else if (attacker.first.first == 2) {
                    l1->occupied_slot2 = false;
                }
                
            }
            pos_enemy += 1;
        }
        if (!killed) {
            pos_attacker += 1;
        }
        killed = false;
    }

    pos_attacker = 0;
    pos_enemy = 0;
    killed = false;
    for (auto& attacker : l2->attackersOnLine) {
        for (auto& enemy : l2->enemiesOnLine) {
            if (enemy.first.first - (attacker.first.first * 150 + 220) < 20 && enemy.first.first - (attacker.first.first * 150 + 220) > -40) {

                attacker.second.second = 0.98;
                killed = true;
                if (attacker.first.first == 0) {
                    l2->occupied_slot0 = false;
                }
                else if (attacker.first.first == 1) {
                    l2->occupied_slot1 = false;
                }
                else if (attacker.first.first == 2) {
                    l2->occupied_slot2 = false;
                }

            }
            pos_enemy += 1;
        }
        if (!killed) {
            pos_attacker += 1;
        }
        killed = false;
    }

}