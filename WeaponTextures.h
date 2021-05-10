#include "SimpleSprite.h"

namespace weapons
{
	namespace textures
	{
		render::SimpleSprite sword1("Items/LongWep.png", { 0, 16 });
		render::SimpleSprite sword2("Items/LongWep.png", { 32, 16 });
		render::SimpleSprite spear("Items/LongWep.png", { 0, 32 });
		render::SimpleSprite scythe("Items/LongWep.png", { 16 * 3, 16 * 4 });
		render::SimpleSprite shovel("Items/LongWep.png", { 16 * 4, 16 * 4 }); //spoon
		render::SimpleSprite pickaxe("Items/ShortWep.png", { 16 * 2, 16 * 3 });
		render::SimpleSprite bow("Items/Ammo.png", { 0, 16 });
		render::SimpleSprite crystalBow("Items/Ammo.png", { 48, 16 });
		render::SimpleSprite rifle("Items/Ammo.png", { 16, 64 });
		render::SimpleSprite photoMachine("Items/Light.png", { 16 * 6, 0 });//flash
	}
}
