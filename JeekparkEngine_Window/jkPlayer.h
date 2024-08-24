#pragma once

#include "..\JeekparkEngine_SOURCE\jkGameObject.h"

namespace jk
{

    class Player : public GameObject
    {
    public:
        struct Stats
        {
            int Level;
            int Experience;
            int Health;
            int MaxHealth;
            int Mana;
            int MaxMana;
            int Strength;
            int Agility;
            int Intelligence;
            float Armor;
            float MagicResist;
            int AttackDamage;
            int AttackRate;
            int AttackRange;
            int AttackSpeed;
            float PreAttackTime;
            float AttackTime;
            float PostAttackTime;
            int ProjectileSpeed;
            float TurnTime;
            int VisionRange;
            int Gold;
        };

        Player();
        ~Player();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render(HDC hdc) override;


    private:
        Stats mStats;
    };

}