#pragma once
#include "Advanced2D.h"

namespace Freedom
{
	class UILabel : public UIBase
	{
	private:
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

		UILabel();
		~UILabel();
		int init(Rect &r, std::string text = "Label", std::string fonttype = "Ariel", int fontsize = 18);
		void setOrient(enum Orientation o) { orient = o; }
		void setText(std::string t) { text = t; }
		void draw();
		void drawWithBox();
		void update();

		// These methods can be used to override GUIBase events if you want to prevent them from firing
		void OnMouseMove(int x, int y);
		void OnMouseClick(int x, int y, int b);
		void OnMouseDrag(int x, int y);

	}; // class

};  // namespace
