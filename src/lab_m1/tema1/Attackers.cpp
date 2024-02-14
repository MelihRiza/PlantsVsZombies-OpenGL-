#include "lab_m1/tema1/tema.h"

#include <vector>
#include <iostream>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"


using namespace std;
using namespace m1;


#define ATTACKER0_SHOP_X 50
#define ATTACKER0_SHOP_Y 600
#define ATTACKER1_SHOP_X 200
#define ATTACKER1_SHOP_Y 600
#define ATTACKER2_SHOP_X 350
#define ATTACKER2_SHOP_Y 600
#define ATTACKER3_SHOP_X 500
#define ATTACKER3_SHOP_Y 600
#define ATTACKER_BOX_SIZE 90
#define PLANT_BOX_SIZE 120


void tema::BuyAttacker(float x, float y) {
    if (x >= ATTACKER0_SHOP_X && x <= ATTACKER0_SHOP_X + ATTACKER_BOX_SIZE
        && y >= ATTACKER0_SHOP_Y && y < ATTACKER0_SHOP_Y + ATTACKER_BOX_SIZE && money_left >= 1) {
        holdingAttacker = true;
        attackerType = 0;
    }
    else if (x >= ATTACKER1_SHOP_X && x <= ATTACKER1_SHOP_X + ATTACKER_BOX_SIZE
        && y >= ATTACKER1_SHOP_Y && y < ATTACKER1_SHOP_Y + ATTACKER_BOX_SIZE && money_left >= 2) {
        holdingAttacker = true;
        attackerType = 1;
    }
    else if (x >= ATTACKER2_SHOP_X && x <= ATTACKER2_SHOP_X + ATTACKER_BOX_SIZE
        && y >= ATTACKER2_SHOP_Y && y < ATTACKER2_SHOP_Y + ATTACKER_BOX_SIZE && money_left >= 2) {
        holdingAttacker = true;
        attackerType = 2;
    }
    else if (x >= ATTACKER3_SHOP_X && x <= ATTACKER3_SHOP_X + ATTACKER_BOX_SIZE
        && y >= ATTACKER3_SHOP_Y && y < ATTACKER3_SHOP_Y + ATTACKER_BOX_SIZE && money_left >= 3) {
        holdingAttacker = true;
        attackerType = 3;
    }
}

void tema::DrawAttackerAtCursor(float x, float y, int type) {
    glm::mat3 modelMatrix;
    modelMatrix = glm::mat3(1);
    modelMatrix[2][0] = x;
    modelMatrix[2][1] = y;

    if (type == 0) {
        RenderMesh2D(meshes["attacker0"], shaders["VertexColor"], modelMatrix);
    }
    else if (type == 1) {
        RenderMesh2D(meshes["attacker1"], shaders["VertexColor"], modelMatrix);
    }
    else if (type == 2) {
        RenderMesh2D(meshes["attacker2"], shaders["VertexColor"], modelMatrix);
    }
    else if (type == 3) {
        RenderMesh2D(meshes["attacker3"], shaders["VertexColor"], modelMatrix);
    }
}


