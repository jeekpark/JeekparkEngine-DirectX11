#pragma once
#include "jkComponent.h"

namespace jk
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetMass(float mass) { mMass = mass; }
		void AddForce(Vector2 force) { mForce = force; }
        void SetGround(bool ground) { mbGround = ground; }
        void SetVecloty(Vector2 velocity) { mVelocity = velocity; }
        Vector2 GetVelocity() { return mVelocity; }
        void SetFriction(float friction) { mFriction = friction; }


	private:
        bool mbGround;
		float mMass;
		float mFriction;

		Vector2 mForce;
		Vector2 mAccelation;
		Vector2 mVelocity;
        Vector2 mLimitedVelocity;
		Vector2 mGravity;
	};
}