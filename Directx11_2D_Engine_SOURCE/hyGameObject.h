#pragma once
#include "hyEntity.h"
#include "hyComponent.h"
#include "hyScript.h"


namespace hy
{
	class GameObject : public Entity
	{
	public:
		enum eState
		{
			Active,
			Paused,
			Dead,
		};

		GameObject();
		virtual ~GameObject();

		//void AddComponent(Component* component);

		template <typename T>
		T* AddComponent()
		{
			T* component = new T();
			Component* comp = dynamic_cast<Component*>(component);
			if (comp)
			{
				int myOrder = comp->GetUpdateOrder();
				mComponents[myOrder] = comp;
				mComponents[myOrder]->mOwner = this;
			}

			Script* script = dynamic_cast<Script*>(component);
			if (script != nullptr)
			{
				mScripts.push_back(script);
				script->SetOwner(this);
			}

			return component;
		}

		/*template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			mComponents.push_back(comp);
			comp->SetOwner(this);

			return comp;
		}*/

		template <typename T>
		T* GetComponent()
		{
			T* component;
			for (auto c : mComponents)
			{
				component = dynamic_cast<T*>(c);

				if (component != nullptr)
					return component;
			}

			return nullptr;
		}

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		void SetLayerType(LAYERTYPE LayerType) { mLayerType = LayerType; }
		LAYERTYPE GetLayerType() { return mLayerType; }

	private:
		eState mState;
		std::vector<Component*> mComponents;
		LAYERTYPE mLayerType;	
		std::vector<Script*> mScripts;
	};
}


