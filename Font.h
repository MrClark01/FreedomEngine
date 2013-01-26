#include "Advanced2D.h"
#pragma once

/*
	This bitmapped font with width data is preferrable to a DirectX font when cross-platform is an issue,
	but for Windows-only code it is not as good as ID3DXFont.
*/

namespace Advanced2D
{
	class Font
	{
	private:
		LPD3DXFONT fontObj;

	public:
		Font(std::string name, int pointsize);
		virtual ~Font() { }

		void Print(int x, int y, std::string text, int color = 0xFFFFFFFF);
		int getTextWidth(std::string text);
		int getTextHeight(std::string text);
	};
};