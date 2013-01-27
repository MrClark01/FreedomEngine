#include "Advanced2D.h"

namespace Freedom
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
