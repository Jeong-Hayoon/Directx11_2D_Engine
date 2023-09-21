#include "hySceneManager.h"
#include "hyResources.h"
#include "hyTime.h"
#include "hyGameObject.h"
#include "hyTransform.h"
#include "hyInput.h"
#include "hyBullet.h"
#include "hyMeshRenderer.h"
#include "hyPlayer.h"
#include "hyObject.h"


namespace hy
{
	Scene* SceneManager::mActiveScene = nullptr;
	std::map<std::wstring, Scene*> SceneManager::mScenes = {};

	// Player* SceneManager::player = nullptr;
	// Transform* SceneManager::tr = nullptr;
	/*Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mPlayScene = nullptr;*/

	void SceneManager::Initialize()
	{
			//mPlayScene = new Scene();
			//mActiveScene = mPlayScene;
			//{
			//	Player* player = object::Instantiate<Player>(LAYERTYPE::Charactor);
			//	player->GetComponent<Transform>()->SetScale(Vector3(0.5f, 0.5f, 0.5f));
			//	//player->GetComponent<Transform>()->SetScale(Vector3(2.0f, 2.0f, 2.0f));

			//	MeshRenderer* meshRenderer = player->AddComponent<MeshRenderer>();
			//	meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
			//	meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));

			//	mPlayScene->AddGameObject(player, LAYERTYPE::Charactor);
			//}

			/*{
				GameObject* object = new GameObject();
				Transform* tr = new Transform();
				tr->SetPosition(Vector3(-0.5f, -0.2f, 0.0f));
				object->AddComponent(tr);

				MeshRenderer* meshRenderer = new MeshRenderer();
				meshRenderer->SetMesh(Resources::Find<Mesh>(L"TriangleMesh"));
				meshRenderer->SetShader(Resources::Find<Shader>(L"TriangleShader"));
				object->AddComponent(meshRenderer);

				mPlayScene->AddGameObject(object, LAYER::NONE);
			}*/
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();

	}

	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void SceneManager::Render()
	{
		mActiveScene->Render();
	}

	Scene* SceneManager::LoadScene(const std::wstring name)
	{
		std::map<std::wstring, Scene*>::iterator iter
			= mScenes.find(name);

		if (iter == mScenes.end())
			return nullptr;

		mActiveScene = iter->second;
		return iter->second;
	}
}
