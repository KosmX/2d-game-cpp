#include "TestGenerator.h"

#include "WallEntity.h"
#include "mainGame.h"
#include "PlayerEntity.h"
#include "CharacterTexture.h"
#include "DummyEntity.h"
#include "TypicalMeleeWeapon.h"
#include "EMGun.h"

using namespace entities;
using namespace std;

shared_ptr<PlayerEntity> TestGenerator::generate(GameClient& client)
{
	auto* asd = new WallEntity({ -1, 0 });
	//some random walls, just because why not???
	client += make_shared<WallEntity>(*new WallEntity(olc::vf2d(0, 0)));
	client += make_shared<WallEntity>(*new WallEntity(olc::vf2d(-1, 1)));
	client += make_shared<WallEntity>(*new WallEntity(olc::vf2d(-2, 0)));
	client += make_shared<WallEntity>(*new WallEntity(olc::vf2d(-2, -1)));
	client += make_shared<WallEntity>(*new WallEntity(olc::vf2d(-1, -1)));
	client += make_shared<WallEntity>(*asd);

	client += make_shared<CharacterEntity>(*new DummyEntity(olc::vf2d(5, 6), render::CharacterTexture::MageTexture));

	auto weapon = make_shared<weapons::TypicalMeleeWeapon>(*new weapons::TypicalMeleeWeapon(weapons::TypicalMeleeWeapon::sword));
	auto weapon1 = make_shared<weapons::Pistol>(*new weapons::Pistol(weapons::RangedWeapon::pistol));
	auto weapon2 = make_shared<weapons::Pistol>(*new weapons::EMGun(weapons::RangedWeapon::emgun));

	weapon->setPos({ -3, -4 });
	weapon1->setPos({ -4, -4 });
	weapon2->setPos({ -4, -5 });
	
	client += weapon;
	client += weapon2;
	client += weapon1;
	shared_ptr<PlayerEntity> player(new PlayerEntity({ 0, -4 }, render::CharacterTexture::EngineerTexture));


	client += player;
	return player;
}
