#include "hyGameObject.h"
#include "hyTransform.h"


namespace hy
{
	GameObject::GameObject()
		: mState(eState::Active)
	{
		// resize : ������ �뷮�� ������ ũ��� �ø���, �ش� ũ�⸸ŭ�� ������ ������ ������ �ʱ�ȭ
		// reserve() �Լ��� resize() �Լ��� �ִµ�, �� �Լ��� ���̴� �뷮 Ȯ�� �� 
		// �� ������ �ʱ�ȭ�� �ϴ��� ���� �ʴ����� ����
		//reserve(N) : N�� �뷮�� �̸� Ȯ���س���.
		// resize(N, number = 0) : N�� �뷮�� �̸� Ȯ���س��� ������ ������ �� ��° �Ű������� ������ ä��.�� ��° �Ű������� ������ 0
	
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

