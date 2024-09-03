#include "jkCamera.h"

#include "jkGameObject.h"
#include "jkTransform.h"
#include "jkApplication.h"

extern jk::Application app;

namespace jk
{
    Camera::Camera()
        : Component(enums::eComponentType::Camera)
        , mDistance(Vector2::Zero)
        , mResolution(Vector2::Zero)
        , mLookPosition(Vector2::Zero)
        , mTarget(nullptr)
    {

    }
    Camera::~Camera()
    {
    }
    void Camera::Initialize()
    {
        mResolution.x = CAST_FLOAT(app.GetClientWidth());
        mResolution.y = CAST_FLOAT(app.GetClientHeight());
    }
    void Camera::Update()
    {
        if (mTarget)
        {
            Transform* tr = mTarget->GetComponent<Transform>();
            mLookPosition = tr->GetPosition();
        }
        else
        {
            Transform* cameraTr = GetOwner()->GetComponent<Transform>();
            mLookPosition = cameraTr->GetPosition();
        }
        mDistance = mLookPosition - (mResolution / 2.f);
    }
    void Camera::LateUpdate()
    {
        
    }
    void Camera::Render()
    {
    }
}
