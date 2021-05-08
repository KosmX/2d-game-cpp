#include "TestGenerator.h"

#include "WallEntity.h"
#include "mainGame.h"
#include "PlayerEntity.h"
#include "CharacterTexture.h"

using namespace entities;
using namespace std;

void TestGenerator::generate(GameClient& client)
{
	auto* asd = new WallEntity({ -1, 0 });
	//some random walls, just because why not???
	client += make_shared<WallEntity>(*new WallEntity(olc::vf2d(0, 0)));
	client += make_shared<WallEntity>(*new WallEntity(olc::vf2d(-1, 1)));
	client += make_shared<WallEntity>(*new WallEntity(olc::vf2d(-2, 0)));
	client += make_shared<WallEntity>(*new WallEntity(olc::vf2d(-2, -1)));
	client += make_shared<WallEntity>(*new WallEntity(olc::vf2d(-1, -1)));
	client += make_shared<WallEntity>(*asd);

	client += make_shared<PlayerEntity>(*new PlayerEntity({ 0, -4 }, render::CharacterTexture::EngineerTexture));
}