void tema::PlaceAttacker(float x, float y) {

    // line 2
    if (x > line2.slot0X && x < line2.slot0X + PLANT_BOX_SIZE
        && y > line2.slot0Y && y < line2.slot0Y + PLANT_BOX_SIZE && !line2.occupied_slot0) {
        line2.occupied_slot0 = true;
        line2.attackersOnLine.push_back(std::make_pair(std::make_pair(0, attackerType), std::make_pair(1.0, 1.0)));
        if (attackerType == 0) {
            money_left -= 1;
        }
        else if (attackerType == 3) {
            money_left -= 3;
        }
        else {
            money_left -= 2;
        }
    }
    else if (x > line2.slot1X && x < line2.slot1X + PLANT_BOX_SIZE
        && y > line2.slot1Y && y < line2.slot1Y + PLANT_BOX_SIZE && !line2.occupied_slot1) {
        line2.occupied_slot1 = true;
        line2.attackersOnLine.push_back(std::make_pair(std::make_pair(1, attackerType), std::make_pair(1.0, 1.0)));
        if (attackerType == 0) {
            money_left -= 1;
        }
        else if (attackerType == 3) {
            money_left -= 3;
        }
        else {
            money_left -= 2;
        }
    }
    else if (x > line2.slot2X && x < line2.slot2X + PLANT_BOX_SIZE
        && y > line2.slot2Y && y < line2.slot2Y + PLANT_BOX_SIZE && !line2.occupied_slot2) {
        line2.occupied_slot2 = true;
        line2.attackersOnLine.push_back(std::make_pair(std::make_pair(2, attackerType), std::make_pair(1.0, 1.0)));
        if (attackerType == 0) {
            money_left -= 1;
        }
        else if (attackerType == 3) {
            money_left -= 3;
        }
        else {
            money_left -= 2;
        }
    }

    // line 1

    else if (x > line1.slot0X && x < line1.slot0X + PLANT_BOX_SIZE
        && y > line1.slot0Y && y < line1.slot0Y + PLANT_BOX_SIZE && !line1.occupied_slot0) {
        line1.occupied_slot0 = true;
        line1.attackersOnLine.push_back(std::make_pair(std::make_pair(0, attackerType), std::make_pair(1.0, 1.0)));
        if (attackerType == 0) {
            money_left -= 1;
        }
        else if (attackerType == 3) {
            money_left -= 3;
        }
        else {
            money_left -= 2;
        }
    }
    else if (x > line1.slot1X && x < line1.slot1X + PLANT_BOX_SIZE
        && y > line1.slot1Y && y < line1.slot1Y + PLANT_BOX_SIZE && !line1.occupied_slot1) {
        line1.occupied_slot1 = true;
        line1.attackersOnLine.push_back(std::make_pair(std::make_pair(1, attackerType), std::make_pair(1.0, 1.0)));
        if (attackerType == 0) {
            money_left -= 1;
        }
        else if (attackerType == 3) {
            money_left -= 3;
        }
        else {
            money_left -= 2;
        }
    }
    else if (x > line1.slot2X && x < line1.slot2X + PLANT_BOX_SIZE
        && y > line1.slot2Y && y < line1.slot2Y + PLANT_BOX_SIZE && !line1.occupied_slot2) {
        line1.occupied_slot2 = true;
        line1.attackersOnLine.push_back(std::make_pair(std::make_pair(2, attackerType), std::make_pair(1.0, 1.0)));
        if (attackerType == 0) {
            money_left -= 1;
        }
        else if (attackerType == 3) {
            money_left -= 3;
        }
        else {
            money_left -= 2;
        }
    }

    // line 0

    if (x > line0.slot0X && x < line0.slot0X + PLANT_BOX_SIZE
        && y > line0.slot0Y && y < line0.slot0Y + PLANT_BOX_SIZE && !line0.occupied_slot0) {
        line0.occupied_slot0 = true;
        line0.attackersOnLine.push_back(std::make_pair(std::make_pair(0, attackerType), std::make_pair(1.0, 1.0)));
        if (attackerType == 0) {
            money_left -= 1;
        }
        else if (attackerType == 3) {
            money_left -= 3;
        }
        else {
            money_left -= 2;
        }
    }
    else if (x > line0.slot1X && x < line0.slot1X + PLANT_BOX_SIZE
        && y > line0.slot1Y && y < line0.slot1Y + PLANT_BOX_SIZE && !line0.occupied_slot1) {
        line0.occupied_slot1 = true;
        line0.attackersOnLine.push_back(std::make_pair(std::make_pair(1, attackerType), std::make_pair(1.0, 1.0)));
        if (attackerType == 0) {
            money_left -= 1;
        }
        else if (attackerType == 3) {
            money_left -= 3;
        }
        else {
            money_left -= 2;
        }
    }
    else if (x > line0.slot2X && x < line0.slot2X + PLANT_BOX_SIZE
        && y > line0.slot2Y && y < line0.slot2Y + PLANT_BOX_SIZE && !line0.occupied_slot2) {
        line0.occupied_slot2 = true;
        line0.attackersOnLine.push_back(std::make_pair(std::make_pair(2, attackerType), std::make_pair(1.0, 1.0)));
        if (attackerType == 0) {
            money_left -= 1;
        }
        else if (attackerType == 3) {
            money_left -= 3;
        }
        else {
            money_left -= 2;
        }
    }
}

