#include "SquareRoomGenerator.h"
#include "olc.h"

#include "PlayerEntity.h"
#include "GlitchGun.h"
#include "TypicalMeleeWeapon.h"
#include "WallEntity.h"
#include <random>

#include "CharacterTexture.h"
#include "mainGame.h"
#include "EntityWithAI.h"

const int maxSize = 64;
const int minSize = 32;

using namespace olc;
using namespace weapons;
using namespace entities;
using namespace render;
using namespace std;

std::shared_ptr<PlayerEntity> SquareRoomGenerator::generate(GameClient& client)
{
	int x, y;
	x = rand() % (maxSize - minSize) + minSize;
	y = rand() % (maxSize - minSize) + minSize;
	for(int i = 0; i < x; i++){
		for (int j = 0; j < y; j++) {
			if((i == 0 || i == x - 1) || j == 0 || j == y-1){
				client += shared_ptr<WallEntity>(new WallEntity(vf2d(i, j)));
			}
			else if(j != 1 && i != 1){
				int r = rand() % 256;
				if(r == 1){
					auto weapon = make_shared<weapons::TypicalMeleeWeapon>(*new weapons::TypicalMeleeWeapon(weapons::TypicalMeleeWeapon::spoon));
					weapon->setPos(vf2d(i, j));
					client += weapon;
				}
				else if(r == 2){
					auto weapon = make_shared<weapons::TypicalMeleeWeapon>(*new weapons::TypicalMeleeWeapon(weapons::TypicalMeleeWeapon::longSword));
					weapon->setPos(vf2d(i, j));
					client += weapon;
				}
				else if(r == 3){
					auto weapon = make_shared<weapons::Pistol>(*new weapons::Pistol(weapons::RangedWeapon::pistol));
					weapon->setPos(vf2d(i, j));
					client += weapon;
				}
				else if(r == 4){
					auto weapon = make_shared<weapons::EMGun>(*new weapons::EMGun(weapons::RangedWeapon::emgun)); //bee careful with make_shared?!
					weapon->setPos(vf2d(i, j));
					client += weapon;
				}
				else if(r == 5){
					shared_ptr<weapons::Weapon> weapon(new weapons::GlitchGun(0.3f, 40, 10, "GItc|_|Un"));
					weapon->setPos(vf2d(i, j));
					client += weapon;
				}
				else if (r < 24) {
					client += shared_ptr<WallEntity>(new WallEntity(vf2d(i, j)));
				}
				else if(r < 40){
					shared_ptr<EntityWithAI> enemy(new EntityWithAI(vf2d(i, j), rand() % 2 ? CharacterTexture::WarriorTexture : CharacterTexture::PaladinTexture));
					int r2 = rand() % 3;
					shared_ptr<Weapon> weapon;
					switch (r2) {
					case 0:
						weapon = shared_ptr<Weapon>(new Pistol(weapons::RangedWeapon::pistol));
						break;
					case 1:
						weapon = shared_ptr<Weapon>(new TypicalMeleeWeapon(TypicalMeleeWeapon::sword));
						break;
					default:
						weapon = nullptr;
					}
					enemy->addWeapon(weapon);
					client += enemy;
				}
			}
		}
	}
	
	std::shared_ptr<PlayerEntity> player(new PlayerEntity({ 1, 1 }, rand() % 2 ? CharacterTexture::MageTexture : CharacterTexture::EngineerTexture));

	client += player;
	return player;
	
}
