#pragma once
#include "Advanced2D.h"

namespace Freedom
{
	class UIButton : public UIBase
	{
	private:
		D3DCOLOR mocolor, mccolor;
		int fontsize;
		Font *font;
		std::string text;

	public:
		enum Orientation
		{
			LABEL_LEFT = 0,
			LABEL_CENTER,
			LABEL_RIGHT
		};
		enum Orientation orient;

		UIButton();
		~UIButton();
		int init(Rect &r, std::string text = "Button", std::string fonttype = "Ariel", int fontsize = 18); // Verdana
		void setOrient(enum Orientation o) { orient = o; }
		void setBackColor(D3DCOLOR color) { backcolor = color; }
		void setMouseOverColor(D3DCOLOR color) { mocolor = color; }
		void setMouseClickColor(D3DCOLOR color) { mccolor = color; }
		void draw();
		void update();
		void OnMouseClick(int x, int y, int b);
		void OnMouseMove(int x,int y); //uncomment if you want to override base
        void OnMouseDrag(int x,int y);
		
		bool isPressed() { return mouseclick; }

	};  // class

}; // namespace
