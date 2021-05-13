#pragma once

#include "SimpleSprite.h"

namespace weapons
{
	namespace textures
	{
		inline render::SimpleSprite sword1("Items/LongWep.png", { 0, 16 });
		inline render::SimpleSprite sword2("Items/LongWep.png", { 32, 16 });
		inline render::SimpleSprite spear("Items/LongWep.png", { 0, 32 });
		inline render::SimpleSprite scythe("Items/LongWep.png", { 16 * 3, 16 * 4 });
		inline render::SimpleSprite shovel("Items/LongWep.png", { 16 * 4, 16 * 4 }); //spoon
		inline render::SimpleSprite pickaxe("Items/ShortWep.png", { 16 * 2, 16 * 3 });
		inline render::SimpleSprite bow("Items/Ammo.png", { 0, 16 });
		inline render::SimpleSprite crystalBow("Items/Ammo.png", { 48, 16 });
		inline render::SimpleSprite rifle("Items/Ammo.png", { 16, 64 });
		inline render::SimpleSprite photoMachine("Items/Light.png", { 16 * 6, 0 });//flash
	}
}
