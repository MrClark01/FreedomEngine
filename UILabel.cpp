#include "Advanced2D.h"

namespace Freedom
{
	UILabel::UILabel() : UIBase()
	{
		textcolor = 0xffffffff;
		orient = LABEL_LEFT;
		linesize = 1;
	}

	UILabel::~UILabel()
	{
		delete font;
	}

	int UILabel::init(Rect &r, std::string text, std::string fonttype, int fontsize)
	{
        rect = r;
		font = new Font( fonttype, fontsize );
		this->text = text;

        //return the control ID for event tracking
        return getID();
    }

	void UILabel::update()
	{
	}

	void UILabel::draw()
	{
		//if (linesize > 0)
		//	shape->drawBox( rect, linesize, bordercolor ); // Shape is from GUIBase

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
	}

	void UILabel::drawWithBox()
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
	}

    /**
    By overriding these base virtual methods, we eliminate the base events (if desired)
    **/
	void UILabel::OnMouseClick(int x,int y,int b)
	{
		UIBase::OnMouseClick(x, y, b);

		//g_engine->message("label clicked");
	}

    void UILabel::OnMouseMove(int x,int y) {}
    void UILabel::OnMouseDrag(int x,int y){}


}; // namespace
