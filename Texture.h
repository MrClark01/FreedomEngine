#include "Advanced2D.h"

#ifndef _TEXTURE_H
#define _TEXTURE_H 1

namespace Advanced2D
{
	class Texture
	{
	public:
		LPDIRECT3DTEXTURE9 texture;
		D3DXIMAGE_INFO info;

		Texture();
		~Texture();
	//	bool create(int width,int height);
		bool Create(int width, int height, bool clear);
		bool Load(std::string filename, D3DCOLOR transcolor = D3DCOLOR_XRGB(0,0,0));
		bool Save(std::string filename, _D3DXIMAGE_FILEFORMAT format = D3DXIFF_BMP);
		void Release();

		bool CreateRenderTarget(int widht, int height);
		bool RenderStart(bool clear = true,	D3DCOLOR clearColor = 0xff000000);
		bool RenderStop();

		LPDIRECT3DTEXTURE9 GetTexture() { return texture; }
		int getWidth();
		int getHeight();
		RECT getBounds();

	private:
		// Surfaces act as targets for rendering (ie, the backbuffer is a surface that is used for rendering to the display)
		// A surface can be where drawing occurs (other than the backbuffer)
		LPDIRECT3DSURFACE9 renderDepthStencilSurface;
		LPDIRECT3DSURFACE9 renderSurface;
	};

}; // namespace

#endif
