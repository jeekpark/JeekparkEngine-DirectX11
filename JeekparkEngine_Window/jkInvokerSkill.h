#pragma once

#include "CommonInclude.h"

namespace jk
{

    class InvokerSkill
    {
    public:
        enum class eElement
        {
            Quas,
            Wex,
            Exort,
        };
        enum class eSpell
        {
            ColdSnap,
            GhostWalk,
            IceWall,
            EMP,
            Tornado,
            Alacrity,
            SunStrike,
            ForgeSpirit,
            ChaosMeteor,
            DeafeningBlast,
        };

        InvokerSkill();
        ~InvokerSkill();

        void UseQuas();
        void UseWex();
        void UseExort();
        void UseSpellCombination();
        void UseSpell();
    private:
        eElement mSpellCombination[3];
        eSpell mSpell[2];

    };

}