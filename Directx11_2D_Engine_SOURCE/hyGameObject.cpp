#include "hyGameObject.h"
#include "hyTransform.h"


namespace hy
{
	GameObject::GameObject()
		: mState(eState::Active)
	{
		// resize : 벡터의 용량을 지정된 크기로 늘리고, 해당 크기만큼의 공간을 지정된 값으로 초기화
		// reserve() 함수와 resize() 함수가 있는데, 두 함수의 차이는 용량 확보 후 
		// 그 공간을 초기화를 하느냐 하지 않느냐의 차이
		//reserve(N) : N의 용량을 미리 확보해놓음.
		// resize(N, number = 0) : N의 용량을 미리 확보해놓고 나머지 공간을 두 번째 매개변수의 값으로 채움.두 번째 매개변수가 없으면 0
	
		mComponents.resize(COMPONENTTYPE::END);
		//AddComponent<Transform>();
	}

	GameObject::~GameObject()
	{

	}

	/*void GameObject::AddComponent(Component* component)
	{
		int myOrder = component->GetUpdateOrder();
		mComponents[myOrder] = component;
		mComponents[myOrder]->mOwner = this;
	}*/


	void GameObject::Initialize()
	{
		/*for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}*/

		for (int i = 0; i < mComponents.size(); i++)
		{
			if (mComponents[i] == nullptr)
				continue;

			mComponents[i]->Initialize();
		}

		for (Script* script : mScripts)
		{
			if (script == nullptr)
				continue;

			script->Initialize();
		}
	}
	void GameObject::Update()
	{
		/*for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}*/

		for (int i = 0; i < mComponents.size(); i++)
		{
			if (mComponents[i] == nullptr)
				continue;

			mComponents[i]->Update();
		}

		for (Script* script : mScripts)
		{
			if (script == nullptr)
				continue;

			script->Update();
		}	
	}

	void GameObject::LateUpdate()
	{
		/*for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->LateUpdate();
		}*/

		for (int i = 0; i < mComponents.size(); i++)
		{
			if (mComponents[i] == nullptr)
				continue;

			mComponents[i]->LateUpdate();
		}

		for (Script* script : mScripts)
		{
			if (script == nullptr)
				continue;

			script->LateUpdate();
		}

	}
	void GameObject::Render()
	{
		/*for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render();
		}*/

		for (int i = 0; i < mComponents.size(); i++)
		{
			if (mComponents[i] == nullptr)
				continue;

			mComponents[i]->Render();
		}

		for (Script* script : mScripts)
		{
			if (script == nullptr)
				continue;

			script->Render();
		}
	}
}

