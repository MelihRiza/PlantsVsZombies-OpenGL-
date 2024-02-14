#include "lab_m1/tema1/tema.h"

#include <vector>
#include <iostream>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/object2D.h"

using namespace std;
using namespace m1;



tema::tema()
{

}


tema::~tema()
{
}


void tema::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 30;


    // Create Squares

    Mesh* square1 = object2D::CreateSquare("square1", corner, squareSide * 4, glm::vec3(0.63, 0.57, 0.34), true);
    AddMeshToList(square1);

    Mesh* square2 = object2D::CreateSquare("square2", corner, squareSide * 3, glm::vec3(0.5, 0.5, 0.5));
    AddMeshToList(square2);

    Mesh* square3 = object2D::CreateSquare("square3", corner, squareSide * 3, glm::vec3(1, 0, 0), true);
    AddMeshToList(square3);

    // Create hexagons

    Mesh* hexagonMini = object2D::CreateHexagon("hexagonMini", corner, squareSide, glm::vec3(0, 0, 1), true);
    AddMeshToList(hexagonMini);

    Mesh* hexagon0 = object2D::CreateHexagon("hexagon0", corner, squareSide * 1.5, glm::vec3(1, 0, 0), true, true);
    AddMeshToList(hexagon0);

    Mesh* hexagon1 = object2D::CreateHexagon("hexagon1", corner, squareSide * 1.5, glm::vec3(0, 1, 1), true, true);
    AddMeshToList(hexagon1);

    Mesh* hexagon2 = object2D::CreateHexagon("hexagon2", corner, squareSide * 1.5, glm::vec3(1, 0.06, 0.94), true, true);
    AddMeshToList(hexagon2);

    Mesh* hexagon3 = object2D::CreateHexagon("hexagon3", corner, squareSide * 1.5, glm::vec3(0.22, 1, 0.08), true, true);
    AddMeshToList(hexagon3);

    // Create attackers (turrets)

    Mesh* attacker0 = object2D::CreateAttacker("attacker0", corner, squareSide * 1.5, glm::vec3(1, 0, 0), true);
    AddMeshToList(attacker0);

    Mesh* attacker1 = object2D::CreateAttacker("attacker1", corner, squareSide * 1.5, glm::vec3(0, 1, 1), true);
    AddMeshToList(attacker1);

    Mesh* attacker2 = object2D::CreateAttacker("attacker2", corner, squareSide * 1.5, glm::vec3(1, 0.06, 0.94), true);
    AddMeshToList(attacker2);

    Mesh* attacker3 = object2D::CreateAttacker("attacker3", corner, squareSide * 1.5, glm::vec3(0.22, 1, 0.08), true);
    AddMeshToList(attacker3);

    // stars

    Mesh* goldenStar = object2D::CreateStar("goldenStar", corner, squareSide * 1.5, glm::vec3(1, 0.847, 0), true);
    AddMeshToList(goldenStar);

    Mesh* starGray = object2D::CreateStar("starGray", corner, squareSide * 1.5, glm::vec3(0.5, 0.5, 0.5), true, true);
    AddMeshToList(starGray);

    Mesh* redStar = object2D::CreateStar("redStar", corner, squareSide, glm::vec3(1, 0, 0), true, true);
    AddMeshToList(redStar);

    Mesh* cyanStar = object2D::CreateStar("cyanStar", corner, squareSide, glm::vec3(0, 1, 1), true, true);
    AddMeshToList(cyanStar);

    Mesh* pinkStar = object2D::CreateStar("pinkStar", corner, squareSide, glm::vec3(1, 0.06, 0.94), true, true);
    AddMeshToList(pinkStar);

    Mesh* greenStar = object2D::CreateStar("greenStar", corner, squareSide, glm::vec3(0.22, 1, 0.08), true, true);
    AddMeshToList(greenStar);

    // LawnMower

    Mesh* lawnMower = object2D::CreateLawnMower("lawnMower", corner, squareSide * 2.2, glm::vec3(0.294, 0.325, 0.125), true);
    AddMeshToList(lawnMower);

    // Hearth

    Mesh* hearth = object2D::CreateHearth("hearth", corner, squareSide * 2.2, glm::vec3(1, 0, 0), true);
    AddMeshToList(hearth);

    Mesh* wheel = object2D::CreateWheel("wheel", corner, squareSide / 2, glm::vec3(0.5, 0.5, 0.5), true);
    AddMeshToList(wheel);


    line0 = line(50, 100, 50, 250, 50, 400, 50, 110, 110, 80);

    line1 = line(200, 100, 200, 250, 200, 400, 200, 260, 260, 80);

    line2 = line(350, 100, 350, 250, 350, 400, 350, 410, 410, 80);

    lives_left = 3;
    money_left = 5;

    time_money_spawn = GenerateRandomNumber(8, 15);
    time_passed_money = 0;

    angularStep = 1;
    currentXStar = 0;

    holdingAttacker = false;
    leftButtonPressed = false;

}


