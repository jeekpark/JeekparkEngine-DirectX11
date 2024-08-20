#pragma once
#include "jkEntity.h"

namespace jk
{
	using namespace enums;
	class UIBase : public Entity
	{
	public:
		UIBase();
		~UIBase();

		void Initialize();
		void Active();
		void InActive();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnClear();

		eUIType GetUIType() { return mUIType; }
		void SetFullScreen(bool enable) { mbFullScreen = enable; }
		bool IsFullScreen() { return mbFullScreen; }

	private:
		eUIType mUIType;
		bool mbFullScreen;
		bool mbEnabled;
	};
}