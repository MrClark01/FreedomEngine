#include "Advanced2D.h"
#pragma once

namespace Freedom
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