void tema::DrawAttackersOnBoard() {
    int to_remove[9];

    for (int i = 0; i < 9; i++) {
        to_remove[i] = 0;
    }

    if (line0.attackersOnLine.size() > 0) {
        glm::mat3 modelMatrix = glm::mat3(1);
        float posY = line0.slot0Y + 60;


        int pos_attacker_in_vector = 0;
        bool deleted_attacker = false;


        for (auto& pair : line0.attackersOnLine) {
            float startX = 0;
            if (pair.first.first == 0)
                startX = line0.slot0X + 35;
            else if (pair.first.first == 1)
                startX = line0.slot1X + 35;
            else if (pair.first.first == 2)
                startX = line0.slot2X + 35;

            if (pair.first.second == 0) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {
                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);
                    
                    pair.second.second -= 0.02;
                }
               
                RenderMesh2D(meshes["attacker0"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[pair.first.first] = 1;
                }
            }
            else if (pair.first.second == 1) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }
               
                RenderMesh2D(meshes["attacker1"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[pair.first.first] = 1;
                }
            }
            else if (pair.first.second == 2) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }
              
                RenderMesh2D(meshes["attacker2"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[pair.first.first] = 1;
                }
            }
            else if (pair.first.second == 3) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }


                RenderMesh2D(meshes["attacker3"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[pair.first.first] = 1;
                }
            }
        }
    }

    if (line1.attackersOnLine.size() > 0) {
        glm::mat3 modelMatrix = glm::mat3(1);
        float posY = line1.slot0Y + 60;

        for (auto& pair : line1.attackersOnLine) {
            float startX = 0;
            if (pair.first.first == 0)
                startX = line1.slot0X + 35;
            else if (pair.first.first == 1)
                startX = line1.slot1X + 35;
            else if (pair.first.first == 2)
                startX = line1.slot2X + 35;

   


            if (pair.first.second == 0) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }

                RenderMesh2D(meshes["attacker0"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[3 + pair.first.first] = 1;
                }
            }
            else if (pair.first.second == 1) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }

                RenderMesh2D(meshes["attacker1"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[3 + pair.first.first] = 1;
                }
            }
            else if (pair.first.second == 2) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }

                RenderMesh2D(meshes["attacker2"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[3 + pair.first.first] = 1;
                }
            }
            else if (pair.first.second == 3) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }

                RenderMesh2D(meshes["attacker3"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[3 + pair.first.first] = 1;
                }
            }
        }
    }

    if (line2.attackersOnLine.size() > 0) {
        glm::mat3 modelMatrix = glm::mat3(1);
        float posY = line2.slot0Y + 60;

        for (auto& pair : line2.attackersOnLine) {
            float startX = 0;
            if (pair.first.first == 0)
                startX = line2.slot0X + 35;
            else if (pair.first.first == 1)
                startX = line2.slot1X + 35;
            else if (pair.first.first == 2)
                startX = line2.slot2X + 35;


            if (pair.first.second == 0) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }

                RenderMesh2D(meshes["attacker0"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[6 + pair.first.first] = 1;
                }
            }
            else if (pair.first.second == 1) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }

                RenderMesh2D(meshes["attacker1"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[6 + pair.first.first] = 1;
                }
            }
            else if (pair.first.second == 2) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }

                RenderMesh2D(meshes["attacker2"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[6 + pair.first.first] = 1;
                }
            }
            else if (pair.first.second == 3) {
                modelMatrix = glm::mat3(1);
                modelMatrix[2][0] = startX;
                modelMatrix[2][1] = posY;
                if (pair.second.second < 1.0) {

                    modelMatrix *= transform2D::Scale(pair.second.second, pair.second.second);

                    pair.second.second -= 0.02;
                }

                RenderMesh2D(meshes["attacker3"], shaders["VertexColor"], modelMatrix);

                if (pair.second.second < 0.2) {
                    to_remove[6 + pair.first.first] = 1;
                }
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (to_remove[i] == 1 && i < 3) {
            deleteAttacker(&line0, i % 3);
        }
        else if (to_remove[i] == 1 && i >= 3 && i < 6) {
            deleteAttacker(&line1, i % 3);
        }
        else if (to_remove[i] == 1 && i >= 6 && i < 9) {
            deleteAttacker(&line2, i % 3);
        }
    }
}

