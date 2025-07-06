#include <thread>
#include "libraries/overlay/overlay.h"
#include "logger.h"

int main() {

	static MSG msg = { 0 };
	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		if (!overlay::scale())
			break;

		auto shown = GetKeyState(VK_INSERT);
		overlay::click_through(!shown);

		window::new_frame();

		if (shown) {
			
		}

		window::draw();
	}

	window::cleanup();

	return 0;
}
