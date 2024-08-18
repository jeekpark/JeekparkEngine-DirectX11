#include "jkToolScene.h"
#include "jkObject.h"
#include "jkTile.h"
#include "jkTilemapRenderer.h"
#include "jkResources.h"
#include "jkCamera.h"
#include "jkRenderer.h"
#include "jkInput.h"
#include "jkCameraScript.h"
Vector2 jk::ToolScene::SelectedIndex = { 0.f, 0.f };

jk::ToolScene::ToolScene()
    : mGridSize(1.f, 1.f)
{
}

jk::ToolScene::~ToolScene()
{
}

void jk::ToolScene::Initialize()
{
    ///////// CAMERA /////////
    GameObject* camObj = object::Instantiate<GameObject>(enums::eLayerType::None);
    Camera* camComp = camObj->AddComponent<Camera>();
    CameraScript* camScript = camObj->AddComponent<CameraScript>();
    renderer::mainCamera = camComp;


    mGridSize = { 48.f, 48.f };
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile);
            TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
            tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
            tmr->SetSourceTileSize({ 16.f, 16.f });
            
            tmr->SetIndex({ 0.f, 0.f });
            tile->GetComponent<Transform>()->SetPosition({ 16.f * 3.f * i, 16.f * 3.f * j });
            tile->GetComponent<Transform>()->SetScale({ 3.f, 3.f });
        }
    }


    

    Scene::Initialize();
}

void jk::ToolScene::Update()
{
    Scene::Update();
}

void jk::ToolScene::LateUpdate()
{
    Scene::LateUpdate();
    if (Input::GetKeyDown(eKeyCode::LButton))
    {
        Vector2 pos = Input::GetMousePostion();
        
        if (pos.x < 0.f || pos.y < 0.f)
        {
            return;
        }   
        pos = renderer::mainCamera->ScreenToWorldPoint(pos);
        Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile);
        TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
        tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
        tmr->SetSourceTileSize({ 16.f, 16.f });
        tmr->SetIndex(SelectedIndex);
        tile->SetPositionInGrid(pos.x, pos.y, mGridSize);
        tile->GetComponent<Transform>()->SetScale({ 3.f, 3.f });

        mTiles.push_back(tile);
    }
    if (Input::GetKeyDown(eKeyCode::S))
    {
        Save();
    }
    if (Input::GetKeyDown(eKeyCode::L))
    {
        Load();
    }

}

void jk::ToolScene::Render(HDC hdc)
{
    Scene::Render(hdc);
    
    for (int i = -50; i < 50; ++i)
    {
        Vector2 pos = renderer::mainCamera->WorldToScreenPoint({ mGridSize.x * i, 0.f });
        MoveToEx(hdc, pos.x, 0, nullptr);
        LineTo(hdc, pos.x, 1080);
    }
    for (int j = -50; j < 50; ++j)
    {
        Vector2 pos = renderer::mainCamera->WorldToScreenPoint({ 0.f, mGridSize.y * j});
        MoveToEx(hdc, 0, pos.y, nullptr);
        LineTo(hdc, 1920, pos.y);
    }
}

void jk::ToolScene::OnEnter()
{
    Scene::OnEnter();
}

void jk::ToolScene::OnExit()
{
    Scene::OnExit();
}

void jk::ToolScene::Save()
{
    OPENFILENAME ofn = {};
    wchar_t szFilePath[MAX_PATH] = {};
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFilePath;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFilePath);
    ofn.lpstrFilter = L"Tile\0*.tile\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    if (GetSaveFileName(&ofn) == false)
    {
        return;
    }
    FILE* pFile = nullptr;
    _wfopen_s(&pFile, szFilePath, L"wb");
    if (pFile == nullptr)
    {
        return;
    }

    for (Tile* tile : mTiles)
    {
        TilemapRenderer* tmr = tile->GetComponent<TilemapRenderer>();
        Vector2 index = tmr->GetIndex();

        Transform* tr = tile->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();

        fwrite(&index, sizeof(Vector2), 1, pFile);
        fwrite(&pos, sizeof(Vector2), 1, pFile);
    }
    fclose(pFile);
}

void jk::ToolScene::Load()
{
    OPENFILENAME ofn = {};
    wchar_t szFilePath[MAX_PATH] = {};
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFilePath;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFilePath);
    ofn.lpstrFilter = L"Tile\0*.tile\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    if (GetSaveFileName(&ofn) == false)
    {
        return;
    }
    FILE* pFile = nullptr;
    _wfopen_s(&pFile, szFilePath, L"rb");
    if (pFile == nullptr)
    {
        return;
    }
    clearTiles();

    while (true)
    {
        Vector2 index;
        Vector2 pos;
        if (fread(&index, sizeof(Vector2), 1, pFile) == 0)
        {
            break;
        }
        if (fread(&pos, sizeof(Vector2), 1, pFile) == 0)
        {
            break;
        }
        int a = 0;


        Tile* tile = object::Instantiate<Tile>(enums::eLayerType::Tile);
        TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
        tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
        tmr->SetSourceTileSize({ 16.f, 16.f });
        tmr->SetIndex(index);
        tile->SetPositionInGrid(pos.x, pos.y, mGridSize);
        tile->GetComponent<Transform>()->SetScale({ 3.f, 3.f });

        mTiles.push_back(tile);
    }
}

void jk::ToolScene::clearTiles()
{
    for (Tile* tile : mTiles)
    {
        object::Destroy(tile);
    }
    mTiles.clear();
}


LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_LBUTTONDOWN:
    {
        POINT mousePos = {};
        GetCursorPos(&mousePos);
        ScreenToClient(hWnd, &mousePos);

        jk::math::Vector2 pos = { (float)mousePos.x, (float)mousePos.y };
        int idxX = (int)(pos.x / 16.f);
        int idxY = (int)(pos.y / 16.f);

        jk::ToolScene::SelectedIndex = { (float)idxX, (float)idxY };
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        jk::graphics::Texture* tex
            = jk::Resources::Find<jk::graphics::Texture>(L"SpringFloor");

        TransparentBlt(hdc,
            0, 0,
            tex->GetWidth(),
            tex->GetHeight(),
            tex->GetHdc(),
            0, 0,
            tex->GetWidth(),
            tex->GetHeight(),
            RGB(255, 0, 255));

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
