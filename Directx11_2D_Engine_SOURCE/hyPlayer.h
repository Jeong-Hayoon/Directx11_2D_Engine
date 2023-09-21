#pragma once
#include "hyGameObject.h"
#include "hyTransform.h"

namespace hy
{
	class Player : public GameObject
	{
	public:

		Player();
		virtual ~Player();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

	private:
		Transform* tr;
	};
}



