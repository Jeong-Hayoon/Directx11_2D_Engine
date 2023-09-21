#pragma once
#include "hyGameObject.h"

namespace hy
{
	class Bullet : public GameObject
	{
	public:

		Bullet();
		virtual ~Bullet();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:


	};
}



