#include "Advanced2D.h"

namespace Freedom
{
	int UIBase::_controlid;

	UIBase::UIBase()
	{
		controlid = _controlid++;
		rect.set(0,0,0,0);
		linesize = 1;
		bordercolor = 0xffffffff; // White
		backcolor = 0xffcccccc;
		shape = new VectorShape();
	}

	UIBase::~UIBase()
	{
		delete shape;
	}

    // TODO: UIBase Method definitions
    /*
    UIBase methods (methods are part of a class, functions are stand alone)

    draw virtual
    update virtual
    OnMouseMove defined
    OnMouseClick defined
    OnMouseDrag defined
    */

	void UIBase::draw() {}
	void UIBase::update() {}

	void UIBase::OnMouseClick(int x, int y, int b)
	{
		if (!rect.isInside(x,y)) return;
		mousex = x;
		mousey = y;
		mouseb = b;
		mouseclick = true;
		int relativex = x - rect.left;
		int relativey = y - rect.top;
		//g_engine->message("Button Clicked!");
		//g_engine->raiseEvent(new Event(EVENT_GUI_MOUSECLICK, getID(), relativex, relativey, b));
	}

	void UIBase::OnMouseMove(int x,int y)
    {
        if (mouseclick) {
            mouseclick=false;
            OnMouseDrag(x,y);
            return;
        }
		mouseover=false;
		if (!rect.isInside(x,y)) return;
		mousex = x;
		mousey = y;
		mouseover = true;
        int relativex = x - rect.left;
        int relativey = y - rect.top;
		//g_engine->raiseEvent(new Event(EVENT_GUI_MOUSEMOVE, getID(), relativex, relativey));
    }

    void UIBase::OnMouseDrag(int x,int y)
    {
    	mouseover=false;
		if (!rect.isInside(x,y)) return;
		mousex = x;
		mousey = y;
		mouseover = true;
        int relativex = x - rect.left;
        int relativey = y - rect.top;
		//g_engine->raiseEvent(new Event(EVENT_GUI_MOUSEDRAG, getID(), relativex, relativey, mouseb));
    }

}; // namespace
