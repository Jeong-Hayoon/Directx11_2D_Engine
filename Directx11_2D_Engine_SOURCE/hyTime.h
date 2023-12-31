#pragma once
#include "CommonInclude.h"
#include "Directx11_2D_Engine.h"

namespace hy
{
	class Time
	{
	public:
		static __forceinline float DeltaTime() { return mDeltaTime; }

		static void Initialize();
		static void Update();
		static void Render();

	private:
		static LARGE_INTEGER	mCpuFrequency;
		static LARGE_INTEGER   mPrevFrequency;
		static LARGE_INTEGER	mCurFrequency;

		static float			mDeltaTime;
		static float			mOneSecond;
	};
}

