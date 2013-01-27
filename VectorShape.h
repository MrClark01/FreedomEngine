#pragma once
#include "Advanced2D.h"

namespace Freedom
{
	class VectorShape
	{
	private:
		Texture *texture;
		Sprite *sprite;
		int size;

	public:
		VectorShape(void);
		~VectorShape(void);
		void MakeTexture();
		void drawPoint(Vector3 point, int linesize, D3DCOLOR color = 0xffffffff);
		void drawPoint(double x, double y, int linesize, D3DCOLOR color = 0xffffffff);
		void drawLine(Vector3 point1, Vector3 point2, int linesize, D3DCOLOR color = 0xffffffff);
		void drawLine(double x1, double y1, double x2, double y2, int linesize, D3DCOLOR color = 0xffffffff);
		void drawBox(Vector3 point1, Vector3 point2, int linesize, D3DCOLOR color = 0xffffffff);
		void drawBox(double x1, double y1, double x2, double y2, int linesize, D3DCOLOR color = 0xffffffff);
		void drawBox(Rect rect, int linesize, D3DCOLOR color = 0xffffffff);
        void drawFilledBox( Rect rect, D3DCOLOR color = 0xffffffff );

	}; // class

}; // namespace 
