#include "Advanced2D.h"

namespace Advanced2D
{
	UITexturedButton::UITexturedButton()
	{
		pressedImage = NULL;
		unpressedImage = NULL;
	}

	UITexturedButton::~UITexturedButton()
	{
		pressedImage = NULL;
		delete pressedImage;
		unpressedImage = NULL;
		delete unpressedImage;
	}

}; // namespace