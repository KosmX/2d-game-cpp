#pragma once
#include "EMGun.h"

namespace weapons
{
	
	class GlitchTexture : public render::ITexture
	{
	private:
		render::LazySprite sprite;
	public:
		GlitchTexture(const std::string& name = "FromMacskusz111/bug.png");
		void render(olc::TransformedView& scene, Entity& entity) override;
	};


	
	class GlitchGun :
		public EMGun
	{
		friend GlitchTexture;
	private:
		float timeState = 0;
		static GlitchTexture GlitchTexture;
		
	public:
		GlitchGun(float cooldownTime, int damage, float projectileSpeed = 10, const std::string& name = "RangedWeapon", const olc::vf2d& pos = { 0, 0 }, float energyRegen = 10);
		void spawnProjectile(std::shared_ptr<Entity>& user, const olc::vf2d& pos, const olc::vf2d& v0, int damage) override;
		bool update(float dTick) override;
	};


}
