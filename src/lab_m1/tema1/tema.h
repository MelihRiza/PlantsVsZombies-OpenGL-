#pragma once

#include "components/simple_scene.h"


#define TIME_RELOAD 5

namespace m1
{
    class line
    {
    public:
        line();
        line(int line_Ypos,
            int slot0X, int slot0Y,
            int slot1X, int slot1Y,
            int slot2X, int slot2Y,
            float enemiesY, float bulletsY,
            float lawnMowerX);
        ~line();


        int line_Ypos;
        int slot0X, slot0Y, slot1X, slot1Y, slot2X, slot2Y;
        bool occupied_slot0, occupied_slot1, occupied_slot2;
        bool used_lawnMower, activateLawnMower;

        float angularWheel;

        std::vector<std::pair<std::pair<float, int>, std::pair<int, float>>> enemiesOnLine; // (positionX and type) and (healh and scale)
        float enemiesY, bulletsY, lawnMowerX;
        float bulletRotation;

        std::vector<std::pair<std::pair<int, int>, std::pair<float, float>>> attackersOnLine; // (slot occupied and type) and (reload_time and scale)

        std::vector<std::tuple<float, int, float>> bulletsOnLine; // positionX, type, reload time

        bool spawnEnemy(int deltaTimeSeconds);
        int enemyType();


    };





    class tema : public gfxc::SimpleScene
    {
     public:
         tema();
        ~tema();

        void Init() override;

     private:
        void CreateMesh(const char* name, const std::vector<VertexFormat>& vertices, const std::vector<unsigned int>& indices);

        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;

        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;


        void RenderGameInterface(float deltaTimeSeconds);
        void RenderLineOfSquares(line* l);
        void RenderShop();
        void RenderLives();

        void SpawnEnemy(float deltaTimeSeconds, line* line, int enemy_type);
        void SpawnMoney(float deltaTimeSeconds);

        void DrawEnemies(float deltaTimeSeconds, line* line);
        void DrawStaticStar(float x, float y, float scale);
        void DrawMoneyStars();
        void DrawAttackerAtCursor(float x, float y, int type);
        void DrawAttackersOnBoard();
        void DrawLawnMowers(float deltaTimeSeconds);

        void advance_enemy(float deltaTimeSeconds, line* l0, line* l1, line* l2);

        void PlaceAttacker(float x, float y);
        void RemoveAttacker(float x, float y);
        void deleteAttacker(line* l, int idx);
       

        bool TakeMoney(float x, float y);
        void BuyAttacker(float x, float y);

        void KillEnemy(line* l, int idx);
        void KillAttacker(line* l, int idx);
        void DestroyBullet(line* l, int idx);

        void CheckEnemies(float deltaTimeSeconds, line* l);
        void DrawBullets(float deltaTimeSeconds, line* l);

        void Colide(line* l0, line* l1, line* l2);
        void DestroyAttacker(line* l0, line* l1, line* l2);

        int GenerateRandomNumber(int start, int end);

        void ActivateLawnMower(line *l);

        bool holdingAttacker;
        int attackerType;
        bool leftButtonPressed;


     protected:
        glm::mat3 modelMatrix;
        line line0, line1, line2;

        int lives_left;
        int money_left;
        float time_money_spawn;
        float time_passed_money;


        float currentXStar, currentYStar;
        float angularStep;

        float mouseXpos, mouseYpos;
       
        std::vector<std::pair<float, float>> starsMoney;


    };

    
}   // namespace m1
