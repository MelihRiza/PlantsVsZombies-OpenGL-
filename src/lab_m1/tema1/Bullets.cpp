#include "lab_m1/tema1/tema.h"

#include <vector>
#include <iostream>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"


using namespace std;
using namespace m1;


#define ATTACKER_RELOAD_TIME 6
#define BULLETS_SPEED 300


void tema::CheckEnemies(float deltaTimeSeconds, line* l) {
    for (auto& attacker : l->attackersOnLine) {
        for (const auto& enemy : l->enemiesOnLine) {
            if (attacker.first.second == enemy.first.second && attacker.second.first > ATTACKER_RELOAD_TIME) {
                l->bulletsOnLine.push_back(std::make_tuple(attacker.first.first * 150 + 220, attacker.first.second, 3));
                attacker.second.first = 0;
            }
        }
    }
    for (auto& pair : l->attackersOnLine) {
        pair.second.first += deltaTimeSeconds * 4;
    }
}


void tema::DrawBullets(float deltaTimeSeconds, line* l) {
    glm::mat3 modelMatrix;
    for (auto& tuple : l->bulletsOnLine) {

        l->bulletsOnLine.erase(std::remove_if(l->bulletsOnLine.begin(), l->bulletsOnLine.end(),
            [](const std::tuple<float, int, int>& tuple) {
                return std::get<0>(tuple) > 1300.0f;
            }), l->bulletsOnLine.end());

        modelMatrix = glm::mat3(1);
        modelMatrix[2][0] = std::get<0>(tuple);
        modelMatrix[2][1] = l->bulletsY;

        modelMatrix *= transform2D::Rotate(-l->bulletRotation);

        l->bulletRotation += 5 * deltaTimeSeconds;

        if (std::get<1>(tuple) == 0) {
            RenderMesh2D(meshes["redStar"], shaders["VertexColor"], modelMatrix);
        }
        else if (std::get<1>(tuple) == 1) {
            RenderMesh2D(meshes["cyanStar"], shaders["VertexColor"], modelMatrix);
        }
        else if (std::get<1>(tuple) == 2) {
            RenderMesh2D(meshes["pinkStar"], shaders["VertexColor"], modelMatrix);
        }
        else if (std::get<1>(tuple) == 3) {
            RenderMesh2D(meshes["greenStar"], shaders["VertexColor"], modelMatrix);
        }

        std::get<0>(tuple) += BULLETS_SPEED * deltaTimeSeconds;
    }
}

void tema::DestroyBullet(line* l, int idx) {
    if (idx >= 0 && idx < l->bulletsOnLine.size()) {
        l->bulletsOnLine.erase(l->bulletsOnLine.begin() + idx);
    }
}

void tema::Colide(line* l0, line* l1, line* l2) {

    int pos_bullet = 0;
    int pos_enemy = 0;
    for (auto& bullet : l0->bulletsOnLine) {
        for (auto& enemy : l0->enemiesOnLine) {
            if (enemy.first.first - std::get<0>(bullet) < 20 && enemy.first.second == std::get<1>(bullet)) {

                DestroyBullet(l0, pos_bullet);
                enemy.second.first -= 1;
                if (enemy.second.first == 0) {
                    enemy.second.second = 0.98;

                }

            }
            pos_enemy += 1;
        }
        pos_bullet += 1;
    }

    pos_bullet = 0;
    pos_enemy = 0;
    for (auto& bullet : l1->bulletsOnLine) {
        for (auto& enemy : l1->enemiesOnLine) {
            if (enemy.first.first - std::get<0>(bullet) < 20 && enemy.first.second == std::get<1>(bullet)) {

                DestroyBullet(l1, pos_bullet);
                enemy.second.first -= 1;
                if (enemy.second.first == 0) {
                    enemy.second.second = 0.98;
                }

            }
            pos_enemy += 1;
        }
        pos_bullet += 1;
    }

    pos_bullet = 0;
    pos_enemy = 0;
    for (auto& bullet : l2->bulletsOnLine) {
        for (auto& enemy : l2->enemiesOnLine) {
            if (enemy.first.first - std::get<0>(bullet) < 20 && enemy.first.second == std::get<1>(bullet)) {

                DestroyBullet(l2, pos_bullet);
                enemy.second.first -= 1;
                if (enemy.second.first == 0) {
                    enemy.second.second = 0.98;
                }

            }
            pos_enemy += 1;
        }
        pos_bullet += 1;
    }

}