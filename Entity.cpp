#include "Entity.h"
#include <sstream>

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
			offset.y = 0;
		}
		if (delta.y > hitSize.y) {
			offset.x = 0;
		}
		return offset;
	}

	
	Entity::Entity(const olc::vf2d& pos)
		: pos(pos), is_initialized(false), is_alive(true){}
	
	vf2d Entity::getPos() const
	{
		return this->pos;
	}
	
	vf2d Entity::getSize() const
	{
		return vf2d(1, 1);
	}
	
	void Entity::render(TransformedView& scene)
	{
		getTexture().render(scene, *this);
	}

	std::string Entity::getName() const
	{
		stringstream s;
		s << "Entity#" << this;
		return s.str();
	}


	bool Entity::isInitialized()
	{
		return is_initialized;
	}

	bool Entity::isAlive() const
	{
		return this->is_alive;
	}

}

TransformedView& operator+=(TransformedView& scene, entities::Entity& entity) {
	entity.render(scene);
	return scene;
}

TransformedView& operator+=(TransformedView& scene, std::shared_ptr<entities::Entity>& entity) {
	entity->render(scene);
	return scene;
}