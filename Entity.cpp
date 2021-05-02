#include "Entity.h"

#include <utility>

using namespace std;
using namespace olc;

// fine tuning the collision engine, the edges of a box won't collide
const float ignoreDistance = 0.01f;

namespace entities {
	/*
	 * hitBox calc
	 * @parameter other the other entity
	 * @return to move to avoid collision
	 */
	vf2d Entity::getCollision(const Entity& other)
	{
		const vf2d delta = this->getPos() - other.getPos();
		//pair<bool, bool> dir(delta.x < 0, delta.y < 0);
		vf2d dir(delta.x < 0 ? 1 : -1, delta.y < 0 ? 1 : -1);
		vf2d offset(abs(delta.x), abs(delta.y));
		vf2d hitSize = this->getHitBoxSize() + other.getHitBoxSize();
		offset -= hitSize;
		offset = vf2d(offset.x < 0 ? offset.x : 0, offset.y < 0 ? offset.y : 0);
		offset *= dir;
		hitSize -= vf2d(ignoreDistance, ignoreDistance);
		if (delta.x > hitSize.x) {
			offset.x = 0;
		}
		if (delta.y > hitSize.y) {
			offset.y = 0;
		}
		return offset;
	}

	
	Entity::Entity(const olc::vf2d& pos)
		: pos(pos)
	{
		
	}
	vf2d Entity::getPos() const
	{
		return this->pos;
	}
	void Entity::render(olc::TransformedView& scene)
	{
		getTexture().render(scene, *this);
	}

}

TransformedView& operator+=(olc::TransformedView& scene, entities::Entity& entity) {
	entity.render(scene);
	return scene;
}