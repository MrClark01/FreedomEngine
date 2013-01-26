#include "Advanced2D.h"
#pragma once

namespace Advanced2D
{
	class UITexturedButton : public UIButton
	{
	private:
		Texture* unpressedImage;
		Texture* pressedImage;

	public:
		UITexturedButton();
		~UITexturedButton();

		void setPressedImage(Texture* texture) { pressedImage = texture; }
		void setUnpressedImage(Texture* texture) { unpressedImage = texture; }

		Texture* getPressedImage() { return pressedImage; }
		Texture* getUnpressedImage() { return unpressedImage; }

	}; // class

}; // namespace