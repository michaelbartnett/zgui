#include "imgui.h"

#include "ImGuizmo.h"

#include "imgui_internal.h"

#ifndef ZGUI_API
#define ZGUI_API
#endif

//--------------------------------------------------------------------------------------------------
//
// ImGuizmo
//
//--------------------------------------------------------------------------------------------------
extern "C"
{
    void zguiGizmo_Init()
    {
        IMGUIZMO_NAMESPACE::Init();
    }

    void zguiGizmo_Deinit()
    {
        IMGUIZMO_NAMESPACE::Deinit();
    }

    IMGUI_API ImGuizmo::Context* zguiGizmo_CreateContext()
    {
        return IMGUIZMO_NAMESPACE::CreateContext();
    }

    IMGUI_API void zguiGizmo_DestroyContext(ImGuizmo::Context* context)
    {
        IMGUIZMO_NAMESPACE::DestroyContext(context);
    }

    IMGUI_API void zguiGizmo_SetCurrentContext(ImGuizmo::Context* context)
    {
        IMGUIZMO_NAMESPACE::SetCurrentContext(context);
    }

    IMGUI_API ImGuizmo::Context* zguiGizmo_GetCurrentContext()
    {
        return IMGUIZMO_NAMESPACE::GetCurrentContext();
    }

    ZGUI_API void zguiGizmo_SetDrawlist(ImDrawList *drawlist)
    {
        IMGUIZMO_NAMESPACE::SetDrawlist(drawlist);
    }

    ZGUI_API void zguiGizmo_BeginFrame()
    {
        IMGUIZMO_NAMESPACE::BeginFrame();
    }

    ZGUI_API void zguiGizmo_SetImGuiContext(ImGuiContext *ctx)
    {
        IMGUIZMO_NAMESPACE::SetImGuiContext(ctx);
    }

    ZGUI_API bool zguiGizmo_IsOver()
    {
        return IMGUIZMO_NAMESPACE::IsOver();
    }

    ZGUI_API bool zguiGizmo_IsUsing()
    {
        return IMGUIZMO_NAMESPACE::IsUsing();
    }

    ZGUI_API bool zguiGizmo_IsUsingAny()
    {
        return IMGUIZMO_NAMESPACE::IsUsingAny();
    }

    ZGUI_API void zguiGizmo_Enable(bool enable)
    {
        IMGUIZMO_NAMESPACE::Enable(enable);
    }

    ZGUI_API void zguiGizmo_DecomposeMatrixToComponents(
        const float *matrix,
        float *translation,
        float *rotation,
        float *scale)
    {
        IMGUIZMO_NAMESPACE::DecomposeMatrixToComponents(matrix, translation, rotation, scale);
    }

    ZGUI_API void zguiGizmo_RecomposeMatrixFromComponents(
        const float *translation,
        const float *rotation,
        const float *scale,
        float *matrix)
    {
        IMGUIZMO_NAMESPACE::RecomposeMatrixFromComponents(translation, rotation, scale, matrix);
    }

    ZGUI_API void zguiGizmo_SetRect(float x, float y, float width, float height)
    {
        IMGUIZMO_NAMESPACE::SetRect(x, y, width, height);
    }

    ZGUI_API void zguiGizmo_SetOrthographic(bool isOrthographic)
    {
        IMGUIZMO_NAMESPACE::SetOrthographic(isOrthographic);
    }

    ZGUI_API void zguiGizmo_DrawCubes(const float *view, const float *projection, const float *matrices, int matrixCount)
    {
        IMGUIZMO_NAMESPACE::DrawCubes(view, projection, matrices, matrixCount);
    }

    ZGUI_API void zguiGizmo_DrawGrid(
        const float *view,
        const float *projection,
        const float *matrix,
        const float gridSize)
    {
        IMGUIZMO_NAMESPACE::DrawGrid(view, projection, matrix, gridSize);
    }

    ZGUI_API bool zguiGizmo_Manipulate(
        const float *view,
        const float *projection,
        IMGUIZMO_NAMESPACE::OPERATION operation,
        IMGUIZMO_NAMESPACE::MODE mode,
        float *matrix,
        float *deltaMatrix = NULL,
        const float *snap = NULL,
        const float *localBounds = NULL,
        const float *boundsSnap = NULL)
    {
        return IMGUIZMO_NAMESPACE::Manipulate(view, projection, operation, mode, matrix, deltaMatrix, snap, localBounds, boundsSnap);
    }

    //
    // Please note that this cubeview is patented by Autodesk : https://patents.google.com/patent/US7782319B2/en
    // It seems to be a defensive patent in the US. I don't think it will bring troubles using it as
    // other software are using the same mechanics. But just in case, you are now warned!
    //
    ZGUI_API void zguiGizmo_ViewManipulate(
        float *view,
        float length,
        const float position[2],
        const float size[2],
        ImU32 backgroundColor)
    {
        const ImVec2 p(position[0], position[1]);
        const ImVec2 s(size[0], size[1]);
        IMGUIZMO_NAMESPACE::ViewManipulate(view, length, p, s, backgroundColor);
    }
    // use this version if you did not call Manipulate before and you are just using ViewManipulate
    ZGUI_API void zguiGizmo_ViewManipulateIndependent(
        float *view,
        const float *projection,
        IMGUIZMO_NAMESPACE::OPERATION operation,
        IMGUIZMO_NAMESPACE::MODE mode,
        float *matrix,
        float length,
        const float position[2],
        const float size[2],
        ImU32 backgroundColor)
    {
        const ImVec2 p(position[0], position[1]);
        const ImVec2 s(size[0], size[1]);
        IMGUIZMO_NAMESPACE::ViewManipulate(view, projection, operation, mode, matrix, length, p, s, backgroundColor);
    }

    ZGUI_API void zguiGizmo_SetID(int id)
    {
        IMGUIZMO_NAMESPACE::SetID(id);
    }

    ZGUI_API bool zguiGizmo_IsOverOperation(IMGUIZMO_NAMESPACE::OPERATION op)
    {
        return IMGUIZMO_NAMESPACE::IsOver(op);
    }

    ZGUI_API void zguiGizmo_AllowAxisFlip(bool value)
    {
        IMGUIZMO_NAMESPACE::AllowAxisFlip(value);
    }

    ZGUI_API void zguiGizmo_SetAxisLimit(float value)
    {
        IMGUIZMO_NAMESPACE::SetAxisLimit(value);
    }

    ZGUI_API void zguiGizmo_SetPlaneLimit(float value)
    {
        IMGUIZMO_NAMESPACE::SetPlaneLimit(value);
    }

    ZGUI_API IMGUIZMO_NAMESPACE::Style *zguiGizmo_GetStyle()
    {
        return &IMGUIZMO_NAMESPACE::GetStyle();
    }

} /* extern "C" */