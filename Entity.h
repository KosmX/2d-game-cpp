#pragma once

#include "olc.h"
#include "ITexture.h"

namespace entities {

	class Entity
	{
	protected:
		olc::vf2d pos; //I can store these safely directly
		render::ITexture& texture;
	public:

		Entity(render::ITexture& texture, const olc::vf2d& pos);
		
		virtual olc::vf2d getPos() const;

		virtual void tick(float deltaT);

		//this shouldn't change it's state
		virtual void render(olc::TransformedView& scene) const;

		virtual ~Entity();

		//TODO getAs*** stuff, all virtual
	};


}

/**
 * I literally add entities to the scene :D
 */
olc::TransformedView& operator+=(olc::TransformedView&, entities::Entity&);