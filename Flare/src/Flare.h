#pragma once

// For use by Flare applications!
#include "Flare/Core/Core.h"

#include "Flare/Core/Application.h"
#include "Flare/Core/Layer.h"
#include "Flare/Core/TimeStep.h"

#include "Flare/Logging/LogService.h"
#include "Flare/Logging/LogEmitter.h"

#include "Flare/UserInput/Input.h"
#include "Flare/UserInput/InputCodes.h"

#include "Flare/Events/Event.h"
#include "Flare/Events/KeyEvent.h"
#include "Flare/Events/EventDispatcher.h"

#include "Flare/Resource/ResourceManager.h"
#include "Flare/Resource/FileAsset.h"

// ----------  Rendering  ----------
#include "Flare/Rendering/Renderer.h"
#include "Flare/Rendering/Rendering.h"
#include "Flare/Rendering/RenderingController.h"

#include "Flare/Rendering/Buffer.h"
#include "Flare/Rendering/Shader.h"
#include "Flare/Rendering/VertexArray.h"

#include "Flare/Rendering/OrthographicCamera.h"
#include "Flare/Rendering/OrthographicCameraController.h"
// ---------------------------------

#include "Flare/ImGui/ImGuiLayer.h"
