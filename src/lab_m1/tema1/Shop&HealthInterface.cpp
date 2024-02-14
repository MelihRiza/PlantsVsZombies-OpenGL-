#include "lab_m1/tema1/tema.h"

#include <vector>
#include <iostream>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"


using namespace std;
using namespace m1;


void tema::RenderShop() {
    modelMatrix = glm::mat3(1);
    modelMatrix[2][0] = 50;
    modelMatrix[2][1] = 600;

    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix); // First attacker 
    modelMatrix[2][0] += 15;
    modelMatrix[2][1] += 45;
    RenderMesh2D(meshes["attacker0"], shaders["VertexColor"], modelMatrix);
    DrawStaticStar(modelMatrix[2][0], modelMatrix[2][1] - 70, 0.4);

    modelMatrix[2][0] = 200;
    modelMatrix[2][1] = 600;
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix); // Second attacker
    modelMatrix[2][0] += 15;
    modelMatrix[2][1] += 45;
    RenderMesh2D(meshes["attacker1"], shaders["VertexColor"], modelMatrix);
    DrawStaticStar(modelMatrix[2][0], modelMatrix[2][1] - 70, 0.4);
    DrawStaticStar(modelMatrix[2][0] + 35, modelMatrix[2][1] - 70, 0.4);


    modelMatrix[2][0] = 350;
    modelMatrix[2][1] = 600;
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix); // Third attacker
    modelMatrix[2][0] += 15;
    modelMatrix[2][1] += 45;
    RenderMesh2D(meshes["attacker2"], shaders["VertexColor"], modelMatrix);
    DrawStaticStar(modelMatrix[2][0], modelMatrix[2][1] - 70, 0.4);
    DrawStaticStar(modelMatrix[2][0] + 35, modelMatrix[2][1] - 70, 0.4);

    modelMatrix[2][0] = 500;
    modelMatrix[2][1] = 600;
    RenderMesh2D(meshes["square2"], shaders["VertexColor"], modelMatrix); // Fourth attacker
    modelMatrix[2][0] += 15;
    modelMatrix[2][1] += 45;
    RenderMesh2D(meshes["attacker3"], shaders["VertexColor"], modelMatrix);
    DrawStaticStar(modelMatrix[2][0], modelMatrix[2][1] - 70, 0.4);
    DrawStaticStar(modelMatrix[2][0] + 35, modelMatrix[2][1] - 70, 0.4);
    DrawStaticStar(modelMatrix[2][0] + 70, modelMatrix[2][1] - 70, 0.4);
}

void tema::RenderLives() {
    float start_x = 750;
    float start_y = 650;


    for (int i = 0; i < lives_left; i++) {
        modelMatrix = glm::mat4(1);
        modelMatrix[2][0] = start_x + i * 125;
        modelMatrix[2][1] = start_y;
        modelMatrix *= transform2D::Scale(0.9, 0.9);

        RenderMesh2D(meshes["hearth"], shaders["VertexColor"], modelMatrix);
    }

    start_y -= 40;

    // Draw money left
    modelMatrix[2][1] = start_y;
    modelMatrix *= transform2D::Scale(0.4, 0.4);

    int contor = 0;
    int line = 0;
    int i = 0;

    while (i < money_left) {
        if (contor == 14) {
            line += 1;
            contor = 0;
        }
        modelMatrix[2][0] = start_x + (i % 14) * 35;
        modelMatrix[2][1] = 570 - (line * 35);
        RenderMesh2D(meshes["starGray"], shaders["VertexColor"], modelMatrix);
        i++;
        contor++;
    }

}

void tema::DrawStaticStar(float x, float y, float scale) {
    glm::mat3 modelMatrix1;
    modelMatrix1 = glm::mat3(1);

    modelMatrix1[2][0] = x;
    modelMatrix1[2][1] = y;

    modelMatrix1 *= transform2D::Scale(scale, scale);

    RenderMesh2D(meshes["starGray"], shaders["VertexColor"], modelMatrix1);
}