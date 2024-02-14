#include "lab_m1/tema1/tema.h"

#include <vector>
#include <iostream>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"

using namespace std;
using namespace m1;


#define LAWNMOWER_SPEED 200;


void tema::DrawLawnMowers(float deltaTimeSeconds) {

    if (!line0.used_lawnMower) {
        glm::mat3 modelMatrix = glm::mat3(1);

        modelMatrix[2][0] = line0.lawnMowerX;
        modelMatrix[2][1] = line0.slot0Y;

        RenderMesh2D(meshes["lawnMower"], shaders["VertexColor"], modelMatrix);


        if (line0.activateLawnMower) {
            line0.lawnMowerX += deltaTimeSeconds * LAWNMOWER_SPEED;

            modelMatrix[2][0] = line0.lawnMowerX - 50;
            modelMatrix *= transform2D::Rotate(-line0.angularWheel);

            line0.angularWheel += 50 * deltaTimeSeconds;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);

            modelMatrix[2][0] = line0.lawnMowerX - 15;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);
        }
        else {
            modelMatrix[2][0] = line0.lawnMowerX - 50;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);

            modelMatrix[2][0] = line0.lawnMowerX - 15;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);
        }
    }

    if (!line1.used_lawnMower) {
        glm::mat3 modelMatrix = glm::mat3(1);

        modelMatrix[2][0] = line1.lawnMowerX;
        modelMatrix[2][1] = line1.slot0Y;

        RenderMesh2D(meshes["lawnMower"], shaders["VertexColor"], modelMatrix);

        if (line1.activateLawnMower) {
            line1.lawnMowerX += deltaTimeSeconds * LAWNMOWER_SPEED;

            modelMatrix[2][0] = line1.lawnMowerX - 50;
            modelMatrix *= transform2D::Rotate(-line1.angularWheel);

            line1.angularWheel += 50 * deltaTimeSeconds;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);

            modelMatrix[2][0] = line1.lawnMowerX - 15;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);
        }
        else {
            modelMatrix[2][0] = line1.lawnMowerX - 50;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);

            modelMatrix[2][0] = line1.lawnMowerX - 15;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);
        }

    }

    if (!line2.used_lawnMower) {
        glm::mat3 modelMatrix = glm::mat3(1);

        modelMatrix[2][0] = line2.lawnMowerX;
        modelMatrix[2][1] = line2.slot0Y;

        RenderMesh2D(meshes["lawnMower"], shaders["VertexColor"], modelMatrix);

        if (line2.activateLawnMower) {
            line2.lawnMowerX += deltaTimeSeconds * LAWNMOWER_SPEED;

            modelMatrix[2][0] = line2.lawnMowerX - 50;
            modelMatrix *= transform2D::Rotate(-line2.angularWheel);

            line2.angularWheel += 50 * deltaTimeSeconds;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);

            modelMatrix[2][0] = line2.lawnMowerX - 15;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);
        }
        else {
            modelMatrix[2][0] = line2.lawnMowerX - 50;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);

            modelMatrix[2][0] = line2.lawnMowerX - 15;

            RenderMesh2D(meshes["wheel"], shaders["VertexColor"], modelMatrix);
        }
    }
}


void tema::ActivateLawnMower(line* l) {

    if (!l->used_lawnMower) {
        for (auto& enemy : l->enemiesOnLine) {
            if (enemy.first.first < 120 && !l->activateLawnMower) {
                l->activateLawnMower = true;
                enemy.second.first -= 3;
                enemy.second.second = 0.80;
                continue;
            }

            if (enemy.first.first - l->lawnMowerX < 30 && enemy.first.first - l->lawnMowerX > -10 && l->activateLawnMower) {
                enemy.second.first -= 3;
                enemy.second.second = 0.80;
            }
            if (l->lawnMowerX > 1100) {
                l->used_lawnMower = true;
                l->activateLawnMower = false;
            }
        }
    }

}