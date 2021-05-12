#include "DummyEntity.h"

namespace entities
{
    DummyEntity::DummyEntity(olc::vf2d pos, render::ITexture& skin, const std::string& name)
	    : CharacterEntity(skin, pos), name(name) {}
}
