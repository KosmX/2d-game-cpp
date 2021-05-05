#include "SimpleSprite.h"

render::SimpleSprite::SimpleSprite(const std::string name, olc::vi2d pos)
	: sprite(name, pos)
{
	
}

void render::SimpleSprite::render(olc::TransformedView& scene, entities::Entity& entity)
{
	this->sprite.render(scene, entity.getPos());
}
