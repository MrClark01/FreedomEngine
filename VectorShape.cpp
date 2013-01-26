#include "Advanced2D.h"

namespace Advanced2D
{

	VectorShape::VectorShape(void)
	{
		texture = NULL;
		sprite = NULL;
		size = -1;
	}

	void VectorShape::MakeTexture()
	{
		//validate VectorShape size
		if (size < 1) return;

		//create the texture
		if (texture) delete texture;
		texture = new Texture();
		if (!texture->Create(128, size, true))
		{
			g_engine->message("Error creating VectorShape texture");
			g_engine->Shutdown();
		}

		//create the sprite
		if (sprite) delete sprite;
		sprite = new Sprite();
		sprite->setImage( texture );
	}

	VectorShape::~VectorShape(void)
	{
		if (texture) delete texture;
		if (sprite) delete sprite;
	}


	void VectorShape::drawLine(Vector3 point1, Vector3 point2, int linesize, D3DCOLOR color)
	{
		//if VectorShape size changed, texture must be recreated
		if (size != linesize)
		{
			size = linesize;
			MakeTexture();
		}

		//position start of line at startpos
		sprite->setPosition( point1 );

		//set scale so line reaches point2
		double dist = g_engine->math->Distance( point1, point2 );
			//Math::Distance( point1, point2 );
		double w = (double)sprite->getWidth();
		double scale = dist / w;
		sprite->setScale( scale, 1.0 );

		//rotate VectorShape to aim it at endpos
		double angle = g_engine->math->AngleToTarget( point1, point2 );
		sprite->setRotation( angle );

		//line will be drawn from upper-left corner at
		//point1 with pivot at 0,0 and rotated toward poin2
		sprite->setColor( color );
		sprite->drawPivoted(0,0);
	}

	void VectorShape::drawLine(double x1, double y1, double x2, double y2, int linesize, D3DCOLOR color)
	{
		Vector3 p1(x1,y1,0.0);
		Vector3 p2(x2,y2,0.0);
		this->drawLine( p1, p2, linesize, color );
	}

	void VectorShape::drawPoint(Vector3 point, int linesize, D3DCOLOR color)
	{
		Vector3 stretch(point.x+linesize, point.y, 0.0);
		this->drawLine(point, stretch, linesize, color);
	}

	void VectorShape::drawPoint(double x, double y, int linesize, D3DCOLOR color)
	{
		Vector3 point(x,y,0.0);
		this->drawPoint(point, linesize, color);
	}

	void VectorShape::drawBox(Vector3 point1, Vector3 point2, int linesize, D3DCOLOR color)
	{
		//top line
		Vector3 upperRight(point2.x, point1.y, 0.0);
		this->drawLine(point1, upperRight, linesize, color);

		//left line
		Vector3 lowerLeft(point1.x, point2.y, 0.0);
		this->drawLine(lowerLeft, point1, linesize, color);

		//right line
		this->drawLine(upperRight, point2, linesize, color);

		//bottom line
		this->drawLine(point2, lowerLeft, linesize, color);
	}

	void VectorShape::drawBox(double x1, double y1, double x2, double y2, int linesize, D3DCOLOR color)
	{
		Vector3 p1(x1,y1,0.0);
		Vector3 p2(x2,y2,0.0);
		this->drawBox( p1, p2, linesize, color );
	}

	void VectorShape::drawBox(Rect rect, int linesize, D3DCOLOR color)
	{
		Vector3 p1(rect.left, rect.top, 0.0);
		Vector3 p2(rect.right, rect.bottom, 0.0);
		this->drawBox( p1, p2, linesize, color );
	}

    void VectorShape::drawFilledBox( Rect rect, D3DCOLOR color )
    {
	    Vector3 p1( rect.left, rect.top, 0.0 );
		Vector3 p2( rect.right, rect.top, 0.0 );
		this->drawLine( p1, p2, rect.bottom-rect.top, color );
	}

}; // namespace
