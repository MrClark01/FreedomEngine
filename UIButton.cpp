#include "Advanced2D.h"

namespace Advanced2D
{
	UIButton::UIButton() : UIBase()
    {
		backcolor = 0xffcccccc;
		mocolor = 0xffeeeeee;
		mccolor = 0xffaaaaaa;
		//textcolor = 0xff000000; // original
		textcolor = 0xffffffff;
		orient = LABEL_LEFT;
		linesize = 1;
		mouseover = false;
		mousex = mousey = 0;
    }

	UIButton::~UIButton()
	{
		delete font;
	}

	int UIButton::init(Rect &r, std::string text, std::string fonttype, int fontsize)
	{
        rect = r;
		font = new Font( fonttype, fontsize );
		this->text = text;
		this->fontsize = fontsize;

        //return the control ID for event tracking
        return getID();
	}

	void UIButton::update()
	{
		if (!rect.isInside( mousex,mousey ))
		{
			mouseover=false;
		}
		mouseclick=false;
	}

	void UIButton::draw()
	{
		if (linesize > 0)
			shape->drawBox( rect, linesize, bordercolor ); // Shape is from GUIBase

		g_engine->SetSpriteIdentity();

		int x = (int)rect.left;
		int y = (int)rect.top;

		//for vertical positioning
		int texth = (int)font->getTextHeight(text);
		int centery = y + (int)rect.getHeight()/2 - texth/2;

		//for horizontal positioning
		int textw = font->getTextWidth(text);
		int centerx = x + (int)rect.getWidth()/2 - textw/2;
		int rightx = x + (int)rect.getWidth() - textw - 2;

		D3DCOLOR tcolor = backcolor;
		if (mouseover) tcolor = mocolor;
		if (mouseclick) tcolor = mccolor;

		//draw a fat line for the background
        //shape->drawFilledBox( rect, tcolor );
		//shape->drawBox( rect, linesize, bordercolor );

		switch(orient)
		{
			case LABEL_LEFT:
				font->Print( x+2, centery, text, textcolor );
				break;
			case LABEL_CENTER:
				font->Print( centerx, centery, text, textcolor );
				break;
			case LABEL_RIGHT:
				font->Print( rightx, centery, text, textcolor );
				break;
		}

		/*font->Print( centerx, centery, text, textcolor );
		if (fontsize > 14)
			font->Print( centerx+1, centery, text, textcolor );*/
	}

    /**
    If you override a base method but want to retain base functionality, be sure to call the base method
    and then you can do whatever additional processing you want.
    **/
	void UIButton::OnMouseClick(int x,int y,int b)
	{
        //call base method event
        UIBase::OnMouseClick(x,y,b);

        //now do additional things after a click
		if (!rect.isInside(x,y)) return;
		g_engine->message("Mouse clicked on Button");
	}

	void UIButton::OnMouseMove(int x,int y){}
    void UIButton::OnMouseDrag(int x,int y){}

}; // namespace

