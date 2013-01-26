#include "Advanced2D.h"
#include "Entity.h"
#pragma once

namespace Advanced2D
{
	enum CollisionType
	{
		COLLISION_NONE = 0,
		COLLISION_RECT = 1,
		COLLISION_DIST = 2
	};

	class Sprite : public Entity // Sprite class code omitted
	{
	private:
		Vector3 position;
		Vector3 velocity;
		bool imageLoaded;
		int state;
		int direction;

	protected:
		Texture *image;
		int width, height;
		int animcolumns;
		int framestart, frametimer;
		int movestart, movetimer;
		bool collidable;
		enum CollisionType collisionMethod;
		int curframe, totalframes, animdir;
		double faceAngle, moveAngle;
		int animstartx, animstarty;
		double rotation, scaleh, scalev;
		D3DXMATRIX matRotate;
		D3DXMATRIX matScale;
		void transform();
		D3DCOLOR color;
		int firstframe, lastframe;

	public:
		Sprite();
		virtual ~Sprite();
		bool loadImage(std::string filename, D3DCOLOR transcolor = D3DCOLOR_XRGB(255, 0, 255));
		void setImage(Texture *);
		void move();
		void animate();
		void update();
		void animate(int first, int last);
		void draw();
		void drawPivoted(double centerx, double centery);
		void drawFast();

		// screen position
		Vector3 getPosition() { return position; }
		void setPosition(Vector3 position) { this->position = position; }
		void setPosition(double x, double y) { position.Set(x, y, 0); }
		double getX() { return position.getX(); }
		double getY() { return position.getY(); }
		void setX(double x) { return position.setX(x); }
		void setY(double y) { return position.setY(y); }

		// movement velocity
		Vector3 getVelocity() { return velocity; }
		void setVelocity(Vector3 v) { this->velocity = v; }
		void setVelocity(double x, double y) { velocity.setX(x); velocity.setY(y); }

		// image size
		void setSize(int width, int height) { this->width = width; this->height = height; }
		int getWidth() { return this->width; }
		void setWidth(int value) { this->width = value; }
		int getHeight() { return this->height; }
		void setHeight(int value) { this->height = value; }

		int getState() { return state; }
		void setState(int value) { state = value; }

		int getDirection() { return direction; }
		void setDirection(int value) { direction = value; }

		int getColumns() { return animcolumns; }
		void setColumns(int value) { animcolumns = value; }

		int getFrameTimer() { return frametimer; }
		void setFrameTimer(int value) { frametimer = value; }

		int getCurrentFrame() { return curframe; }
		void setCurrentFrame(int value) { curframe = value; }

		int getTotalFrames() { return totalframes; }
		void setTotalFrames(int value)
		{
			this->totalframes = value;
			this->firstframe = 0;
			this->lastframe = value - 1;
		}

		int getAnimationDirection() { return animdir; }
		void setAnimationDirection(int value) { animdir = value; }

		double getRotation() { return rotation; }
		void setRotation(double value) { rotation = value; }
		double getScaleH() { return scaleh; }
		double getScaleV() { return scalev; }
		void setScale(double horiz, double vert) { scaleh = horiz, scalev = vert; }

		D3DCOLOR getColor() { return color; }
		void setColor(D3DCOLOR col) { color = col; }

		int getMoveTimer() { return movetimer; }
		void setMoveTimer(int value) { movetimer = value; }

		bool isCollidable() { return collidable; }
		void setCollidable(bool value) { collidable = value; }
		CollisionType getCollisionMethod() { return collisionMethod; }
		void setCollisionMethod(CollisionType type) { collisionMethod = type; }
        RECT getBounds();

		int getFirstFrame() { return firstframe; }
		void setFirstFrame(int value) { firstframe = value; }
		int getLastFrame() { return lastframe; }
		void setLastFrame(int value) { lastframe = value; }

	}; // class

}; // namespace
