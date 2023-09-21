#include "hyBullet.h"
#include "hyResources.h"
#include "hyMeshRenderer.h"
#include "hySceneManager.h"
#include "hyTime.h"

namespace hy
{


	Bullet::Bullet()
	{

	}
	Bullet::~Bullet()
	{
	}
	void Bullet::Initialize()
	{
		GameObject::Initialize();
	}
	void Bullet::Update()
	{
		Transform* tr = GetComponent<Transform>();
		Vector3 pos = tr->GetPosition();
		pos.y += 1.f * Time::DeltaTime();
		tr->SetPosition(pos);

		GameObject::Update();
	}
	void Bullet::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Bullet::Render()
	{
		GameObject::Render();
	}
}