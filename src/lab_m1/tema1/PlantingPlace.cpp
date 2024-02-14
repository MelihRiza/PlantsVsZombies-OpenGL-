#include "lab_m1/tema1/tema.h"

#include <vector>
#include <iostream>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"


using namespace std;
using namespace m1;


void tema::RenderLineOfSquares(line* l) {
    modelMatrix = glm::mat3(1);
    modelMatrix[2][0] = l->slot0X;
    modelMatrix[2][1] = l->slot0Y;

    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix[2][0] = l->slot1X;
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

    modelMatrix[2][0] = l->slot2X;
    RenderMesh2D(meshes["square1"], shaders["VertexColor"], modelMatrix);

}