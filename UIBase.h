#include "Advanced2D.h"
#pragma once

namespace Freedom
{
  class UIBase
  {
    private:
		static int _controlid;

	protected:
		int controlid;
		int linesize;
		D3DCOLOR backcolor;
		D3DCOLOR bordercolor;
		D3DCOLOR textcolor;
		VectorShape *shape;
		bool mouseover, mouseclick;
		int mousex, mousey, mouseb;

	public:
		UIBase();
		virtual ~UIBase();
		virtual void setBorder(int size, D3DCOLOR col) { linesize = size; bordercolor = col; }
		virtual void setTextColor(D3DCOLOR color) { textcolor = color; }
		Rect rect;
		virtual Rect getRect() { return rect; }
		virtual int getX() { return (int)rect.left; }
		virtual int getY() { return (int)rect.top; }
		virtual int getID() { return controlid; }

		virtual void draw();
		virtual void update();
		virtual void OnMouseMove(int x, int y);
		virtual void OnMouseClick(int x, int y, int b);
		virtual void OnMouseDrag(int x, int y);
  };

};
