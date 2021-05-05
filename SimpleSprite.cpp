#include "SimpleSprite.h"
#include "Entity.h"

using namespace olc;

render::SimpleSprite::SimpleSprite(const std::string& name, const vi2d& pos, const vf2d& size)
	: sprite(name), uv(pos), size(size) {}

void render::SimpleSprite::render(olc::TransformedView& scene, entities::Entity& entity)
{
	this->sprite.render(scene, entity.getPos(), uv, size);
}
