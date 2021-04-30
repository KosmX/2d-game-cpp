#include "Entity.h"

namespace entities {
	Entity::Entity(render::ITexture& texture, const olc::vf2d& pos)
		:pos(pos), texture(texture)
	{
		
	}
	olc::vf2d Entity::getPos() const
	{
		return this->pos;
	}
	void Entity::render(olc::TransformedView& scene) const
	{
		this->texture.render(scene, *this);
	}
	Entity::~Entity()
	{
		delete &texture;
	}


}

olc::TransformedView& operator+=(olc::TransformedView& scene, entities::Entity& entity) {
	entity.render(scene);
	return scene;
}