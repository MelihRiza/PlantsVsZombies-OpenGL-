#include "object2D.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* object2D::CreateSquare(
    const std::string &name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0, -2), color),
        VertexFormat(corner + glm::vec3(length, 0, -2), color),
        VertexFormat(corner + glm::vec3(length, length, -2), color),
        VertexFormat(corner + glm::vec3(0, length, -2), color)
    };

    Mesh* square = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        square->SetDrawMode(GL_LINE_LOOP);
    } else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    square->InitFromData(vertices, indices);
    return square;
}

Mesh* object2D::CreateHexagon(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill, bool back)
{
    glm::vec3 corner = leftBottomCorner;

    float incX = length / 8;
    float incY = length / 4;

    std::vector<VertexFormat> vertices;
    if (!back) {
        vertices =
        {
            VertexFormat(corner, color),
            VertexFormat(corner + glm::vec3(- length, 0, 0), color),
            VertexFormat(corner + glm::vec3(- length / 2, 0.866 * length, 0), color),
            VertexFormat(corner + glm::vec3(length / 2, 0.866* length, 0), color),
            VertexFormat(corner + glm::vec3(length, 0, 0), color),
            VertexFormat(corner + glm::vec3(length / 2, - 0.866 * length, 0), color),
            VertexFormat(corner + glm::vec3(- length / 2,- 0.866 * length, 0), color),

        };
    }
    else {
        vertices =
        {
            VertexFormat(corner + glm::vec3(0, 0, -1), color),
            VertexFormat(corner + glm::vec3(-length, 0, -1), color),
            VertexFormat(corner + glm::vec3(-length / 2, 0.866 * length, -1), color),
            VertexFormat(corner + glm::vec3(length / 2, 0.866 * length, -1), color),
            VertexFormat(corner + glm::vec3(length, 0, -1), color),
            VertexFormat(corner + glm::vec3(length / 2, -0.866 * length, -1), color),
            VertexFormat(corner + glm::vec3(-length / 2,-0.866 * length, -1), color),

        };
    }

    Mesh* hexagon = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2,
                                          0, 2, 3,
                                          0, 3, 4,
                                          0, 4, 5,
                                          0, 5, 6,
                                          0, 6, 1,
                                                   };

    if (!fill) {
        hexagon->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    hexagon->InitFromData(vertices, indices);
    return hexagon;
}



Mesh* object2D::CreateAttacker(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0, 3), color),
        VertexFormat(corner + glm::vec3(length / 2, length, 3), color),
        VertexFormat(corner + glm::vec3(length, 0, 3), color), // C
        VertexFormat(corner + glm::vec3(length / 2, -length, 3), color), // B
        VertexFormat(corner + glm::vec3(length / 2, 0, 3), color), // I

        VertexFormat(corner + glm::vec3(length / 2 + 3 / 4 * length, length / 4, 3), glm::vec3(0.5, 0.5, 0.5)),
        VertexFormat(corner + glm::vec3(length / 2 + 3 / 4 * length, - length / 4, 3), glm::vec3(0.5, 0.5, 0.5)),
        VertexFormat(corner + glm::vec3(1.5 * length, length / 4, 3), glm::vec3(0.5, 0.5, 0.5)),
        VertexFormat(corner + glm::vec3(1.5 * length, -length / 4, 3), glm::vec3(0.5, 0.5, 0.5)),
    };

    Mesh* attacker = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 4, 1,
                                          1, 4, 2,
                                          2, 4, 3,
                                          3, 4, 0,
                                          
                                            4, 6, 5,
                                            5, 6, 7,
                                            7, 6, 8};

    if (!fill) {
        attacker->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    attacker->InitFromData(vertices, indices);
    return attacker;
}


Mesh* object2D::CreateStar(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill, bool back)
{
    glm::vec3 corner = leftBottomCorner;

    float zPos = 0;
    if (!back) {
        zPos = 5;
    }

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0, zPos), color), // centru 0 
        VertexFormat(corner + glm::vec3(0, length, zPos), color), // sus 1
        VertexFormat(corner + glm::vec3(- 0.962 * length, 0.34 * length, zPos), color), // stanga 2
        VertexFormat(corner + glm::vec3(0.962 * length, 0.34 * length, zPos), color), // dreapta 3
        VertexFormat(corner + glm::vec3(- 0.62 * length,- length * 0.83, zPos), color), // stanga jos 4
        VertexFormat(corner + glm::vec3(0.62 * length, -  length * 0.83, zPos), color),  // dreapta jos 5

        VertexFormat(corner + glm::vec3(0, -0.37 * length, zPos), color), // centru jos
    };

    Mesh* star = new Mesh(name);
    std::vector<unsigned int> indices = {
                                            2, 3, 6,
                                            1, 4, 6,
                                            1, 6, 5
                                        };

    if (!fill) {
        star->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    star->InitFromData(vertices, indices);
    return star;
}


Mesh* object2D::CreateLawnMower(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0, 2), color),
        VertexFormat(corner + glm::vec3(-length, 0, 2), color),
        VertexFormat(corner + glm::vec3(-length, 2 * length, 2), color),
        VertexFormat(corner + glm::vec3(- 0.6 * length, length, 2), color),
        VertexFormat(corner + glm::vec3(- 0.2 * length, length, 2), color)
    };

    Mesh* LawnMower = new Mesh(name);
    std::vector<unsigned int> indices = {
                                        0, 3, 4,
                                        0, 1, 3,
                                        1, 2 ,3};

    if (!fill) {
        LawnMower->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    LawnMower->InitFromData(vertices, indices);
    return LawnMower;
}


Mesh* object2D::CreateHearth(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(0, 0, -2), color),
        VertexFormat(corner + glm::vec3(0, length / 4, -2), color),
        VertexFormat(corner + glm::vec3(length / 4, length * 0.57, -2), color),
        VertexFormat(corner + glm::vec3(0.57 * length, length * 0.75, -2), color),
        VertexFormat(corner + glm::vec3(length, length * 0.5, -2), color),
        VertexFormat(corner + glm::vec3(0.9 * length, 0, -2), color),
        VertexFormat(corner + glm::vec3(0, -length, -2), color),
        VertexFormat(corner + glm::vec3(-0.9 * length, 0, -2), color),
        VertexFormat(corner + glm::vec3(-length, length * 0.5, -2), color),
        VertexFormat(corner + glm::vec3(-0.57 * length, length * 0.75, -2), color),
        VertexFormat(corner + glm::vec3( -length / 4, length * 0.57, -2), color),
    };

    Mesh* hearth = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2,
                                          0, 2, 3,
                                          0, 3, 4,
                                          0, 4, 5,
                                          0, 5, 6,
                                          0, 6, 7,
                                          0, 7, 8,
                                          0, 8, 9,
                                          0, 9, 10,
                                          0, 10, 1};

    if (!fill) {
        hearth->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    hearth->InitFromData(vertices, indices);
    return hearth;
}


Mesh* object2D::CreateWheel(
    const std::string& name,
    glm::vec3 leftBottomCorner,
    float length,
    glm::vec3 color,
    bool fill)
{
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices =
    {
        VertexFormat(corner + glm::vec3(-length / 2, - length / 2, 4), color),
        VertexFormat(corner + glm::vec3(- length / 2, length / 2, 4), color),
        VertexFormat(corner + glm::vec3(length / 2, length / 2, 4), color),
        VertexFormat(corner + glm::vec3(length / 2, - length / 2, 4), color)
    };

    Mesh* wheel = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        wheel->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    wheel->InitFromData(vertices, indices);
    return wheel;
}