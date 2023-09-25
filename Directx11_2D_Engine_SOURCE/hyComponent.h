#pragma once
#include "hyEnums.h"
#include "hyEntity.h"
#include "hyMath.h"

namespace hy
{
	using namespace enums;
	using namespace math;

	class GameObject;
	class Component : public Entity
	{
	public:
		friend GameObject;

		// 생성자에서 COMPONENTTYPE 지정
		Component(COMPONENTTYPE type);
		virtual ~Component();

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		virtual void LateUpdate() = 0;
		virtual void Render() = 0;

		GameObject* GetOwner() { return mOwner; }
		void SetOwner(class GameObject* owner) { mOwner = owner; }

		UINT GetUpdateOrder() { return (UINT)mType; }

	private:
		const COMPONENTTYPE mType;
		GameObject* mOwner;
	};
}
