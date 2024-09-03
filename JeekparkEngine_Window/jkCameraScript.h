#pragma once
#include "..\jeekparkEngine_SOURCE\\jkScript.h"
#include "..\jeekparkEngine_SOURCE\\jkTransform.h"

namespace jk
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};
}