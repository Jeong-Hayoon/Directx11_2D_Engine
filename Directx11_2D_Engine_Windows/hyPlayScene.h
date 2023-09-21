#pragma once
#include "..\\Directx11_2D_Engine_SOURCE\\hyScene.h"

namespace hy
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		virtual ~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
	};
}
