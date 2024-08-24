#include "jkRigidbody.h"

#include "jkTime.h"
#include "jkTransform.h"
#include "jkGameObject.h"

namespace jk
{
	Rigidbody::Rigidbody()
		: Component(enums::eComponentType::Rigidbody)
        , mbGround(false)
		, mMass(1.0f)
		, mFriction(10.0f)
		, mForce(Vector2::Zero)
		, mVelocity(Vector2::Zero)
        , mLimitedVelocity(Vector2(2000.f, 10000.f))
		, mGravity(Vector2(0.f, 800.f))
		, mAccelation(Vector2::Zero)
	{

	}

	Rigidbody::~Rigidbody()
	{
	}

	void Rigidbody::Initialize()
	{
	}

	void Rigidbody::Update()
	{
		mAccelation = mForce / mMass;
		mVelocity += mAccelation * Time::DeltaTime();

		if (mbGround)
		{
			Vector2 gravity = mGravity;
			gravity.normalize();
			float dot = Vector2::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
            mVelocity += mGravity * Time::DeltaTime();
		}

		Vector2 gravity = mGravity;
		gravity.normalize();
		float dot = Vector2::Dot(mVelocity, gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimitedVelocity.y < gravity.length())
		{
			gravity.normalize();
			gravity *= mLimitedVelocity.y;
		}

		if (mLimitedVelocity.x < sideVelocity.length())
		{
			sideVelocity.normalize();
			sideVelocity *= mLimitedVelocity.x;
		}
		mVelocity = gravity + sideVelocity;

		if (!(mVelocity == Vector2::Zero))
		{
			Vector2 friction = -mVelocity;
			friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();
			if (mVelocity.length() <= friction.length())
			{
				mVelocity = Vector2::Zero;
			}
			else
			{
				mVelocity += friction;
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = pos + mVelocity * Time::DeltaTime();
		tr->SetPosition(pos);

		mForce.clear();
	}

	void Rigidbody::LateUpdate()
	{
	}

	void Rigidbody::Render(HDC hdc)
	{
	}

}