void tema::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);

}


void tema::Update(float deltaTimeSeconds)
{
    RenderGameInterface(deltaTimeSeconds);


    modelMatrix = glm::mat3(1);


    if (lives_left == 0) {
        cout << "Game Over! :(" << endl;
        exit(NULL);
    }

}


void tema::FrameEnd()
{
}

void tema::RenderGameInterface(float deltaTimeSeconds) {

    // render the squares (slots for planting)
    RenderLineOfSquares(&line0);
    RenderLineOfSquares(&line1);
    RenderLineOfSquares(&line2);

    modelMatrix[2][0] = 20;
    modelMatrix[2][1] = 50;
    modelMatrix *= transform2D::Scale(0.5, (float)42 / 9);
    RenderMesh2D(meshes["square3"], shaders["VertexColor"], modelMatrix);


    RenderShop();

    RenderLives();


    // render enemies
    if (line0.spawnEnemy(deltaTimeSeconds)) {
        int enemy_type = line0.enemyType();
        SpawnEnemy(deltaTimeSeconds, &line0, enemy_type);
    }
    else {
        DrawEnemies(deltaTimeSeconds, &line0);
    }
    if (line1.spawnEnemy(deltaTimeSeconds)) {
        int enemy_type = line1.enemyType();
        SpawnEnemy(deltaTimeSeconds, &line1, enemy_type);
    }
    else {
        DrawEnemies(deltaTimeSeconds, &line1);
    }
    if (line2.spawnEnemy(deltaTimeSeconds)) {
        int enemy_type = line2.enemyType();
        SpawnEnemy(deltaTimeSeconds, &line2, enemy_type);
    }
    else {
        DrawEnemies(deltaTimeSeconds, &line2);
    }

    advance_enemy(deltaTimeSeconds, &line0, &line1, &line2);

    SpawnMoney(deltaTimeSeconds);

    DrawMoneyStars();

    if (holdingAttacker && leftButtonPressed) {
        DrawAttackerAtCursor(mouseXpos, mouseYpos, attackerType);
    }

    DrawAttackersOnBoard();

    CheckEnemies(deltaTimeSeconds, &line0);
    CheckEnemies(deltaTimeSeconds, &line1);
    CheckEnemies(deltaTimeSeconds, &line2);

    DrawBullets(deltaTimeSeconds, &line0);
    DrawBullets(deltaTimeSeconds, &line1);
    DrawBullets(deltaTimeSeconds, &line2);

    Colide(&line0, &line1, &line2);
    DestroyAttacker(&line0, &line1, &line2);

    DrawLawnMowers(deltaTimeSeconds);

    ActivateLawnMower(&line0);
    ActivateLawnMower(&line1);
    ActivateLawnMower(&line2);
}







/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void tema::OnInputUpdate(float deltaTime, int mods)
{
}


void tema::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void tema::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void tema::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
    mouseXpos = mouseX;
    mouseYpos = 720 - mouseY;
}


void tema::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event
    float realY = 720 - mouseY;

    if (IS_BIT_SET(button, GLFW_MOUSE_BUTTON_LEFT)) {
        if (!TakeMoney(mouseX, realY)) {
            leftButtonPressed = true;
            BuyAttacker(mouseX, realY);
        }

    }
    else if (IS_BIT_SET(button, GLFW_MOUSE_BUTTON_RIGHT)) {
        // TODO remove an attacker
        RemoveAttacker(mouseX, realY);
    }

}


void tema::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
    if (IS_BIT_SET(button, GLFW_MOUSE_BUTTON_LEFT)) {
        float realY = 720 - mouseY;
        // TODO place attacker
        leftButtonPressed = false;
        if (holdingAttacker) {
            PlaceAttacker(mouseX, realY);
            holdingAttacker = false;
        }
    }
}


void tema::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void tema::OnWindowResize(int width, int height)
{
}
