#include "WallTexture.h"
#include "WallEntity.h"
#include "GameException.h"

using namespace olc;
using namespace entities;

namespace render
{

	
	WallTexture::WallTexture(const std::string& resName, const vf2d& baseOffset, const vf2d& size)
		: sprite(resName), baseOffset(baseOffset * size), size(size) {}
	void WallTexture::render(olc::TransformedView& scene, Entity& entity)
	{
		if(dynamic_cast<WallEntity*>(&entity) == nullptr){
			throw GameException("Wall texture needs a wall entity", entity);
		}
		auto& wallEntity = dynamic_cast<WallEntity&>(entity);
		vf2d offset = this->baseOffset;

		//I can't use index[] because that is not const function... WHY???
		offset += (offsetMap.find(wallEntity.getNeighbourID())->second * this->size);
		this->sprite.renderCentered(scene, wallEntity.getPos(), offset, size, wallEntity.getSize());
	}




	
	//Wall neighbour texture offset mapping
	const std::map<byte, vi2d> WallTexture::offsetMap = {
		{0b0000, vi2d(1, 1) }, {0b0001, vi2d(1, 1)}, {0b0010, vi2d(0, 1)}, {0b0011, vi2d(0, 1)},
		{0b0100, vi2d(1, 0) }, {0b0101, vi2d(2, 2)}, {0b0110, vi2d(2, 0)}, {0b0111, vi2d(5, 1)},
		{0b1000, vi2d(1, 0) }, {0b1001, vi2d(0, 2)}, {0b1010, vi2d(0, 0)}, {0b1011, vi2d(3, 1)},
		{0b1100, vi2d(1, 0) }, {0b1101, vi2d(4, 2)}, {0b1110, vi2d(4, 0)}, {0b1111, vi2d(4, 1)}
	};
}