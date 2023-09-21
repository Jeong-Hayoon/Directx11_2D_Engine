#pragma once
#include "..\\Directx11_2D_Engine_SOURCE\\hyScript.h"

namespace hy
{

	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		virtual ~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;
	};

}
