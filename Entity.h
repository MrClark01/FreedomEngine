#include "Advanced2D.h"

#pragma once

namespace Freedom {

	enum EntityType
	{
		ENTITY_UNKNOWN = -1,
		ENTITY_MESH = 0,
		ENTITY_SPRITE,
		ENTITY_TIMER,
		ENTITY_SCRIPTED_SPRITE
	};

	enum RenderType
	{
		RENDER_NONE = 0,
        RENDER_2D,
        RENDER_3D
    };

	class Entity {
	private:
		int id;
		std::string name;
		bool visible;
		bool alive;
		enum RenderType renderType;
		int objectType;
		int lifetimeLength;
		Timer lifetimeTimer;

	public:
		Entity(enum RenderType renderType);
		virtual ~Entity() { };

		virtual void move() = 0;
		virtual void animate() = 0;
		virtual void draw() = 0;

		void setID(int value) { id = value; }
		int getID() { return id; }

		void setRenderType(enum RenderType type) { renderType = type; }
		enum RenderType getRenderType() { return renderType; }

		std::string getName() { return name; }
		void setName(std::string value) { name = value; }

		bool getVisible() { return visible; }
		void setVisible(bool value) { visible = value; }

		bool getAlive() { return alive; }
		void setAlive(bool value) { alive = value; }

		int getLifetime() { return lifetimeLength; }
		void setLifetime(int ms) { lifetimeLength = ms; lifetimeTimer.reset(); }
		bool lifetimeExpired() { return lifetimeTimer.stopwatch(lifetimeLength); }

		int getObjectType() { return objectType; }
		void setObjectType(int value) { objectType = value; }

	};


};
