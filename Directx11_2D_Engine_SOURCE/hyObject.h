#pragma once
#include "hyScene.h"
#include "hyGameObject.h"
#include "hySceneManager.h"
#include "hyTransform.h"

namespace hy::object
{
	template <typename T>
	static __forceinline T* Instantiate(LAYER type)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObject, type);
		gameObject->Initialize();
		gameObject->SetLayerType(type);

		return gameObject;
	}


	template <typename T>
	static __forceinline T* Instantiate(LAYER type, Vector2 position)
	{
		T* gameObject = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObject, type);
		gameObject->Initialize();
		gameObject->SetLAYER(type);
		gameObject->GetComponent<Transform>()->SetPosition(position);

		return gameObject;
	}

}

