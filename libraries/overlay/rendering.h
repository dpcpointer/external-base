#pragma once

#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_dx11.h>
#include <imgui_impl_win32.h>

namespace rendering {
	inline void render_Box(ImDrawList* draw_list, ImVec2& top_left, ImVec2& bottom_right, ImColor color, float size, ImColor outline_color = ImColor(1, 1, 1, 255)) {
		if (!draw_list) {
			draw_list = ImGui::GetBackgroundDrawList();
				if (!draw_list)
					return;
		}

		float outline_thickness = size * 0.5f;

		draw_list->AddRect(top_left, bottom_right, color, 0.0f, ImDrawFlags_RoundCornersNone, size);
		draw_list->AddRect({ top_left.x - outline_thickness, top_left.y - outline_thickness },
			{ bottom_right.x + outline_thickness, bottom_right.y + outline_thickness },
			outline_color, 0.0f, ImDrawFlags_RoundCornersNone, outline_thickness);
	}
}