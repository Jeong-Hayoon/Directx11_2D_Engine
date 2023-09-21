#include "hyLayer.h"


namespace hy
{
	Layer::Layer()
	{
	}
	Layer::~Layer()
	{
		for (GameObject* gameObject : mGameObjects)
		{
			delete gameObject;
			gameObject = nullptr;
		}
	}

	void Layer::Initialize()
	{
		/*for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Initialize();
		}*/

		for (int i = 0; i < mGameObjects.size(); i++)
		{
			/*if (mGameObjects[i]->GetState() == GameObject::eState::Pause)
				continue;*/

			mGameObjects[i]->Initialize();
		}


	}

	void Layer::Update()
	{
		/*for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Update();
		}*/

		for (int i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Update();
		}
	}

	void Layer::LateUpdate()
	{
		/*for (GameObject* gameObject : mGameObjects)
		{
			gameObject->LateUpdate();
		}*/

		for (int i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->LateUpdate();
		}
	}

	void Layer::Render()
	{
		/*for (GameObject* gameObject : mGameObjects)
		{
			gameObject->Render();
		}*/

		for (int i = 0; i < mGameObjects.size(); i++)
		{
			mGameObjects[i]->Render();
		}
	}

	void Layer::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}
}