#include "Advanced2D.h"

namespace Freedom
{
	Font::Font(std::string name, int pointsize)
	{
		fontObj = NULL;

		D3DXFONT_DESC fontDesc =
		{
			pointsize,				//height
			0,						//width
			0,						//weight
			0,						//miplevels
			false,					//italic
			DEFAULT_CHARSET,		//charset
			OUT_TT_PRECIS,			//output precision
			CLIP_DEFAULT_PRECIS,	//quality
			DEFAULT_PITCH,			//pitch and family
			""
		};
		strcpy(fontDesc.FaceName, name.c_str());

		D3DXCreateFontIndirect(g_engine->getDevice(), &fontDesc, &fontObj);
	}

	void Font::Print(int x, int y, std::string text, int color)
	{
		// figure out the text boundary
		RECT rect = { x, y, 0, 0 };
		fontObj->DrawTextA(NULL, text.c_str(), text.length(), &rect, DT_CALCRECT, color);

		// print the text
		fontObj->DrawTextA(g_engine->getSpriteHandler(), text.c_str(), text.length(), &rect, DT_LEFT, color);
	}

	int Font::getTextWidth(std::string text)
	{
		RECT rect = { 0, 0, 0, 0 };
		fontObj->DrawTextA(NULL, text.c_str(), text.length(), &rect, DT_CALCRECT, 0xffffffff);
		return rect.right;
	}

	int Font::getTextHeight(std::string text)
	{
		RECT rect = { 0, 0, 0, 0 };
		fontObj->DrawText( NULL, text.c_str(), text.length(), &rect, DT_CALCRECT, 0xffffffff);
		return rect.bottom;
	}

}; // namespace
