#pragma once
#include "jkUIBase.h"
#include "jkTexture.h"

namespace jk
{
	class UIButton : public UIBase
	{
	public:
		UIButton();
		~UIButton();

		void OnInit() override;
		void OnActive() override;
		void OnInActive() override;
		void OnUpdate() override;
		void OnLateUpdate() override;
		void OnRender() override;
		void OnClear() override;

		void ButtonClick();

	private:
		graphics::Texture* mTexture;
		Event mOnClick;
	};
}