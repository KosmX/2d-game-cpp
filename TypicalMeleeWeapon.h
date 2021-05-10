#pragma once
#include "MeleeWeapon.h"
namespace weapons {
    class TypicalMeleeWeapon :
        public MeleeWeapon
    {
    public:
        static TypicalMeleeWeapon sword;

    protected:
        float maxRange;
        std::function<bool(std::shared_ptr<Entity>, std::shared_ptr<Entity>)> getPredicator() override;
    };
}
