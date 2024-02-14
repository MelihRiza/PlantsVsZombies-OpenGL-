#include "lab_m1/tema1/tema.h"

#include <vector>
#include <iostream>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"


using namespace std;
using namespace m1;


void tema::SpawnMoney(float deltaTimeSeconds) {
    time_passed_money += deltaTimeSeconds;
    if (time_passed_money >= time_money_spawn) {
        for (int i = 0; i < 3; i++) {
            int x = GenerateRandomNumber(10, 1200);
            int y = GenerateRandomNumber(10, 700);

            starsMoney.push_back(std::make_pair(x, y));
        }
        time_passed_money = 0;
        time_money_spawn = GenerateRandomNumber(8, 15);
    }
}

void tema::DrawMoneyStars() {
    if (starsMoney.size() == 0) {
        return;
    }

    for (const auto& pair : starsMoney) {
        glm::mat3 modelMatrix;
        modelMatrix = glm::mat3(1);
        modelMatrix[2][0] = pair.first;
        modelMatrix[2][1] = pair.second;
        RenderMesh2D(meshes["goldenStar"], shaders["VertexColor"], modelMatrix);
    }
}

int tema::GenerateRandomNumber(int start, int end) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(start, end);

    int randomNum = dist(mt);

    return randomNum;
}

bool tema::TakeMoney(float x, float y) {
    glm::vec2 point1(x, y);

    auto pos = starsMoney.begin();

    bool took = false;

    while (pos != starsMoney.end()) {
        const auto& pair = *pos;
        glm::vec2 point2(pair.first, pair.second);

        if (glm::distance(point1, point2) <= 35) {
            money_left += 1;
            took = true;
            pos = starsMoney.erase(pos);
        }
        else {
            ++pos;
        }
    }

    return took;
}