#pragma once
#include "EMGun.h"

namespace weapons
{
	/**
	 * @brief Texture for the bug weapon
	*/
	class GlitchTexture : public render::ITexture
	{
	private:
		render::LazySprite sprite;
	public:
		/**
		 * @brief Texture from my friend, Macskusz111
		 * @param name the file path and name
		*/
		GlitchTexture(const std::string& name = "FromMacskusz111/bug.png");
		void render(olc::TransformedView& scene, Entity& entity) override;
	};


	/**
	 * @brief TODO make the bug weapon more buggy
	*/
	class GlitchGun :
		public EMGun
	{
		friend GlitchTexture;
	private:
		/**
		 * @brief internal variable for the animated texture
		*/
		float timeState = 0;
		static GlitchTexture GlitchTexture;
		
	public:
		GlitchGun(float cooldownTime, int damage, float projectileSpeed = 10, const std::string& name = "RangedWeapon", const olc::vf2d& pos = { 0, 0 }, float energyRegen = 10);
		/**
		 * @brief It does randomly shoot normal and explosive projectiles
		 * @param user the user
		 * @param pos where is the user
		 * @param v0 the base speed of the projectile
		 * @param damage how much damage does it have
		*/
		void spawnProjectile(std::shared_ptr<Entity>& user, const olc::vf2d& pos, const olc::vf2d& v0, int damage) override;
		bool update(float dTick) override;
	};


}
