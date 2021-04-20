#pragma once


namespace render
{


	/**
	 * Everything what can be rendered. PLS use as virtual
	 *
	 */
	class IRenderable
	{
	public:
		virtual void render() const = 0;
	};

}