void tema::deleteAttacker(line* l, int idx) {
    l->attackersOnLine.erase(
        std::remove_if(l->attackersOnLine.begin(), l->attackersOnLine.end(), [idx](std::pair<std::pair<int, int>, std::pair<float, float>>& pair) {
            return pair.first.first == idx;
            }),
        l->attackersOnLine.end()
    );
   
}



void tema::RemoveAttacker(float x, float y) {
    if (x > line2.slot0X && x < line2.slot0X + PLANT_BOX_SIZE
        && y > line2.slot0Y && y < line2.slot0Y + PLANT_BOX_SIZE && line2.occupied_slot0) {
        line2.occupied_slot0 = false;
        
        for (auto& pair : line2.attackersOnLine) {
            if (pair.first.first == 0) {
                pair.second.second = 0.98;
            }
        }
    }
    else if (x > line2.slot1X && x < line2.slot1X + PLANT_BOX_SIZE
        && y > line2.slot1Y && y < line2.slot1Y + PLANT_BOX_SIZE && line2.occupied_slot1) {
        line2.occupied_slot1 = false;

        for (auto& pair : line2.attackersOnLine) {
            if (pair.first.first == 1) {
                pair.second.second = 0.98;
            }
        }
    }
    else if (x > line2.slot2X && x < line2.slot2X + PLANT_BOX_SIZE
        && y > line2.slot2Y && y < line2.slot2Y + PLANT_BOX_SIZE && line2.occupied_slot2) {
        line2.occupied_slot2 = false;
        
        for (auto& pair : line2.attackersOnLine) {
            if (pair.first.first == 2) {
                pair.second.second = 0.98;
            }
        }
    }


    else if (x > line1.slot0X && x < line1.slot0X + PLANT_BOX_SIZE
        && y > line1.slot0Y && y < line1.slot0Y + PLANT_BOX_SIZE && line1.occupied_slot0) {
        line1.occupied_slot0 = false;

        for (auto& pair : line1.attackersOnLine) {
            if (pair.first.first == 0) {
                pair.second.second = 0.98;
            }
        }
    }
    else if (x > line1.slot1X && x < line1.slot1X + PLANT_BOX_SIZE
        && y > line1.slot1Y && y < line1.slot1Y + PLANT_BOX_SIZE && line1.occupied_slot1) {
        line1.occupied_slot1 = false;
        
        for (auto& pair : line1.attackersOnLine) {
            if (pair.first.first == 1) {
                pair.second.second = 0.98;
            }
        }
    }
    else if (x > line1.slot2X && x < line1.slot2X + PLANT_BOX_SIZE
        && y > line1.slot2Y && y < line1.slot2Y + PLANT_BOX_SIZE && line1.occupied_slot2) {
        line1.occupied_slot2 = false;
        
        for (auto& pair : line1.attackersOnLine) {
            if (pair.first.first == 2) {
                pair.second.second = 0.98;
            }
        }
    }


    if (x > line0.slot0X && x < line0.slot0X + PLANT_BOX_SIZE
        && y > line0.slot0Y && y < line0.slot0Y + PLANT_BOX_SIZE && line0.occupied_slot0) {
        line0.occupied_slot0 = false;
        int k = 0;

        for (auto& pair : line0.attackersOnLine) {
            if (pair.first.first == 0) {
                pair.second.second = 0.98;
            }
        }
    }
    else if (x > line0.slot1X && x < line0.slot1X + PLANT_BOX_SIZE
        && y > line0.slot1Y && y < line0.slot1Y + PLANT_BOX_SIZE && line0.occupied_slot1) {
        line0.occupied_slot1 = false;

        for (auto& pair : line0.attackersOnLine) {
            if (pair.first.first == 1) {
                pair.second.second = 0.98;
            }
        }
    }
    else if (x > line0.slot2X && x < line0.slot2X + PLANT_BOX_SIZE
        && y > line0.slot2Y && y < line0.slot2Y + PLANT_BOX_SIZE && line0.occupied_slot2) {
        line0.occupied_slot2 = false;
        
        for (auto& pair : line0.attackersOnLine) {
            if (pair.first.first == 2) {
                pair.second.second = 0.98;
            }
        }
    }
}