#include "Entity.h"

namespace entities {
	Entity::Entity(render::ITexture& texture, const olc::vf2d& pos)
		:pos(pos), texture(texture)
	{
		
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