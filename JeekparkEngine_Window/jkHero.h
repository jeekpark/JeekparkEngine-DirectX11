#pragma once

#include "..\JeekparkEngine_SOURCE\jkGameObject.h"

namespace jk
{

    class Hero : public GameObject
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

        Hero();
        ~Hero();

        void Initialize() override;
        void Update() override;
        void LateUpdate() override;
        void Render() override;

        void SetStats(const Stats& stats) { mStats = stats; }
        const Stats& GetStats() const { return mStats; }

        void SetLevel(int level) { mStats.Level = level; }
        void SetExperience(int experience) { mStats.Experience = experience; }
        void SetHealth(int health) { mStats.Health = health; }
        void SetMaxHealth(int maxHealth) { mStats.MaxHealth = maxHealth; }
        void SetMana(int mana) { mStats.Mana = mana; }
        void SetMaxMana(int maxMana) { mStats.MaxMana = maxMana; }
        void SetStrength(int strength) { mStats.Strength = strength; }
        void SetAgility(int agility) { mStats.Agility = agility; }
        void SetIntelligence(int intelligence) { mStats.Intelligence = intelligence; }
        void SetArmor(float armor) { mStats.Armor = armor; }
        void SetMagicResist(float magicResist) { mStats.MagicResist = magicResist; }
        void SetAttackDamage(int attackDamage) { mStats.AttackDamage = attackDamage; }
        void SetAttackRate(int attackRate) { mStats.AttackRate = attackRate; }
        void SetAttackRange(int attackRange) { mStats.AttackRange = attackRange; }
        void SetAttackSpeed(int attackSpeed) { mStats.AttackSpeed = attackSpeed; }
        void SetPreAttackTime(float preAttackTime) { mStats.PreAttackTime = preAttackTime; }
        void SetAttackTime(float attackTime) { mStats.AttackTime = attackTime; }
        void SetPostAttackTime(float postAttackTime) { mStats.PostAttackTime = postAttackTime; }
        void SetProjectileSpeed(int projectileSpeed) { mStats.ProjectileSpeed = projectileSpeed; }
        void SetTurnTime(float turnTime) { mStats.TurnTime = turnTime; }
        void SetVisionRange(int visionRange) { mStats.VisionRange = visionRange; }
        void SetGold(int gold) { mStats.Gold = gold; }

        int GetLevel() const { return mStats.Level; }
        int GetExperience() const { return mStats.Experience; }
        int GetHealth() const { return mStats.Health; }
        int GetMaxHealth() const { return mStats.MaxHealth; }
        int GetMana() const { return mStats.Mana; }
        int GetMaxMana() const { return mStats.MaxMana; }
        int GetStrength() const { return mStats.Strength; }
        int GetAgility() const { return mStats.Agility; }
        int GetIntelligence() const { return mStats.Intelligence; }
        float GetArmor() const { return mStats.Armor; }
        float GetMagicResist() const { return mStats.MagicResist; }
        int GetAttackDamage() const { return mStats.AttackDamage; }
        int GetAttackRate() const { return mStats.AttackRate; }
        int GetAttackRange() const { return mStats.AttackRange; }
        int GetAttackSpeed() const { return mStats.AttackSpeed; }
        float GetPreAttackTime() const { return mStats.PreAttackTime; }
        float GetAttackTime() const { return mStats.AttackTime; }
        float GetPostAttackTime() const { return mStats.PostAttackTime; }
        int GetProjectileSpeed() const { return mStats.ProjectileSpeed; }
        float GetTurnTime() const { return mStats.TurnTime; }
        int GetVisionRange() const { return mStats.VisionRange; }
        int GetGold() const { return mStats.Gold; }



    private:
        Stats mStats;
    };

}