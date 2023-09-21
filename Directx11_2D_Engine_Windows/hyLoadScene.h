#pragma once

#include "..\\Directx11_2D_Engine_SOURCE\\hySceneManager.h"

#include "hyPlayScene.h"


//#ifdef  _DEBUG

//#pragma comment(lib, "..\\x64\\Debug\\YamYamEngine_Windows.lib")

//#else

//#pragma comment(lib, "..\\x64\\Release\\YamYamEngine_Windows.lib")

//#endif //  _DEBUG




namespace hy

{

	void InitializeScenes()

	{

		SceneManager::CreateScene<PlayScene>(L"PlayScene");




		SceneManager::LoadScene(L"PlayScene");

	}

}